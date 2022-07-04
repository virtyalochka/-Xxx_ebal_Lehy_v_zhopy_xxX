/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Task1;
    QAction *action_Task2;
    QAction *action_Task3;
    QAction *action_Task4;
    QAction *action_Exit;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Task1;
    QPushButton *pushButton_Task2;
    QPushButton *pushButton_Task4;
    QPushButton *pushButton_Task3;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_Statistics;
    QPushButton *pushButton_Exit;
    QMenuBar *menubar;
    QMenu *menu_main;
    QMenu *menu_about;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        action_Task1 = new QAction(MainWindow);
        action_Task1->setObjectName(QString::fromUtf8("action_Task1"));
        action_Task2 = new QAction(MainWindow);
        action_Task2->setObjectName(QString::fromUtf8("action_Task2"));
        action_Task3 = new QAction(MainWindow);
        action_Task3->setObjectName(QString::fromUtf8("action_Task3"));
        action_Task4 = new QAction(MainWindow);
        action_Task4->setObjectName(QString::fromUtf8("action_Task4"));
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QString::fromUtf8("action_Exit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(50, 130, 691, 271));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_Task1 = new QPushButton(verticalLayoutWidget_2);
        pushButton_Task1->setObjectName(QString::fromUtf8("pushButton_Task1"));

        horizontalLayout->addWidget(pushButton_Task1);

        pushButton_Task2 = new QPushButton(verticalLayoutWidget_2);
        pushButton_Task2->setObjectName(QString::fromUtf8("pushButton_Task2"));

        horizontalLayout->addWidget(pushButton_Task2);

        pushButton_Task4 = new QPushButton(verticalLayoutWidget_2);
        pushButton_Task4->setObjectName(QString::fromUtf8("pushButton_Task4"));

        horizontalLayout->addWidget(pushButton_Task4);

        pushButton_Task3 = new QPushButton(verticalLayoutWidget_2);
        pushButton_Task3->setObjectName(QString::fromUtf8("pushButton_Task3"));

        horizontalLayout->addWidget(pushButton_Task3);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_Statistics = new QPushButton(verticalLayoutWidget_2);
        pushButton_Statistics->setObjectName(QString::fromUtf8("pushButton_Statistics"));

        verticalLayout->addWidget(pushButton_Statistics);

        pushButton_Exit = new QPushButton(verticalLayoutWidget_2);
        pushButton_Exit->setObjectName(QString::fromUtf8("pushButton_Exit"));

        verticalLayout->addWidget(pushButton_Exit);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu_main = new QMenu(menubar);
        menu_main->setObjectName(QString::fromUtf8("menu_main"));
        menu_about = new QMenu(menubar);
        menu_about->setObjectName(QString::fromUtf8("menu_about"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_main->menuAction());
        menubar->addAction(menu_about->menuAction());
        menu_main->addAction(action_Task1);
        menu_main->addAction(action_Task2);
        menu_main->addAction(action_Task3);
        menu_main->addAction(action_Task4);
        menu_main->addSeparator();
        menu_main->addAction(action_Exit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_Task1->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260 1", nullptr));
        action_Task2->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260 2", nullptr));
        action_Task3->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260 3", nullptr));
        action_Task4->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260 4", nullptr));
        action_Exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        pushButton_Task1->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260 1", nullptr));
        pushButton_Task2->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260 2", nullptr));
        pushButton_Task4->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260 3", nullptr));
        pushButton_Task3->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260 4", nullptr));
        pushButton_Statistics->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\321\203", nullptr));
        pushButton_Exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        menu_main->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
        menu_about->setTitle(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
