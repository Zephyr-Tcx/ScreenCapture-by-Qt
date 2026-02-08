#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QScreen>
#include <QPixmap>
#include <QDateTime>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QMenu>
#include <QHeaderView>
#include <QDesktopServices>
#include <QStandardPaths>
#include <QFileInfo>
#include <QIcon>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , captureTimer(new QTimer(this))
    , countdownTimer(new QTimer(this))
    , trayIcon(nullptr)
    , settings(new QSettings("ScreenCaptureTool", "Settings", this))
    , countdownSeconds(0)
{
    ui->setupUi(this);
    setupUI();
    setupConnections();
    loadSettings();
    createTrayIcon();
    updateFileList();
}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}

void MainWindow::setupUI()
{
    // 设置窗口属性
    setWindowTitle("Screen Capture Tool");
    setWindowIcon(QIcon(":/icons/app.ico"));
    
    // 设置按钮图标
    ui->manualCapture->setIcon(QIcon(":/icons/screenshot.png"));
    ui->startCapture->setIcon(QIcon(":/icons/start.png"));
    ui->stopCapture->setIcon(QIcon(":/icons/stop.png"));
    ui->selectFolder->setIcon(QIcon(":/icons/folder.png"));
    ui->settingsButton->setIcon(QIcon(":/icons/settings.png"));
    ui->refreshList->setIcon(QIcon(":/icons/folder.png"));
    ui->deleteSelected->setIcon(QStyle::standardIcon(QStyle::SP_TrashIcon));
    ui->deleteOldFiles->setIcon(QStyle::standardIcon(QStyle::SP_TrashIcon));
    
    // 设置表格
    ui->fileTable->setColumnCount(4);
    ui->fileTable->setHorizontalHeaderLabels({"文件名", "大小", "创建时间", "路径"});
    ui->fileTable->horizontalHeader()->setStretchLastSection(true);
    ui->fileTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->fileTable->setAlternatingRowColors(true);
    
    // 初始化屏幕选择
    QList<QScreen*> screens = QGuiApplication::screens();
    for (int i = 0; i < screens.size(); ++i) {
        ui->screenCombo->addItem(QString("屏幕 %1 - %2").arg(i + 1).arg(screens[i]->name()), i);
    }
    
    // 设置快捷键
    new QShortcut(QKeySequence("Ctrl+Shift+S"), this, SLOT(on_manualCapture_clicked()));
    new QShortcut(QKeySequence("Ctrl+P"), this, SLOT(on_startCapture_clicked()));
    new QShortcut(QKeySequence("Ctrl+Q"), this, SLOT(on_stopCapture_clicked()));
}

void MainWindow::setupConnections()
{
    connect(ui->startCapture, &QPushButton::clicked, this, &MainWindow::on_startCapture_clicked);
    connect(ui->stopCapture, &QPushButton::clicked, this, &MainWindow::on_stopCapture_clicked);
    connect(ui->manualCapture, &QPushButton::clicked, this, &MainWindow::on_manualCapture_clicked);
    connect(ui->selectFolder, &QPushButton::clicked, this, &MainWindow::on_selectFolder_clicked);
    connect(ui->intervalSpin, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::on_intervalChanged);
    connect(ui->screenCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_screenChanged);
    connect(ui->deleteSelected, &QPushButton::clicked, this, &MainWindow::on_deleteSelected_clicked);
    connect(ui->deleteOldFiles, &QPushButton::clicked, this, &MainWindow::on_deleteOldFiles_clicked);
    connect(ui->refreshList, &QPushButton::clicked, this, &MainWindow::on_refreshList_clicked);
    connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::showSettings);
    connect(captureTimer, &QTimer::timeout, this, &MainWindow::captureScreen);
    connect(countdownTimer, &QTimer::timeout, this, &MainWindow::updateCountdown);
}

void MainWindow::loadSettings()
{
    currentSavePath = settings->value("savePath", 
        QStandardPaths::writableLocation(QStandardPaths::PicturesLocation) + "/ScreenCaptures").toString();
    ui->folderPath->setText(currentSavePath);
    
    int interval = settings->value("interval", 5).toInt();
    ui->intervalSpin->setValue(interval);
    
    int screenIndex = settings->value("screenIndex", 0).toInt();
    if (screenIndex < ui->screenCombo->count()) {
        ui->screenCombo->setCurrentIndex(screenIndex);
    }
    
    // 创建目录
    QDir dir(currentSavePath);
    if (!dir.exists()) {
        dir.mkpath(".");
    }
}

void MainWindow::saveSettings()
{
    settings->setValue("savePath", currentSavePath);
    settings->setValue("interval", ui->intervalSpin->value());
    settings->setValue("screenIndex", ui->screenCombo->currentIndex());
}

void MainWindow::createTrayIcon()
{
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/icons/app.ico"));
    
    QMenu *trayMenu = new QMenu(this);
    trayMenu->addAction("显示主窗口", this, [this]() { showNormal(); activateWindow(); });
    trayMenu->addAction("手动截图", this, &MainWindow::on_manualCapture_clicked);
    trayMenu->addSeparator();
    trayMenu->addAction("退出", qApp, &QCoreApplication::quit);
    
    trayIcon->setContextMenu(trayMenu);
    trayIcon->show();
    
    connect(trayIcon, &QSystemTrayIcon::activated, this, &MainWindow::trayIconActivated);
}

void MainWindow::on_startCapture_clicked()
{
    if (!captureTimer->isActive()) {
        int interval = ui->intervalSpin->value() * 60000; // 转换为毫秒
        captureTimer->start(interval);
        countdownSeconds = ui->intervalSpin->value() * 60;
        countdownTimer->start(1000);
        
        ui->statusLabel->setText("自动截图已启动");
        ui->startCapture->setEnabled(false);
        ui->stopCapture->setEnabled(true);
        
        showNotification("屏幕截图", "自动截图已启动");
    }
}

void MainWindow::on_stopCapture_clicked()
{
    if (captureTimer->isActive()) {
        captureTimer->stop();
        countdownTimer->stop();
        
        ui->statusLabel->setText("自动截图已停止");
        ui->countdownLabel->setText("");
        ui->startCapture->setEnabled(true);
        ui->stopCapture->setEnabled(false);
        
        showNotification("屏幕截图", "自动截图已停止");
    }
}

void MainWindow::on_manualCapture_clicked()
{
    captureScreen();
    showNotification("屏幕截图", "手动截图已保存");
}

void MainWindow::captureScreen()
{
    int screenIndex = ui->screenCombo->currentData().toInt();
    QList<QScreen*> screens = QGuiApplication::screens();
    
    if (screenIndex >= 0 && screenIndex < screens.size()) {
        QScreen *screen = screens[screenIndex];
        captureAndSave(screen);
    }
}

void MainWindow::captureAndSave(QScreen *screen)
{
    if (!screen) return;
    
    QPixmap pixmap = screen->grabWindow(0);
    QString filename = generateFilename();
    QString filepath = currentSavePath + "/" + filename;
    
    if (pixmap.save(filepath, "PNG")) {
        addFileToList(filepath);
        updateStorageInfo();
        
        // 重置倒计时
        countdownSeconds = ui->intervalSpin->value() * 60;
    }
}

QString MainWindow::generateFilename()
{
    QDateTime now = QDateTime::currentDateTime();
    return QString("screenshot_%1.png").arg(now.toString("yyyyMMdd_hhmmss"));
}

void MainWindow::updateCountdown()
{
    if (--countdownSeconds <= 0) {
        countdownSeconds = ui->intervalSpin->value() * 60;
    }
    
    int minutes = countdownSeconds / 60;
    int seconds = countdownSeconds % 60;
    ui->countdownLabel->setText(QString("下次截图: %1:%2").arg(minutes, 2, 10, QLatin1Char('0')).arg(seconds, 2, 10, QLatin1Char('0')));
}

void MainWindow::on_selectFolder_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "选择保存目录", currentSavePath);
    if (!dir.isEmpty()) {
        currentSavePath = dir;
        ui->folderPath->setText(dir);
        saveSettings();
        updateFileList();
    }
}

void MainWindow::on_intervalChanged(int value)
{
    if (captureTimer->isActive()) {
        captureTimer->stop();
        captureTimer->start(value * 60000);
        countdownSeconds = value * 60;
    }
}

void MainWindow::on_screenChanged(int index)
{
    Q_UNUSED(index)
    saveSettings();
}

void MainWindow::updateFileList()
{
    ui->fileTable->setRowCount(0);
    
    QDir dir(currentSavePath);
    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.jpeg" << "*.bmp";
    QFileInfoList files = dir.entryInfoList(filters, QDir::Files, QDir::Time | QDir::Reversed);
    
    for (const QFileInfo &fileInfo : files) {
        int row = ui->fileTable->rowCount();
        ui->fileTable->insertRow(row);
        
        ui->fileTable->setItem(row, 0, new QTableWidgetItem(fileInfo.fileName()));
        ui->fileTable->setItem(row, 1, new QTableWidgetItem(formatFileSize(fileInfo.size())));
        ui->fileTable->setItem(row, 2, new QTableWidgetItem(fileInfo.created().toString("yyyy-MM-dd hh:mm:ss")));
        ui->fileTable->setItem(row, 3, new QTableWidgetItem(fileInfo.filePath()));
    }
    
    updateStorageInfo();
}

QString MainWindow::formatFileSize(qint64 bytes)
{
    const qint64 KB = 1024;
    const qint64 MB = KB * 1024;
    const qint64 GB = MB * 1024;
    
    if (bytes >= GB) {
        return QString("%1 GB").arg(QString::number(bytes / (double)GB, 'f', 2));
    } else if (bytes >= MB) {
        return QString("%1 MB").arg(QString::number(bytes / (double)MB, 'f', 2));
    } else if (bytes >= KB) {
        return QString("%1 KB").arg(QString::number(bytes / (double)KB, 'f', 2));
    } else {
        return QString("%1 bytes").arg(bytes);
    }
}

void MainWindow::updateStorageInfo()
{
    qint64 size = calculateDirectorySize(currentSavePath);
    ui->storageLabel->setText(QString("存储使用: %1").arg(formatFileSize(size)));
}

qint64 MainWindow::calculateDirectorySize(const QString &path)
{
    qint64 totalSize = 0;
    QDir dir(path);
    
    QFileInfoList files = dir.entryInfoList(QDir::Files);
    for (const QFileInfo &file : files) {
        totalSize += file.size();
    }
    
    QFileInfoList subdirs = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    for (const QFileInfo &subdir : subdirs) {
        totalSize += calculateDirectorySize(subdir.filePath());
    }
    
    return totalSize;
}

void MainWindow::on_deleteSelected_clicked()
{
    QList<QTableWidgetItem*> selected = ui->fileTable->selectedItems();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "警告", "请先选择要删除的文件");
        return;
    }
    
    if (QMessageBox::question(this, "确认", "确定要删除选中的文件吗？") == QMessageBox::Yes) {
        QSet<int> rows;
        for (QTableWidgetItem *item : selected) {
            rows.insert(item->row());
        }
        
        QList<int> rowList = rows.values();
        std::sort(rowList.begin(), rowList.end(), std::greater<int>());
        
        for (int row : rowList) {
            QString filepath = ui->fileTable->item(row, 3)->text();
            deleteFile(filepath);
            ui->fileTable->removeRow(row);
        }
        
        updateStorageInfo();
    }
}

void MainWindow::on_deleteOldFiles_clicked()
{
    int days = QInputDialog::getInt(this, "删除旧文件", "删除多少天前的文件？", 30, 1, 365);
    
    QDateTime cutoff = QDateTime::currentDateTime().addDays(-days);
    int deletedCount = 0;
    
    for (int i = ui->fileTable->rowCount() - 1; i >= 0; --i) {
        QDateTime created = QDateTime::fromString(ui->fileTable->item(i, 2)->text(), "yyyy-MM-dd hh:mm:ss");
        if (created < cutoff) {
            QString filepath = ui->fileTable->item(i, 3)->text();
            deleteFile(filepath);
            ui->fileTable->removeRow(i);
            deletedCount++;
        }
    }
    
    updateStorageInfo();
    QMessageBox::information(this, "完成", QString("已删除 %1 个文件").arg(deletedCount));
}

void MainWindow::deleteFile(const QString &filepath)
{
    QFile file(filepath);
    if (file.exists()) {
        file.remove();
    }
}

void MainWindow::on_refreshList_clicked()
{
    updateFileList();
}

void MainWindow::showSettings()
{
    QDialog settingsDialog(this);
    settingsDialog.setWindowTitle("设置");
    QVBoxLayout *layout = new QVBoxLayout(&settingsDialog);
    
    // 添加设置选项
    QCheckBox *startMinimized = new QCheckBox("启动时最小化到系统托盘");
    startMinimized->setChecked(settings->value("startMinimized", false).toBool());
    layout->addWidget(startMinimized);
    
    QCheckBox *playSound = new QCheckBox("截图时播放声音");
    playSound->setChecked(settings->value("playSound", true).toBool());
    layout->addWidget(playSound);
    
    QCheckBox *autoStart = new QCheckBox("开机自启动");
    autoStart->setChecked(settings->value("autoStart", false).toBool());
    layout->addWidget(autoStart);
    
    QPushButton *saveButton = new QPushButton("保存");
    layout->addWidget(saveButton);
    
    connect(saveButton, &QPushButton::clicked, &settingsDialog, [&, startMinimized, playSound, autoStart]() {
        settings->setValue("startMinimized", startMinimized->isChecked());
        settings->setValue("playSound", playSound->isChecked());
        settings->setValue("autoStart", autoStart->isChecked());
        settingsDialog.accept();
    });
    
    settingsDialog.exec();
}

void MainWindow::trayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::DoubleClick) {
        showNormal();
        activateWindow();
    }
}

void MainWindow::showNotification(const QString &title, const QString &message)
{
    if (settings->value("showNotifications", true).toBool()) {
        trayIcon->showMessage(title, message);
    }
}