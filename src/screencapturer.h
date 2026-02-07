#ifndef SCREENCAPTURER_H
#define SCREENCAPTURER_H

#include <QMainWindow>
#include <QTimer>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QPixmap>
#include <QScreen>
#include <QList>
#include <QSettings>
#include <QTextEdit>
#include <QAction>

QT_BEGIN_NAMESPACE
namespace Ui {
    class ScreenCapturer;
}

class QLabel;
class QSpinBox;
class QComboBox;
class QLineEdit;
class QCheckBox;
class QPushButton;
class QGroupBox;
QT_END_NAMESPACE

struct MonitorInfo {
    int index;          // 显示器编号（0=所有，1=第一个，2=第二个...）
    QString name;       // 显示器名称
    QRect geometry;     // 显示器位置和尺寸
    bool isPrimary;     // 是否为主显示器
};

class ScreenCapturer : public QMainWindow
{
    Q_OBJECT

public:
    explicit ScreenCapturer(QWidget *parent = nullptr);
    ~ScreenCapturer();

    // 公共方法
    void setCaptureInterval(int minutes);
    void setOutputDirectory(const QString &path);
    void setMonitorIndex(int index);
    void startCapture();
    void stopCapture();
    void captureNow();

protected:
    void closeEvent(QCloseEvent *event) override;
    void changeEvent(QEvent *event) override;

private slots:
    // UI事件处理
    void onStartButtonClicked();
    void onStopButtonClicked();
    void onCaptureNowButtonClicked();
    void onBrowseButtonClicked();
    void onClearLogButtonClicked();
    void onSaveLogButtonClicked();
    void onOpenOutputFolder();
    
    // 设置变更
    void onMonitorComboChanged(int index);
    void onIntervalChanged(int value);
    void onFormatComboChanged(const QString &format);
    void onQualityChanged(int value);
    
    // 定时器事件
    void onCaptureTimerTimeout();
    void onUpdateTimerTimeout();
    
    // 系统托盘事件
    void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);
    
    // 菜单动作
    void onPreferencesTriggered();
    void onAlwaysOnTopToggled(bool checked);
    void onShowTrayIconToggled(bool checked);
    
    // 其他槽函数
    void updateScreensInfo();
    void showAboutDialog();
    
    // 自动滚动日志
    void onAutoScrollToggled(bool checked);

private:
    // UI组件
    Ui::ScreenCapturer *ui;
    
    // 核心组件
    QTimer *m_captureTimer;
    QTimer *m_updateTimer;
    QSystemTrayIcon *m_trayIcon;
    QMenu *m_trayMenu;
    QSettings *m_settings;
    
    // 状态变量
    bool m_isCapturing;
    int m_captureCount;
    int m_monitorIndex;
    QString m_outputDirectory;
    QString m_imageFormat;
    int m_imageQuality;
    
    // 显示器信息
    QList<MonitorInfo> m_monitors;
    
    // 私有方法
    void initializeUI();
    void initializeMenuBar();
    void initializeToolBar();
    void initializeConnections();
    void initializeTrayIcon();
    void loadSettings();
    void saveSettings();
    
    // 截图相关
    QPixmap captureScreen(int monitorIndex);
    bool saveScreenshot(const QPixmap &screenshot, const QString &filename);
    QString generateFilename() const;
    QString getImageFormatExtension() const;
    
    // 工具方法
    bool ensureDirectoryExists(const QString &path);
    void showNotification(const QString &title, const QString &message);
    void updateStatus(const QString &message);
    void updateCounter();
    void updateScreenshotPreview(const QPixmap &pixmap);
    void logMessage(const QString &message);
    void openOutputFolder();
    
    // 验证方法
    bool validateSettings();
    bool isOutputDirectoryValid() const;
    
    // 常量
    static const int DEFAULT_INTERVAL = 5;      // 默认5分钟
    static const int MIN_INTERVAL = 1;          // 最小1分钟
    static const int MAX_INTERVAL = 1440;       // 最大24小时
};

#endif // SCREENCAPTURER_H