/********************************************************************************
** Form generated from reading UI file 'screencapturer.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENCAPTURER_H
#define UI_SCREENCAPTURER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScreenCapturer
{
public:
    QAction *actionCaptureNow;
    QAction *actionStartCapture;
    QAction *actionStopCapture;
    QAction *actionExit;
    QAction *actionPreferences;
    QAction *actionShowTrayIcon;
    QAction *actionAlwaysOnTop;
    QAction *actionAbout;
    QAction *actionOpenOutputFolder;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *captureTab;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *basicGroupBox;
    QGridLayout *gridLayout;
    QLabel *intervalLabel;
    QSpinBox *intervalSpin;
    QLabel *monitorLabel;
    QComboBox *monitorCombo;
    QLabel *directoryLabel;
    QLineEdit *directoryEdit;
    QPushButton *browseButton;
    QLabel *formatLabel;
    QComboBox *formatCombo;
    QLabel *qualityLabel;
    QSpinBox *qualitySpin;
    QGroupBox *optionsGroupBox;
    QGridLayout *gridLayout_2;
    QCheckBox *clipboardCheck;
    QCheckBox *showBordersCheck;
    QCheckBox *immediateCheck;
    QCheckBox *openFolderCheck;
    QCheckBox *notificationsCheck;
    QCheckBox *minimizeToTrayCheck;
    QCheckBox *enablePreviewCheck;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *captureNowButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *aboutButton;
    QWidget *statusTab;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *statusGroupBox;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLabel *statusLabel;
    QLabel *label_2;
    QLabel *counterLabel;
    QLabel *label_3;
    QLabel *nextCaptureLabel;
    QLabel *label_4;
    QLabel *timeLabel;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *previewGroupBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *previewLabel;
    QWidget *logTab;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *logTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *clearLogButton;
    QPushButton *saveLogButton;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *autoScrollCheck;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QMenu *menuView;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ScreenCapturer)
    {
        if (ScreenCapturer->objectName().isEmpty())
            ScreenCapturer->setObjectName("ScreenCapturer");
        ScreenCapturer->resize(680, 580);
        ScreenCapturer->setMinimumSize(QSize(680, 580));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/camera.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ScreenCapturer->setWindowIcon(icon);
        ScreenCapturer->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #f5f5f5;\n"
"}\n"
"QGroupBox {\n"
"    font-weight: bold;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 5px;\n"
"    margin-top: 10px;\n"
"    padding-top: 10px;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 5px 0 5px;\n"
"}\n"
"QPushButton {\n"
"    padding: 6px 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e0e0e0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #d0d0d0;\n"
"}\n"
"QPushButton#startButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"}\n"
"QPushButton#startButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"QPushButton#stopButton {\n"
"    background-color: #f44336;\n"
"    color: white;\n"
"}\n"
"QPushButton#stopButton:hover {\n"
"    background-color: #da190b;\n"
"}\n"
"QPushButton#captureNowButton {\n"
"    background-color: #2196F3;\n"
"    color: white;\n"
"}\n"
"QPushButton#c"
                        "aptureNowButton:hover {\n"
"    background-color: #0b7dda;\n"
"}\n"
"QLabel#statusLabel {\n"
"    font-weight: bold;\n"
"    color: #333333;\n"
"}\n"
"QLabel#counterLabel {\n"
"    font-weight: bold;\n"
"    color: #2196F3;\n"
"}\n"
"QLabel#timeLabel {\n"
"    font-family: 'Consolas', 'Monaco', monospace;\n"
"    font-size: 12pt;\n"
"    color: #333333;\n"
"}\n"
"QLabel#previewLabel {\n"
"    border: 2px solid #cccccc;\n"
"    border-radius: 5px;\n"
"    background-color: white;\n"
"}\n"
"QSpinBox, QComboBox, QLineEdit {\n"
"    padding: 4px;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 3px;\n"
"    min-height: 20px;\n"
"}\n"
"QSpinBox:hover, QComboBox:hover, QLineEdit:hover {\n"
"    border-color: #999999;\n"
"}\n"
"QSpinBox:focus, QComboBox:focus, QLineEdit:focus {\n"
"    border-color: #2196F3;\n"
"    outline: none;\n"
"}\n"
"QCheckBox {\n"
"    spacing: 5px;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
"QTabWidget::pane {\n"
"    border: 1px solid #cccc"
                        "cc;\n"
"    background-color: white;\n"
"    border-radius: 5px;\n"
"}\n"
"QTabWidget::tab-bar {\n"
"    alignment: center;\n"
"}\n"
"QTabBar::tab {\n"
"    background-color: #e0e0e0;\n"
"    border: 1px solid #cccccc;\n"
"    padding: 8px 16px;\n"
"    margin-right: 2px;\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"}\n"
"QTabBar::tab:selected {\n"
"    background-color: white;\n"
"    border-bottom-color: white;\n"
"}\n"
"QTabBar::tab:hover:!selected {\n"
"    background-color: #f0f0f0;\n"
"}"));
        actionCaptureNow = new QAction(ScreenCapturer);
        actionCaptureNow->setObjectName("actionCaptureNow");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/capture.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionCaptureNow->setIcon(icon1);
        actionStartCapture = new QAction(ScreenCapturer);
        actionStartCapture->setObjectName("actionStartCapture");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/start.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionStartCapture->setIcon(icon2);
        actionStopCapture = new QAction(ScreenCapturer);
        actionStopCapture->setObjectName("actionStopCapture");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/stop.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionStopCapture->setIcon(icon3);
        actionExit = new QAction(ScreenCapturer);
        actionExit->setObjectName("actionExit");
        actionPreferences = new QAction(ScreenCapturer);
        actionPreferences->setObjectName("actionPreferences");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/settings.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionPreferences->setIcon(icon4);
        actionShowTrayIcon = new QAction(ScreenCapturer);
        actionShowTrayIcon->setObjectName("actionShowTrayIcon");
        actionShowTrayIcon->setCheckable(true);
        actionShowTrayIcon->setChecked(true);
        actionAlwaysOnTop = new QAction(ScreenCapturer);
        actionAlwaysOnTop->setObjectName("actionAlwaysOnTop");
        actionAlwaysOnTop->setCheckable(true);
        actionAbout = new QAction(ScreenCapturer);
        actionAbout->setObjectName("actionAbout");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/about.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionAbout->setIcon(icon5);
        actionOpenOutputFolder = new QAction(ScreenCapturer);
        actionOpenOutputFolder->setObjectName("actionOpenOutputFolder");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/folder.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionOpenOutputFolder->setIcon(icon6);
        centralWidget = new QWidget(ScreenCapturer);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        captureTab = new QWidget();
        captureTab->setObjectName("captureTab");
        verticalLayout_2 = new QVBoxLayout(captureTab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        basicGroupBox = new QGroupBox(captureTab);
        basicGroupBox->setObjectName("basicGroupBox");
        gridLayout = new QGridLayout(basicGroupBox);
        gridLayout->setObjectName("gridLayout");
        intervalLabel = new QLabel(basicGroupBox);
        intervalLabel->setObjectName("intervalLabel");

        gridLayout->addWidget(intervalLabel, 0, 0, 1, 1);

        intervalSpin = new QSpinBox(basicGroupBox);
        intervalSpin->setObjectName("intervalSpin");
        intervalSpin->setMinimum(1);
        intervalSpin->setMaximum(1440);
        intervalSpin->setValue(5);

        gridLayout->addWidget(intervalSpin, 0, 1, 1, 1);

        monitorLabel = new QLabel(basicGroupBox);
        monitorLabel->setObjectName("monitorLabel");

        gridLayout->addWidget(monitorLabel, 1, 0, 1, 1);

        monitorCombo = new QComboBox(basicGroupBox);
        monitorCombo->setObjectName("monitorCombo");

        gridLayout->addWidget(monitorCombo, 1, 1, 1, 1);

        directoryLabel = new QLabel(basicGroupBox);
        directoryLabel->setObjectName("directoryLabel");

        gridLayout->addWidget(directoryLabel, 2, 0, 1, 1);

        directoryEdit = new QLineEdit(basicGroupBox);
        directoryEdit->setObjectName("directoryEdit");

        gridLayout->addWidget(directoryEdit, 2, 1, 1, 1);

        browseButton = new QPushButton(basicGroupBox);
        browseButton->setObjectName("browseButton");

        gridLayout->addWidget(browseButton, 2, 2, 1, 1);

        formatLabel = new QLabel(basicGroupBox);
        formatLabel->setObjectName("formatLabel");

        gridLayout->addWidget(formatLabel, 3, 0, 1, 1);

        formatCombo = new QComboBox(basicGroupBox);
        formatCombo->setObjectName("formatCombo");

        gridLayout->addWidget(formatCombo, 3, 1, 1, 1);

        qualityLabel = new QLabel(basicGroupBox);
        qualityLabel->setObjectName("qualityLabel");

        gridLayout->addWidget(qualityLabel, 3, 2, 1, 1);

        qualitySpin = new QSpinBox(basicGroupBox);
        qualitySpin->setObjectName("qualitySpin");
        qualitySpin->setMinimum(1);
        qualitySpin->setMaximum(100);
        qualitySpin->setValue(100);

        gridLayout->addWidget(qualitySpin, 3, 3, 1, 1);


        verticalLayout_2->addWidget(basicGroupBox);

        optionsGroupBox = new QGroupBox(captureTab);
        optionsGroupBox->setObjectName("optionsGroupBox");
        gridLayout_2 = new QGridLayout(optionsGroupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        clipboardCheck = new QCheckBox(optionsGroupBox);
        clipboardCheck->setObjectName("clipboardCheck");

        gridLayout_2->addWidget(clipboardCheck, 0, 0, 1, 1);

        showBordersCheck = new QCheckBox(optionsGroupBox);
        showBordersCheck->setObjectName("showBordersCheck");

        gridLayout_2->addWidget(showBordersCheck, 0, 1, 1, 1);

        immediateCheck = new QCheckBox(optionsGroupBox);
        immediateCheck->setObjectName("immediateCheck");
        immediateCheck->setChecked(true);

        gridLayout_2->addWidget(immediateCheck, 1, 0, 1, 1);

        openFolderCheck = new QCheckBox(optionsGroupBox);
        openFolderCheck->setObjectName("openFolderCheck");

        gridLayout_2->addWidget(openFolderCheck, 1, 1, 1, 1);

        notificationsCheck = new QCheckBox(optionsGroupBox);
        notificationsCheck->setObjectName("notificationsCheck");
        notificationsCheck->setChecked(true);

        gridLayout_2->addWidget(notificationsCheck, 2, 0, 1, 1);

        minimizeToTrayCheck = new QCheckBox(optionsGroupBox);
        minimizeToTrayCheck->setObjectName("minimizeToTrayCheck");
        minimizeToTrayCheck->setChecked(true);

        gridLayout_2->addWidget(minimizeToTrayCheck, 2, 1, 1, 1);

        enablePreviewCheck = new QCheckBox(optionsGroupBox);
        enablePreviewCheck->setObjectName("enablePreviewCheck");
        enablePreviewCheck->setChecked(true);

        gridLayout_2->addWidget(enablePreviewCheck, 3, 0, 1, 2);


        verticalLayout_2->addWidget(optionsGroupBox);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        startButton = new QPushButton(captureTab);
        startButton->setObjectName("startButton");

        horizontalLayout->addWidget(startButton);

        stopButton = new QPushButton(captureTab);
        stopButton->setObjectName("stopButton");
        stopButton->setEnabled(false);

        horizontalLayout->addWidget(stopButton);

        captureNowButton = new QPushButton(captureTab);
        captureNowButton->setObjectName("captureNowButton");

        horizontalLayout->addWidget(captureNowButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        aboutButton = new QPushButton(captureTab);
        aboutButton->setObjectName("aboutButton");

        horizontalLayout->addWidget(aboutButton);


        verticalLayout_2->addLayout(horizontalLayout);

        tabWidget->addTab(captureTab, QString());
        statusTab = new QWidget();
        statusTab->setObjectName("statusTab");
        verticalLayout_3 = new QVBoxLayout(statusTab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        statusGroupBox = new QGroupBox(statusTab);
        statusGroupBox->setObjectName("statusGroupBox");
        gridLayout_3 = new QGridLayout(statusGroupBox);
        gridLayout_3->setObjectName("gridLayout_3");
        label = new QLabel(statusGroupBox);
        label->setObjectName("label");

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        statusLabel = new QLabel(statusGroupBox);
        statusLabel->setObjectName("statusLabel");

        gridLayout_3->addWidget(statusLabel, 0, 1, 1, 1);

        label_2 = new QLabel(statusGroupBox);
        label_2->setObjectName("label_2");

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        counterLabel = new QLabel(statusGroupBox);
        counterLabel->setObjectName("counterLabel");

        gridLayout_3->addWidget(counterLabel, 1, 1, 1, 1);

        label_3 = new QLabel(statusGroupBox);
        label_3->setObjectName("label_3");

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        nextCaptureLabel = new QLabel(statusGroupBox);
        nextCaptureLabel->setObjectName("nextCaptureLabel");

        gridLayout_3->addWidget(nextCaptureLabel, 2, 1, 1, 1);

        label_4 = new QLabel(statusGroupBox);
        label_4->setObjectName("label_4");

        gridLayout_3->addWidget(label_4, 3, 0, 1, 1);

        timeLabel = new QLabel(statusGroupBox);
        timeLabel->setObjectName("timeLabel");

        gridLayout_3->addWidget(timeLabel, 3, 1, 1, 1);


        verticalLayout_3->addWidget(statusGroupBox);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        previewGroupBox = new QGroupBox(statusTab);
        previewGroupBox->setObjectName("previewGroupBox");
        verticalLayout_4 = new QVBoxLayout(previewGroupBox);
        verticalLayout_4->setObjectName("verticalLayout_4");
        previewLabel = new QLabel(previewGroupBox);
        previewLabel->setObjectName("previewLabel");
        previewLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(previewLabel);


        verticalLayout_3->addWidget(previewGroupBox);

        tabWidget->addTab(statusTab, QString());
        logTab = new QWidget();
        logTab->setObjectName("logTab");
        verticalLayout_5 = new QVBoxLayout(logTab);
        verticalLayout_5->setObjectName("verticalLayout_5");
        logTextEdit = new QTextEdit(logTab);
        logTextEdit->setObjectName("logTextEdit");
        logTextEdit->setReadOnly(true);

        verticalLayout_5->addWidget(logTextEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        clearLogButton = new QPushButton(logTab);
        clearLogButton->setObjectName("clearLogButton");

        horizontalLayout_2->addWidget(clearLogButton);

        saveLogButton = new QPushButton(logTab);
        saveLogButton->setObjectName("saveLogButton");

        horizontalLayout_2->addWidget(saveLogButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        autoScrollCheck = new QCheckBox(logTab);
        autoScrollCheck->setObjectName("autoScrollCheck");
        autoScrollCheck->setChecked(true);

        horizontalLayout_2->addWidget(autoScrollCheck);


        verticalLayout_5->addLayout(horizontalLayout_2);

        tabWidget->addTab(logTab, QString());

        verticalLayout->addWidget(tabWidget);

        ScreenCapturer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ScreenCapturer);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 680, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName("menuSettings");
        menuView = new QMenu(menuBar);
        menuView->setObjectName("menuView");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        ScreenCapturer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ScreenCapturer);
        mainToolBar->setObjectName("mainToolBar");
        mainToolBar->setMovable(false);
        ScreenCapturer->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ScreenCapturer);
        statusBar->setObjectName("statusBar");
        ScreenCapturer->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionCaptureNow);
        menuFile->addSeparator();
        menuFile->addAction(actionStartCapture);
        menuFile->addAction(actionStopCapture);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuSettings->addAction(actionPreferences);
        menuView->addAction(actionShowTrayIcon);
        menuView->addAction(actionAlwaysOnTop);
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionStartCapture);
        mainToolBar->addAction(actionStopCapture);
        mainToolBar->addAction(actionCaptureNow);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionOpenOutputFolder);

        retranslateUi(ScreenCapturer);
        QObject::connect(actionCaptureNow, &QAction::triggered, ScreenCapturer, qOverload<>(&QMainWindow::onCaptureNowButtonClicked));
        QObject::connect(actionStartCapture, &QAction::triggered, ScreenCapturer, qOverload<>(&QMainWindow::onStartButtonClicked));
        QObject::connect(actionStopCapture, &QAction::triggered, ScreenCapturer, qOverload<>(&QMainWindow::onStopButtonClicked));
        QObject::connect(actionExit, &QAction::triggered, ScreenCapturer, qOverload<>(&QMainWindow::close));
        QObject::connect(actionAbout, &QAction::triggered, ScreenCapturer, qOverload<>(&QMainWindow::showAboutDialog));
        QObject::connect(actionOpenOutputFolder, &QAction::triggered, ScreenCapturer, qOverload<>(&QMainWindow::onOpenOutputFolder));
        QObject::connect(clearLogButton, &QPushButton::clicked, ScreenCapturer, qOverload<>(&QMainWindow::onClearLogButtonClicked));
        QObject::connect(saveLogButton, &QPushButton::clicked, ScreenCapturer, qOverload<>(&QMainWindow::onSaveLogButtonClicked));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ScreenCapturer);
    } // setupUi

    void retranslateUi(QMainWindow *ScreenCapturer)
    {
        ScreenCapturer->setWindowTitle(QCoreApplication::translate("ScreenCapturer", "\345\261\217\345\271\225\346\210\252\345\233\276\345\267\245\345\205\267", nullptr));
        actionCaptureNow->setText(QCoreApplication::translate("ScreenCapturer", "\347\253\213\345\215\263\346\210\252\345\233\276", nullptr));
#if QT_CONFIG(shortcut)
        actionCaptureNow->setShortcut(QCoreApplication::translate("ScreenCapturer", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStartCapture->setText(QCoreApplication::translate("ScreenCapturer", "\345\274\200\345\247\213\345\256\232\346\227\266\346\210\252\345\233\276", nullptr));
#if QT_CONFIG(shortcut)
        actionStartCapture->setShortcut(QCoreApplication::translate("ScreenCapturer", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStopCapture->setText(QCoreApplication::translate("ScreenCapturer", "\345\201\234\346\255\242\346\210\252\345\233\276", nullptr));
#if QT_CONFIG(shortcut)
        actionStopCapture->setShortcut(QCoreApplication::translate("ScreenCapturer", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("ScreenCapturer", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("ScreenCapturer", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPreferences->setText(QCoreApplication::translate("ScreenCapturer", "\351\246\226\351\200\211\351\241\271...", nullptr));
#if QT_CONFIG(shortcut)
        actionPreferences->setShortcut(QCoreApplication::translate("ScreenCapturer", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionShowTrayIcon->setText(QCoreApplication::translate("ScreenCapturer", "\346\230\276\347\244\272\347\263\273\347\273\237\346\211\230\347\233\230\345\233\276\346\240\207", nullptr));
        actionAlwaysOnTop->setText(QCoreApplication::translate("ScreenCapturer", "\347\252\227\345\217\243\347\275\256\351\241\266", nullptr));
        actionAbout->setText(QCoreApplication::translate("ScreenCapturer", "\345\205\263\344\272\216...", nullptr));
#if QT_CONFIG(shortcut)
        actionAbout->setShortcut(QCoreApplication::translate("ScreenCapturer", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpenOutputFolder->setText(QCoreApplication::translate("ScreenCapturer", "\346\211\223\345\274\200\350\276\223\345\207\272\346\226\207\344\273\266\345\244\271", nullptr));
#if QT_CONFIG(shortcut)
        actionOpenOutputFolder->setShortcut(QCoreApplication::translate("ScreenCapturer", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        basicGroupBox->setTitle(QCoreApplication::translate("ScreenCapturer", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        intervalLabel->setText(QCoreApplication::translate("ScreenCapturer", "\346\210\252\345\233\276\351\227\264\351\232\224\357\274\232", nullptr));
        intervalSpin->setSuffix(QCoreApplication::translate("ScreenCapturer", " \345\210\206\351\222\237", nullptr));
        monitorLabel->setText(QCoreApplication::translate("ScreenCapturer", "\346\230\276\347\244\272\345\231\250\357\274\232", nullptr));
        directoryLabel->setText(QCoreApplication::translate("ScreenCapturer", "\344\277\235\345\255\230\347\233\256\345\275\225\357\274\232", nullptr));
        browseButton->setText(QCoreApplication::translate("ScreenCapturer", "\346\265\217\350\247\210...", nullptr));
        formatLabel->setText(QCoreApplication::translate("ScreenCapturer", "\345\233\276\347\211\207\346\240\274\345\274\217\357\274\232", nullptr));
        qualityLabel->setText(QCoreApplication::translate("ScreenCapturer", "\350\264\250\351\207\217\357\274\232", nullptr));
        qualitySpin->setSuffix(QCoreApplication::translate("ScreenCapturer", "%", nullptr));
        optionsGroupBox->setTitle(QCoreApplication::translate("ScreenCapturer", "\351\200\211\351\241\271", nullptr));
        clipboardCheck->setText(QCoreApplication::translate("ScreenCapturer", "\346\210\252\345\233\276\346\227\266\345\244\215\345\210\266\345\210\260\345\211\252\350\264\264\346\235\277", nullptr));
        showBordersCheck->setText(QCoreApplication::translate("ScreenCapturer", "\346\230\276\347\244\272\346\230\276\347\244\272\345\231\250\350\276\271\346\241\206", nullptr));
        immediateCheck->setText(QCoreApplication::translate("ScreenCapturer", "\345\220\257\345\212\250\346\227\266\347\253\213\345\215\263\346\210\252\345\233\276", nullptr));
        openFolderCheck->setText(QCoreApplication::translate("ScreenCapturer", "\346\210\252\345\233\276\345\220\216\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", nullptr));
        notificationsCheck->setText(QCoreApplication::translate("ScreenCapturer", "\346\230\276\347\244\272\347\263\273\347\273\237\351\200\232\347\237\245", nullptr));
        minimizeToTrayCheck->setText(QCoreApplication::translate("ScreenCapturer", "\346\234\200\345\260\217\345\214\226\345\210\260\347\263\273\347\273\237\346\211\230\347\233\230", nullptr));
        enablePreviewCheck->setText(QCoreApplication::translate("ScreenCapturer", "\345\220\257\347\224\250\346\210\252\345\233\276\351\242\204\350\247\210", nullptr));
        startButton->setText(QCoreApplication::translate("ScreenCapturer", "\345\274\200\345\247\213\345\256\232\346\227\266\346\210\252\345\233\276", nullptr));
        stopButton->setText(QCoreApplication::translate("ScreenCapturer", "\345\201\234\346\255\242\346\210\252\345\233\276", nullptr));
        captureNowButton->setText(QCoreApplication::translate("ScreenCapturer", "\347\253\213\345\215\263\346\210\252\345\233\276", nullptr));
        aboutButton->setText(QCoreApplication::translate("ScreenCapturer", "\345\205\263\344\272\216", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(captureTab), QCoreApplication::translate("ScreenCapturer", "\346\210\252\345\233\276\350\256\276\347\275\256", nullptr));
        statusGroupBox->setTitle(QCoreApplication::translate("ScreenCapturer", "\350\277\220\350\241\214\347\212\266\346\200\201", nullptr));
        label->setText(QCoreApplication::translate("ScreenCapturer", "\345\275\223\345\211\215\347\212\266\346\200\201\357\274\232", nullptr));
        statusLabel->setText(QCoreApplication::translate("ScreenCapturer", "\345\260\261\347\273\252", nullptr));
        label_2->setText(QCoreApplication::translate("ScreenCapturer", "\346\210\252\345\233\276\350\256\241\346\225\260\357\274\232", nullptr));
        counterLabel->setText(QCoreApplication::translate("ScreenCapturer", "\345\267\262\346\210\252\345\233\276: 0 \345\274\240", nullptr));
        label_3->setText(QCoreApplication::translate("ScreenCapturer", "\344\270\213\346\254\241\346\210\252\345\233\276\357\274\232", nullptr));
        nextCaptureLabel->setText(QCoreApplication::translate("ScreenCapturer", "\344\270\213\346\254\241\346\210\252\345\233\276: --", nullptr));
        label_4->setText(QCoreApplication::translate("ScreenCapturer", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", nullptr));
        timeLabel->setText(QCoreApplication::translate("ScreenCapturer", "--", nullptr));
        previewGroupBox->setTitle(QCoreApplication::translate("ScreenCapturer", "\346\210\252\345\233\276\351\242\204\350\247\210", nullptr));
        previewLabel->setText(QCoreApplication::translate("ScreenCapturer", "\351\242\204\350\247\210\345\214\272\345\237\237", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(statusTab), QCoreApplication::translate("ScreenCapturer", "\347\212\266\346\200\201\344\277\241\346\201\257", nullptr));
        logTextEdit->setHtml(QCoreApplication::translate("ScreenCapturer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\254\242\350\277\216\344\275\277\347\224\250\345\261\217\345\271\225\346\210\252\345\233\276\345\267\245\345\205\267\357\274\201</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\257\267\347\202\271\345\207\273\"\345\274\200\345\247\213\345\256\232\346\227\266\346\210\252\345\233\276\"\346\214\211\351\222\256\345\274\200"
                        "\345\247\213\350\207\252\345\212\250\346\210\252\345\233\276\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\210\226\350\200\205\347\202\271\345\207\273\"\347\253\213\345\215\263\346\210\252\345\233\276\"\346\214\211\351\222\256\346\211\213\345\212\250\346\210\252\345\233\276\343\200\202</p></body></html>", nullptr));
        clearLogButton->setText(QCoreApplication::translate("ScreenCapturer", "\346\270\205\347\251\272\346\227\245\345\277\227", nullptr));
        saveLogButton->setText(QCoreApplication::translate("ScreenCapturer", "\344\277\235\345\255\230\346\227\245\345\277\227", nullptr));
        autoScrollCheck->setText(QCoreApplication::translate("ScreenCapturer", "\350\207\252\345\212\250\346\273\232\345\212\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(logTab), QCoreApplication::translate("ScreenCapturer", "\346\227\245\345\277\227", nullptr));
        menuFile->setTitle(QCoreApplication::translate("ScreenCapturer", "\346\226\207\344\273\266", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("ScreenCapturer", "\350\256\276\347\275\256", nullptr));
        menuView->setTitle(QCoreApplication::translate("ScreenCapturer", "\346\237\245\347\234\213", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("ScreenCapturer", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScreenCapturer: public Ui_ScreenCapturer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENCAPTURER_H
