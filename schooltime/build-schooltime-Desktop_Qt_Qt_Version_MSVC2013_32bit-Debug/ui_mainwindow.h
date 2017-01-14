/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *openArrivalButton;
    QPushButton *openDepartureButton;
    QLineEdit *openArrivalEdit;
    QLineEdit *openDepartureEdit;
    QLabel *label;
    QLineEdit *hourslineEdit;
    QLineEdit *minuteslineEdit;
    QPushButton *computeButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(393, 198);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openArrivalButton = new QPushButton(centralWidget);
        openArrivalButton->setObjectName(QStringLiteral("openArrivalButton"));
        openArrivalButton->setGeometry(QRect(260, 10, 121, 23));
        openDepartureButton = new QPushButton(centralWidget);
        openDepartureButton->setObjectName(QStringLiteral("openDepartureButton"));
        openDepartureButton->setGeometry(QRect(260, 40, 121, 23));
        openArrivalEdit = new QLineEdit(centralWidget);
        openArrivalEdit->setObjectName(QStringLiteral("openArrivalEdit"));
        openArrivalEdit->setGeometry(QRect(10, 10, 241, 20));
        openDepartureEdit = new QLineEdit(centralWidget);
        openDepartureEdit->setObjectName(QStringLiteral("openDepartureEdit"));
        openDepartureEdit->setGeometry(QRect(10, 40, 241, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 120, 301, 16));
        hourslineEdit = new QLineEdit(centralWidget);
        hourslineEdit->setObjectName(QStringLiteral("hourslineEdit"));
        hourslineEdit->setGeometry(QRect(160, 120, 31, 20));
        hourslineEdit->setReadOnly(true);
        minuteslineEdit = new QLineEdit(centralWidget);
        minuteslineEdit->setObjectName(QStringLiteral("minuteslineEdit"));
        minuteslineEdit->setGeometry(QRect(230, 120, 31, 20));
        minuteslineEdit->setReadOnly(true);
        computeButton = new QPushButton(centralWidget);
        computeButton->setObjectName(QStringLiteral("computeButton"));
        computeButton->setGeometry(QRect(50, 70, 161, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 393, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        openArrivalButton->setText(QApplication::translate("MainWindow", "Open Arrival Times", 0));
        openDepartureButton->setText(QApplication::translate("MainWindow", "Open Departure Times", 0));
        label->setText(QApplication::translate("MainWindow", "Your average time at school is              hours,             minutes", 0));
        computeButton->setText(QApplication::translate("MainWindow", "Compute!", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
