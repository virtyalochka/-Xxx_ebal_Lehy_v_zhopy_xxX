/********************************************************************************
** Form generated from reading UI file 'authorize.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORIZE_H
#define UI_AUTHORIZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Authorize
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_Password;
    QLineEdit *lineEdit_Login;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Auth;
    QPushButton *pushButton_Reg;

    void setupUi(QDialog *Authorize)
    {
        if (Authorize->objectName().isEmpty())
            Authorize->setObjectName(QString::fromUtf8("Authorize"));
        Authorize->resize(754, 483);
        verticalLayoutWidget_2 = new QWidget(Authorize);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(60, 170, 621, 121));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit_Password = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_Password->setObjectName(QString::fromUtf8("lineEdit_Password"));

        verticalLayout->addWidget(lineEdit_Password);

        lineEdit_Login = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_Login->setObjectName(QString::fromUtf8("lineEdit_Login"));

        verticalLayout->addWidget(lineEdit_Login);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_Auth = new QPushButton(verticalLayoutWidget_2);
        pushButton_Auth->setObjectName(QString::fromUtf8("pushButton_Auth"));

        horizontalLayout->addWidget(pushButton_Auth);

        pushButton_Reg = new QPushButton(verticalLayoutWidget_2);
        pushButton_Reg->setObjectName(QString::fromUtf8("pushButton_Reg"));

        horizontalLayout->addWidget(pushButton_Reg);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Authorize);

        QMetaObject::connectSlotsByName(Authorize);
    } // setupUi

    void retranslateUi(QDialog *Authorize)
    {
        Authorize->setWindowTitle(QApplication::translate("Authorize", "Dialog", nullptr));
        lineEdit_Password->setPlaceholderText(QApplication::translate("Authorize", "Password", nullptr));
        lineEdit_Login->setInputMask(QString());
        lineEdit_Login->setPlaceholderText(QApplication::translate("Authorize", "Login", nullptr));
        pushButton_Auth->setText(QApplication::translate("Authorize", "\320\236\320\272", nullptr));
        pushButton_Reg->setText(QApplication::translate("Authorize", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Authorize: public Ui_Authorize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZE_H
