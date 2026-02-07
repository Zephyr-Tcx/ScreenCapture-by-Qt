#include "screencapturer.h"
#include <QApplication>
#include <QCommandLineParser>
#include <QStyleFactory>
#include <QTranslator>
#include <QLocale>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // 设置应用程序信息
    app.setApplicationName("ScreenCaptureTool");
    app.setApplicationDisplayName("屏幕截图工具");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("YourCompany");
    app.setOrganizationDomain("example.com");
    
    // 设置窗口样式
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    
    // 设置图标
    app.setWindowIcon(QIcon(":/icons/camera.png"));
    
    // 支持命令行参数
    QCommandLineParser parser;
    parser.setApplicationDescription("定时屏幕截图工具 - 自动截取屏幕并保存为图片");
    parser.addHelpOption();
    parser.addVersionOption();
    
    // 定义命令行选项
    QCommandLineOption intervalOption(
        QStringList() << "i" << "interval",
        "设置截图间隔（分钟）",
        "minutes",
        "5"
    );
    
    QCommandLineOption outputOption(
        QStringList() << "o" << "output",
        "设置输出目录",
        "directory"
    );
    
    QCommandLineOption monitorOption(
        QStringList() << "m" << "monitor",
        "设置显示器编号（0=所有显示器, 1=主显示器, 2=第二显示器...）",
        "number",
        "0"
    );
    
    QCommandLineOption autostartOption(
        QStringList() << "a" << "autostart",
        "程序启动后自动开始截图"
    );
    
    QCommandLineOption hiddenOption(
        QStringList() << "h" << "hidden",
        "启动时隐藏主窗口（最小化到系统托盘）"
    );
    
    parser.addOption(intervalOption);
    parser.addOption(outputOption);
    parser.addOption(monitorOption);
    parser.addOption(autostartOption);
    parser.addOption(hiddenOption);
    
    // 解析命令行参数
    parser.process(app);
    
    // 创建主窗口
    ScreenCapturer window;
    
    // 应用命令行参数
    if (parser.isSet(intervalOption)) {
        int interval = parser.value(intervalOption).toInt();
        if (interval > 0) {
            window.setCaptureInterval(interval);
        }
    }
    
    if (parser.isSet(outputOption)) {
        QString outputDir = parser.value(outputOption);
        window.setOutputDirectory(outputDir);
    }
    
    if (parser.isSet(monitorOption)) {
        int monitor = parser.value(monitorOption).toInt();
        window.setMonitorIndex(monitor);
    }
    
    // 显示窗口（除非指定隐藏）
    if (!parser.isSet(hiddenOption)) {
        window.show();
    }
    
    // 如果指定了自动启动，开始截图
    if (parser.isSet(autostartOption)) {
        window.startCapture();
    }
    
    return app.exec();
}