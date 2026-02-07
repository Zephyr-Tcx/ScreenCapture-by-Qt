#include "screencapturer.h"
#include "ui_screencapturer.h"

#include <QApplication>
#include <QClipboard>
#include <QDateTime>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QDir>
#include <QFileDialog>
#include <QFileInfo>
#include <QGuiApplication>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>
#include <QScreen>
#include <QStandardPaths>
#include <QStyle>
#include <QTime>
#include <QVBoxLayout>
#include <QWindow>

// 构造函数
ScreenCapturer::ScreenCapturer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ScreenCapturer)
    , m_isCapturing(false)
    , m_captureCount(0)
    , m_monitorIndex(0)
    , m_imageFormat("PNG")
    , m_imageQuality(100)
{
    ui->setupUi(this);
    
    // 初始化设置
    m_settings = new QSettings("YourCompany", "ScreenCaptureTool", this);
    
    // 初始化定时器
    m_captureTimer = new QTimer(this);
    m_updateTimer = new QTimer(this);
    
    // 初始化UI
    initializeUI();
    
    // 初始化连接
    initializeConnections();
    
    // 初始化系统托盘
    initializeTrayIcon();
    
    // 加载设置
    loadSettings();
    
    // 更新显示器信息
    updateScreensInfo();
    
    // 启动更新定时器（每秒更新一次）
    m_updateTimer->start(1000);
    
    // 更新状态
    updateStatus("就绪");
}

// 析构函数
ScreenCapturer::~ScreenCapturer()
{
    saveSettings();
    delete ui;
}

// 初始化UI
void ScreenCapturer::initializeUI()
{
    // 设置窗口属性
    setWindowTitle("屏幕截图工具 v1.0");
    setMinimumSize(600, 500);
    
    // 设置图标
    setWindowIcon(QIcon(":/icons/camera.png"));
    
    // 初始化控件状态
    ui->stopButton->setEnabled(false);
    ui->previewLabel->setScaledContents(true);
    ui->previewLabel->setMinimumSize(200, 150);
    ui->previewLabel->setFrameShape(QFrame::Box);
    ui->previewLabel->setAlignment(Qt::AlignCenter);
    
    // 设置截图间隔范围
    ui->intervalSpin->setRange(MIN_INTERVAL, MAX_INTERVAL);
    ui->intervalSpin->setValue(DEFAULT_INTERVAL);
    ui->intervalSpin->setSuffix(" 分钟");
    
    // 设置图片质量范围
    ui->qualitySpin->setRange(1, 100);
    ui->qualitySpin->setValue(m_imageQuality);
    ui->qualitySpin->setSuffix("%");
    
    // 设置图片格式选项
    ui->formatCombo->addItem("PNG (*.png)", "PNG");
    ui->formatCombo->addItem("JPEG (*.jpg)", "JPEG");
    ui->formatCombo->addItem("BMP (*.bmp)", "BMP");
    
    // 设置默认输出目录
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    m_outputDirectory = desktopPath + "/屏幕截图";
    ui->directoryEdit->setText(m_outputDirectory);
    
    // 确保目录存在
    ensureDirectoryExists(m_outputDirectory);
}

// 初始化信号槽连接
void ScreenCapturer::initializeConnections()
{
    // 按钮点击事件
    connect(ui->startButton, &QPushButton::clicked, this, &ScreenCapturer::onStartButtonClicked);
    connect(ui->stopButton, &QPushButton::clicked, this, &ScreenCapturer::onStopButtonClicked);
    connect(ui->captureNowButton, &QPushButton::clicked, this, &ScreenCapturer::onCaptureNowButtonClicked);
    connect(ui->browseButton, &QPushButton::clicked, this, &ScreenCapturer::onBrowseButtonClicked);
    connect(ui->aboutButton, &QPushButton::clicked, this, &ScreenCapturer::showAboutDialog);
    
    // 设置变更事件
    connect(ui->monitorCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ScreenCapturer::onMonitorComboChanged);
    connect(ui->intervalSpin, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &ScreenCapturer::onIntervalChanged);
    connect(ui->formatCombo, &QComboBox::currentTextChanged,
            this, &ScreenCapturer::onFormatComboChanged);
    
    // 定时器事件
    connect(m_captureTimer, &QTimer::timeout, this, &ScreenCapturer::onCaptureTimerTimeout);
    connect(m_updateTimer, &QTimer::timeout, this, &ScreenCapturer::onUpdateTimerTimeout);
}

// 初始化系统托盘
void ScreenCapturer::initializeTrayIcon()
{
    // 创建系统托盘图标
    m_trayIcon = new QSystemTrayIcon(this);
    m_trayIcon->setIcon(QIcon(":/icons/camera.png"));
    m_trayIcon->setToolTip("屏幕截图工具");
    
    // 创建托盘菜单
    m_trayMenu = new QMenu(this);
    
    QAction *showAction = m_trayMenu->addAction("显示主窗口");
    QAction *hideAction = m_trayMenu->addAction("隐藏主窗口");
    m_trayMenu->addSeparator();
    
    QAction *captureAction = m_trayMenu->addAction("立即截图");
    QAction *startAction = m_trayMenu->addAction("开始定时截图");
    QAction *stopAction = m_trayMenu->addAction("停止截图");
    m_trayMenu->addSeparator();
    
    QAction *quitAction = m_trayMenu->addAction("退出");
    
    // 连接菜单动作
    connect(showAction, &QAction::triggered, this, &QWidget::showNormal);
    connect(hideAction, &QAction::triggered, this, &QWidget::hide);
    connect(captureAction, &QAction::triggered, this, &ScreenCapturer::captureNow);
    connect(startAction, &QAction::triggered, this, &ScreenCapturer::startCapture);
    connect(stopAction, &QAction::triggered, this, &ScreenCapturer::stopCapture);
    connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);
    
    // 设置托盘菜单
    m_trayIcon->setContextMenu(m_trayMenu);
    
    // 连接托盘图标激活事件
    connect(m_trayIcon, &QSystemTrayIcon::activated,
            this, &ScreenCapturer::onTrayIconActivated);
    
    // 显示托盘图标
    m_trayIcon->show();
}

// 加载设置
void ScreenCapturer::loadSettings()
{
    m_settings->beginGroup("MainWindow");
    restoreGeometry(m_settings->value("geometry").toByteArray());
    m_settings->endGroup();
    
    m_settings->beginGroup("CaptureSettings");
    m_outputDirectory = m_settings->value("outputDirectory", m_outputDirectory).toString();
    m_monitorIndex = m_settings->value("monitorIndex", 0).toInt();
    int interval = m_settings->value("interval", DEFAULT_INTERVAL).toInt();
    m_imageFormat = m_settings->value("format", "PNG").toString();
    m_imageQuality = m_settings->value("quality", 100).toInt();
    
    // 应用设置到UI
    ui->directoryEdit->setText(m_outputDirectory);
    ui->intervalSpin->setValue(interval);
    ui->qualitySpin->setValue(m_imageQuality);
    
    // 设置格式
    for (int i = 0; i < ui->formatCombo->count(); ++i) {
        if (ui->formatCombo->itemData(i).toString() == m_imageFormat) {
            ui->formatCombo->setCurrentIndex(i);
            break;
        }
    }
    
    m_settings->endGroup();
    
    // 确保目录存在
    ensureDirectoryExists(m_outputDirectory);
}

// 保存设置
void ScreenCapturer::saveSettings()
{
    m_settings->beginGroup("MainWindow");
    m_settings->setValue("geometry", saveGeometry());
    m_settings->endGroup();
    
    m_settings->beginGroup("CaptureSettings");
    m_settings->setValue("outputDirectory", m_outputDirectory);
    m_settings->setValue("monitorIndex", m_monitorIndex);
    m_settings->setValue("interval", ui->intervalSpin->value());
    m_settings->setValue("format", m_imageFormat);
    m_settings->setValue("quality", m_imageQuality);
    m_settings->endGroup();
    
    m_settings->sync();
}

// 更新显示器信息
void ScreenCapturer::updateScreensInfo()
{
    m_monitors.clear();
    ui->monitorCombo->clear();
    
    QList<QScreen*> screens = QGuiApplication::screens();
    
    // 添加"所有显示器"选项
    ui->monitorCombo->addItem("所有显示器", 0);
    
    for (int i = 0; i < screens.size(); ++i) {
        QScreen *screen = screens[i];
        MonitorInfo info;
        info.index = i + 1;
        info.geometry = screen->geometry();
        info.isPrimary = (screen == QGuiApplication::primaryScreen());
        
        if (info.isPrimary) {
            info.name = QString("主显示器 %1 (%2x%3)")
                       .arg(i + 1)
                       .arg(info.geometry.width())
                       .arg(info.geometry.height());
        } else {
            info.name = QString("显示器 %1 (%2x%3)")
                       .arg(i + 1)
                       .arg(info.geometry.width())
                       .arg(info.geometry.height());
        }
        
        m_monitors.append(info);
        ui->monitorCombo->addItem(info.name, info.index);
    }
    
    // 恢复上次选择的显示器
    if (m_monitorIndex >= 0 && m_monitorIndex < ui->monitorCombo->count()) {
        ui->monitorCombo->setCurrentIndex(m_monitorIndex);
    }
}

// 捕获屏幕
QPixmap ScreenCapturer::captureScreen(int monitorIndex)
{
    if (monitorIndex == 0) {
        // 捕获所有显示器
        QList<QScreen*> screens = QGuiApplication::screens();
        if (screens.isEmpty()) {
            return QPixmap();
        }
        
        // 计算所有显示器的总区域
        QRect totalRect;
        for (QScreen *screen : screens) {
            totalRect = totalRect.united(screen->geometry());
        }
        
        // 创建总截图
        QScreen *primaryScreen = QGuiApplication::primaryScreen();
        QPixmap screenshot = primaryScreen->grabWindow(0,
                                                      totalRect.x(),
                                                      totalRect.y(),
                                                      totalRect.width(),
                                                      totalRect.height());
        
        // 绘制显示器边框
        if (ui->showBordersCheck->isChecked()) {
            QPainter painter(&screenshot);
            painter.setPen(QPen(Qt::red, 3));
            
            for (const MonitorInfo &monitor : m_monitors) {
                QRect screenRect = monitor.geometry;
                screenRect.moveTo(screenRect.x() - totalRect.x(),
                                 screenRect.y() - totalRect.y());
                painter.drawRect(screenRect);
                
                // 显示显示器编号
                painter.drawText(screenRect.topLeft() + QPoint(10, 30),
                                QString("显示器 %1").arg(monitor.index));
            }
        }
        
        return screenshot;
    } else {
        // 捕获指定显示器
        int screenIndex = monitorIndex - 1;
        QList<QScreen*> screens = QGuiApplication::screens();
        
        if (screenIndex >= 0 && screenIndex < screens.size()) {
            QScreen *screen = screens[screenIndex];
            QPixmap screenshot = screen->grabWindow(0);
            
            // 绘制显示器边框
            if (ui->showBordersCheck->isChecked()) {
                QPainter painter(&screenshot);
                painter.setPen(QPen(Qt::red, 3));
                painter.drawRect(0, 0, screenshot.width() - 1, screenshot.height() - 1);
                
                // 显示显示器编号
                painter.drawText(10, 30, QString("显示器 %1").arg(monitorIndex));
            }
            
            return screenshot;
        }
    }
    
    return QPixmap();
}

// 保存截图
bool ScreenCapturer::saveScreenshot(const QPixmap &screenshot, const QString &filename)
{
    if (screenshot.isNull()) {
        return false;
    }
    
    QString fullPath = m_outputDirectory + "/" + filename;
    
    // 保存图片
    bool success = screenshot.save(fullPath, m_imageFormat.toUtf8().constData(), m_imageQuality);
    
    // 如果启用了复制到剪贴板，复制图片
    if (success && ui->clipboardCheck->isChecked()) {
        QApplication::clipboard()->setPixmap(screenshot);
    }
    
    // 如果启用了预览，更新预览
    if (success && ui->enablePreviewCheck->isChecked()) {
        updateScreenshotPreview(screenshot);
    }
    
    return success;
}

// 生成文件名
QString ScreenCapturer::generateFilename() const
{
    QDateTime now = QDateTime::currentDateTime();
    QString timestamp = now.toString("yyyyMMdd_hhmmss");
    
    if (m_monitorIndex == 0) {
        return QString("screenshot_%1.%2")
               .arg(timestamp)
               .arg(getImageFormatExtension());
    } else {
        return QString("screen%1_%2.%3")
               .arg(m_monitorIndex)
               .arg(timestamp)
               .arg(getImageFormatExtension());
    }
}

// 获取图片格式扩展名
QString ScreenCapturer::getImageFormatExtension() const
{
    if (m_imageFormat == "PNG") return "png";
    if (m_imageFormat == "JPEG") return "jpg";
    if (m_imageFormat == "BMP") return "bmp";
    return "png";
}

// 确保目录存在
bool ScreenCapturer::ensureDirectoryExists(const QString &path)
{
    QDir dir(path);
    if (!dir.exists()) {
        return dir.mkpath(".");
    }
    return true;
}

// 显示通知
void ScreenCapturer::showNotification(const QString &title, const QString &message)
{
    if (ui->notificationsCheck->isChecked() && m_trayIcon) {
        m_trayIcon->showMessage(title, message,
                               QSystemTrayIcon::Information,
                               3000);
    }
}

// 更新状态
void ScreenCapturer::updateStatus(const QString &message)
{
    ui->statusLabel->setText("状态: " + message);
    
    // 同时更新托盘提示
    if (m_trayIcon) {
        m_trayIcon->setToolTip("屏幕截图工具\n" + message);
    }
}

// 更新计数器
void ScreenCapturer::updateCounter()
{
    ui->counterLabel->setText(QString("已截图: %1 张").arg(m_captureCount));
}

// 更新截图预览
void ScreenCapturer::updateScreenshotPreview(const QPixmap &pixmap)
{
    if (!pixmap.isNull()) {
        // 缩放预览图以适应标签大小
        QSize labelSize = ui->previewLabel->size();
        QPixmap scaledPixmap = pixmap.scaled(labelSize,
                                            Qt::KeepAspectRatio,
                                            Qt::SmoothTransformation);
        ui->previewLabel->setPixmap(scaledPixmap);
    }
}

// 验证设置
bool ScreenCapturer::validateSettings()
{
    if (!isOutputDirectoryValid()) {
        QMessageBox::warning(this, "警告", "输出目录无效或不可写！");
        return false;
    }
    
    if (ui->intervalSpin->value() < MIN_INTERVAL || ui->intervalSpin->value() > MAX_INTERVAL) {
        QMessageBox::warning(this, "警告",
                            QString("截图间隔必须在%1-%2分钟之间！")
                            .arg(MIN_INTERVAL).arg(MAX_INTERVAL));
        return false;
    }
    
    return true;
}

// 检查输出目录
bool ScreenCapturer::isOutputDirectoryValid() const
{
    QDir dir(m_outputDirectory);
    if (!dir.exists()) {
        // 尝试创建目录
        return dir.mkpath(".");
    }
    
    // 检查是否可写
    QFileInfo info(m_outputDirectory);
    return info.isWritable();
}

// ==================== 事件处理 ====================

void ScreenCapturer::closeEvent(QCloseEvent *event)
{
    if (ui->minimizeToTrayCheck->isChecked() && m_trayIcon->isVisible()) {
        hide();
        event->ignore();
    } else {
        // 停止截图
        if (m_isCapturing) {
            stopCapture();
        }
        event->accept();
    }
}

void ScreenCapturer::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::WindowStateChange) {
        if (isMinimized() && ui->minimizeToTrayCheck->isChecked()) {
            hide();
        }
    }
    QMainWindow::changeEvent(event);
}

// ==================== 槽函数 ====================

void ScreenCapturer::onStartButtonClicked()
{
    if (!validateSettings()) {
        return;
    }
    
    startCapture();
}

void ScreenCapturer::onStopButtonClicked()
{
    stopCapture();
}

void ScreenCapturer::onCaptureNowButtonClicked()
{
    captureNow();
}

void ScreenCapturer::onBrowseButtonClicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,
                                                   "选择保存目录",
                                                   m_outputDirectory);
    if (!dir.isEmpty()) {
        m_outputDirectory = dir;
        ui->directoryEdit->setText(dir);
        ensureDirectoryExists(dir);
        saveSettings();
    }
}

void ScreenCapturer::onMonitorComboChanged(int index)
{
    m_monitorIndex = ui->monitorCombo->itemData(index).toInt();
    saveSettings();
}

void ScreenCapturer::onIntervalChanged(int value)
{
    if (m_isCapturing) {
        // 如果正在截图，重新启动定时器
        m_captureTimer->stop();
        m_captureTimer->start(value * 60 * 1000);
    }
    saveSettings();
}

void ScreenCapturer::onFormatComboChanged(const QString &format)
{
    QString selectedFormat = ui->formatCombo->currentData().toString();
    if (!selectedFormat.isEmpty()) {
        m_imageFormat = selectedFormat;
        saveSettings();
    }
}

void ScreenCapturer::onCaptureTimerTimeout()
{
    captureNow();
}

void ScreenCapturer::onUpdateTimerTimeout()
{
    QDateTime now = QDateTime::currentDateTime();
    ui->timeLabel->setText(now.toString("yyyy-MM-dd hh:mm:ss"));
    
    if (m_isCapturing && m_captureTimer->isActive()) {
        int remainingSeconds = m_captureTimer->remainingTime() / 1000;
        int minutes = remainingSeconds / 60;
        int seconds = remainingSeconds % 60;
        
        ui->nextCaptureLabel->setText(
            QString("下次截图: %1分%2秒后")
            .arg(minutes, 2, 10, QChar('0'))
            .arg(seconds, 2, 10, QChar('0'))
        );
    }
}

void ScreenCapturer::onTrayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::DoubleClick) {
        if (isHidden()) {
            showNormal();
            activateWindow();
        } else {
            hide();
        }
    }
}

void ScreenCapturer::onTrayMenuActionTriggered(QAction *action)
{
    // 已经在initializeTrayIcon中连接了
    Q_UNUSED(action);
}

// ==================== 公共方法 ====================

void ScreenCapturer::setCaptureInterval(int minutes)
{
    if (minutes >= MIN_INTERVAL && minutes <= MAX_INTERVAL) {
        ui->intervalSpin->setValue(minutes);
        saveSettings();
    }
}

void ScreenCapturer::setOutputDirectory(const QString &path)
{
    if (!path.isEmpty() && QDir(path).exists()) {
        m_outputDirectory = path;
        ui->directoryEdit->setText(path);
        ensureDirectoryExists(path);
        saveSettings();
    }
}

void ScreenCapturer::setMonitorIndex(int index)
{
    if (index >= 0 && index < ui->monitorCombo->count()) {
        m_monitorIndex = index;
        ui->monitorCombo->setCurrentIndex(index);
        saveSettings();
    }
}

void ScreenCapturer::startCapture()
{
    if (!validateSettings()) {
        return;
    }
    
    int intervalMinutes = ui->intervalSpin->value();
    int intervalMs = intervalMinutes * 60 * 1000;
    
    m_captureTimer->start(intervalMs);
    m_isCapturing = true;
    m_captureCount = 0;
    
    // 更新UI状态
    ui->startButton->setEnabled(false);
    ui->stopButton->setEnabled(true);
    ui->intervalSpin->setEnabled(false);
    ui->monitorCombo->setEnabled(false);
    
    updateStatus("正在定时截图中...");
    updateCounter();
    
    // 立即截取一张（如果启用）
    if (ui->immediateCheck->isChecked()) {
        QTimer::singleShot(100, this, &ScreenCapturer::captureNow);
    }
    
    showNotification("开始截图", QString("已开始定时截图，每 %1 分钟截图一次").arg(intervalMinutes));
}

void ScreenCapturer::stopCapture()
{
    m_captureTimer->stop();
    m_isCapturing = false;
    
    // 更新UI状态
    ui->startButton->setEnabled(true);
    ui->stopButton->setEnabled(false);
    ui->intervalSpin->setEnabled(true);
    ui->monitorCombo->setEnabled(true);
    
    updateStatus("已停止截图");
    ui->nextCaptureLabel->setText("下次截图: --");
    
    showNotification("停止截图", "定时截图已停止");
}

void ScreenCapturer::captureNow()
{
    // 执行截图
    QPixmap screenshot = captureScreen(m_monitorIndex);
    
    if (!screenshot.isNull()) {
        QString filename = generateFilename();
        
        if (saveScreenshot(screenshot, filename)) {
            m_captureCount++;
            updateCounter();
            
            QString fullPath = m_outputDirectory + "/" + filename;
            updateStatus(QString("最后保存: %1").arg(filename));
            
            showNotification("截图成功", QString("已保存到: %1").arg(filename));
            
            // 如果启用了自动打开文件夹，打开文件位置
            if (ui->openFolderCheck->isChecked()) {
                QDesktopServices::openUrl(QUrl::fromLocalFile(m_outputDirectory));
            }
        } else {
            updateStatus("保存失败");
            showNotification("截图失败", "无法保存图片文件");
        }
    } else {
        updateStatus("截图失败");
        showNotification("截图失败", "无法捕获屏幕图像");
    }
}

void ScreenCapturer::showAboutDialog()
{
    QString aboutText = QString(
        "<h3>屏幕截图工具 v%1</h3>"
        "<p>一个功能强大的定时屏幕截图工具</p>"
        "<p>功能特性：</p>"
        "<ul>"
        "<li>定时自动截图</li>"
        "<li>手动随时截图</li>"
        "<li>多显示器支持</li>"
        "<li>自定义保存目录</li>"
        "<li>多种图片格式</li>"
        "<li>系统托盘运行</li>"
        "</ul>"
        "<p>版权所有 © 2023 您的公司</p>"
    ).arg(qApp->applicationVersion());
    
    QMessageBox::about(this, "关于屏幕截图工具", aboutText);
}