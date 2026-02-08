/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *intervalSpin;
    QLabel *label_2;
    QComboBox *screenCombo;
    QPushButton *startCapture;
    QPushButton *stopCapture;
    QPushButton *manualCapture;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLineEdit *folderPath;
    QPushButton *selectFolder;
    QHBoxLayout *horizontalLayout;
    QPushButton *refreshList;
    QPushButton *deleteSelected;
    QPushButton *deleteOldFiles;
    QPushButton *settingsButton;
    QSpacerItem *horizontalSpacer;
    QTableWidget *fileTable;
    QHBoxLayout *horizontalLayout_2;
    QLabel *statusLabel;
    QLabel *countdownLabel;
    QLabel *storageLabel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        intervalSpin = new QSpinBox(groupBox);
        intervalSpin->setObjectName("intervalSpin");
        intervalSpin->setMinimum(1);
        intervalSpin->setMaximum(60);
        intervalSpin->setValue(5);

        gridLayout->addWidget(intervalSpin, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        screenCombo = new QComboBox(groupBox);
        screenCombo->setObjectName("screenCombo");

        gridLayout->addWidget(screenCombo, 0, 3, 1, 1);

        startCapture = new QPushButton(groupBox);
        startCapture->setObjectName("startCapture");

        gridLayout->addWidget(startCapture, 1, 0, 1, 2);

        stopCapture = new QPushButton(groupBox);
        stopCapture->setObjectName("stopCapture");
        stopCapture->setEnabled(false);

        gridLayout->addWidget(stopCapture, 1, 2, 1, 2);

        manualCapture = new QPushButton(groupBox);
        manualCapture->setObjectName("manualCapture");

        gridLayout->addWidget(manualCapture, 2, 0, 1, 4);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        folderPath = new QLineEdit(groupBox_2);
        folderPath->setObjectName("folderPath");

        gridLayout_2->addWidget(folderPath, 0, 1, 1, 1);

        selectFolder = new QPushButton(groupBox_2);
        selectFolder->setObjectName("selectFolder");

        gridLayout_2->addWidget(selectFolder, 0, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        refreshList = new QPushButton(groupBox_2);
        refreshList->setObjectName("refreshList");

        horizontalLayout->addWidget(refreshList);

        deleteSelected = new QPushButton(groupBox_2);
        deleteSelected->setObjectName("deleteSelected");

        horizontalLayout->addWidget(deleteSelected);

        deleteOldFiles = new QPushButton(groupBox_2);
        deleteOldFiles->setObjectName("deleteOldFiles");

        horizontalLayout->addWidget(deleteOldFiles);

        settingsButton = new QPushButton(groupBox_2);
        settingsButton->setObjectName("settingsButton");

        horizontalLayout->addWidget(settingsButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 3);


        verticalLayout->addWidget(groupBox_2);

        fileTable = new QTableWidget(centralwidget);
        fileTable->setObjectName("fileTable");

        verticalLayout->addWidget(fileTable);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");

        horizontalLayout_2->addWidget(statusLabel);

        countdownLabel = new QLabel(centralwidget);
        countdownLabel->setObjectName("countdownLabel");

        horizontalLayout_2->addWidget(countdownLabel);

        storageLabel = new QLabel(centralwidget);
        storageLabel->setObjectName("storageLabel");

        horizontalLayout_2->addWidget(storageLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\210\252\345\233\276\346\216\247\345\210\266", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\210\252\345\233\276\351\227\264\351\232\224\357\274\210\345\210\206\351\222\237\357\274\211:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\345\261\217\345\271\225:", nullptr));
        startCapture->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\350\207\252\345\212\250\346\210\252\345\233\276", nullptr));
        stopCapture->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\350\207\252\345\212\250\346\210\252\345\233\276", nullptr));
        manualCapture->setText(QCoreApplication::translate("MainWindow", "\347\253\213\345\215\263\346\210\252\345\233\276", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\344\277\235\345\255\230", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\350\267\257\345\276\204:", nullptr));
        selectFolder->setText(QCoreApplication::translate("MainWindow", "\346\265\217\350\247\210", nullptr));
        refreshList->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260\345\210\227\350\241\250", nullptr));
        deleteSelected->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\351\200\211\344\270\255", nullptr));
        deleteOldFiles->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\346\227\247\346\226\207\344\273\266", nullptr));
        settingsButton->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "\345\260\261\347\273\252", nullptr));
        countdownLabel->setText(QString());
        storageLabel->setText(QString());
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
