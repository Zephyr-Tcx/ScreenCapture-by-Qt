#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QSystemTrayIcon>
#include <QSettings>
#include <QTableWidget>
#include <QPushButton>
#include <QSpinBox>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startCapture_clicked();
    void on_stopCapture_clicked();
    void on_manualCapture_clicked();
    void on_selectFolder_clicked();
    void on_intervalChanged(int value);
    void on_screenChanged(int index);
    void on_deleteSelected_clicked();
    void on_deleteOldFiles_clicked();
    void on_refreshList_clicked();
    void captureScreen();
    void updateFileList();
    void updateStorageInfo();
    void showSettings();
    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);
    void updateCountdown();

private:
    Ui::MainWindow *ui;
    QTimer *captureTimer;
    QTimer *countdownTimer;
    QSystemTrayIcon *trayIcon;
    QSettings *settings;
    int countdownSeconds;
    QString currentSavePath;
    
    void setupUI();
    void setupConnections();
    void loadSettings();
    void saveSettings();
    void createTrayIcon();
    void captureAndSave(QScreen *screen);
    QString generateFilename();
    void addFileToList(const QString &filepath);
    void deleteFile(const QString &filepath);
    qint64 calculateDirectorySize(const QString &path);
    void showNotification(const QString &title, const QString &message);
};

#endif // MAINWINDOW_H