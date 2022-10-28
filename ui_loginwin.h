/********************************************************************************
** Form generated from reading UI file 'loginwin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIN_H
#define UI_LOGINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "verificationcodelabel.h"

QT_BEGIN_NAMESPACE

class Ui_LoginWin
{
public:
    QPushButton *BtnOK;
    QPushButton *BtnCancel;
    QLabel *labusrname;
    QPushButton *BtnRgs;
    QLineEdit *Editusrid;
    QLineEdit *Editusrpwd;
    QLabel *labusrpwd;
    QLabel *labusrname_2;
    QLineEdit *EditVfcd;
    VerificationCodeLabel *LabVfcd;
    QLabel *label;

    void setupUi(QWidget *LoginWin)
    {
        if (LoginWin->objectName().isEmpty())
            LoginWin->setObjectName(QStringLiteral("LoginWin"));
        LoginWin->resize(430, 288);
        BtnOK = new QPushButton(LoginWin);
        BtnOK->setObjectName(QStringLiteral("BtnOK"));
        BtnOK->setGeometry(QRect(50, 220, 89, 25));
        BtnCancel = new QPushButton(LoginWin);
        BtnCancel->setObjectName(QStringLiteral("BtnCancel"));
        BtnCancel->setGeometry(QRect(270, 220, 89, 25));
        labusrname = new QLabel(LoginWin);
        labusrname->setObjectName(QStringLiteral("labusrname"));
        labusrname->setGeometry(QRect(60, 80, 67, 17));
        BtnRgs = new QPushButton(LoginWin);
        BtnRgs->setObjectName(QStringLiteral("BtnRgs"));
        BtnRgs->setGeometry(QRect(160, 220, 89, 25));
        Editusrid = new QLineEdit(LoginWin);
        Editusrid->setObjectName(QStringLiteral("Editusrid"));
        Editusrid->setGeometry(QRect(150, 70, 191, 31));
        Editusrpwd = new QLineEdit(LoginWin);
        Editusrpwd->setObjectName(QStringLiteral("Editusrpwd"));
        Editusrpwd->setGeometry(QRect(150, 120, 191, 31));
        labusrpwd = new QLabel(LoginWin);
        labusrpwd->setObjectName(QStringLiteral("labusrpwd"));
        labusrpwd->setGeometry(QRect(60, 130, 67, 17));
        labusrname_2 = new QLabel(LoginWin);
        labusrname_2->setObjectName(QStringLiteral("labusrname_2"));
        labusrname_2->setGeometry(QRect(60, 180, 67, 17));
        EditVfcd = new QLineEdit(LoginWin);
        EditVfcd->setObjectName(QStringLiteral("EditVfcd"));
        EditVfcd->setGeometry(QRect(150, 170, 101, 31));
        LabVfcd = new VerificationCodeLabel(LoginWin);
        LabVfcd->setObjectName(QStringLiteral("LabVfcd"));
        LabVfcd->setGeometry(QRect(270, 176, 71, 31));
        label = new QLabel(LoginWin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 130, 31, 17));

        retranslateUi(LoginWin);

        QMetaObject::connectSlotsByName(LoginWin);
    } // setupUi

    void retranslateUi(QWidget *LoginWin)
    {
        LoginWin->setWindowTitle(QApplication::translate("LoginWin", "Form", Q_NULLPTR));
        BtnOK->setText(QApplication::translate("LoginWin", "\347\231\273\345\275\225", Q_NULLPTR));
        BtnCancel->setText(QApplication::translate("LoginWin", "\345\217\226\346\266\210", Q_NULLPTR));
        labusrname->setText(QApplication::translate("LoginWin", "\345\270\220\345\217\267", Q_NULLPTR));
        BtnRgs->setText(QApplication::translate("LoginWin", "\346\263\250\345\206\214", Q_NULLPTR));
        labusrpwd->setText(QApplication::translate("LoginWin", "\345\257\206\347\240\201", Q_NULLPTR));
        labusrname_2->setText(QApplication::translate("LoginWin", "\351\252\214\350\257\201\347\240\201", Q_NULLPTR));
        LabVfcd->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWin: public Ui_LoginWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIN_H
