/********************************************************************************
** Form generated from reading UI file 'rgswin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RGSWIN_H
#define UI_RGSWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RgsWin
{
public:
    QLineEdit *Editusrpwd1;
    QLabel *labTitle;
    QLineEdit *Editusrname;
    QPushButton *BtnCancel;
    QLabel *labusrname;
    QLabel *labusrpwd;
    QPushButton *BtnOK;
    QLabel *labusrpwd1;
    QLineEdit *Editusrid;
    QLabel *labusrid;
    QLineEdit *Editusrpwd;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *RgsWin)
    {
        if (RgsWin->objectName().isEmpty())
            RgsWin->setObjectName(QStringLiteral("RgsWin"));
        RgsWin->resize(469, 371);
        Editusrpwd1 = new QLineEdit(RgsWin);
        Editusrpwd1->setObjectName(QStringLiteral("Editusrpwd1"));
        Editusrpwd1->setGeometry(QRect(160, 240, 191, 31));
        labTitle = new QLabel(RgsWin);
        labTitle->setObjectName(QStringLiteral("labTitle"));
        labTitle->setGeometry(QRect(200, 40, 67, 17));
        Editusrname = new QLineEdit(RgsWin);
        Editusrname->setObjectName(QStringLiteral("Editusrname"));
        Editusrname->setGeometry(QRect(160, 140, 191, 31));
        BtnCancel = new QPushButton(RgsWin);
        BtnCancel->setObjectName(QStringLiteral("BtnCancel"));
        BtnCancel->setGeometry(QRect(280, 290, 89, 25));
        labusrname = new QLabel(RgsWin);
        labusrname->setObjectName(QStringLiteral("labusrname"));
        labusrname->setGeometry(QRect(70, 150, 67, 17));
        labusrpwd = new QLabel(RgsWin);
        labusrpwd->setObjectName(QStringLiteral("labusrpwd"));
        labusrpwd->setGeometry(QRect(70, 200, 67, 17));
        BtnOK = new QPushButton(RgsWin);
        BtnOK->setObjectName(QStringLiteral("BtnOK"));
        BtnOK->setGeometry(QRect(60, 290, 89, 25));
        labusrpwd1 = new QLabel(RgsWin);
        labusrpwd1->setObjectName(QStringLiteral("labusrpwd1"));
        labusrpwd1->setGeometry(QRect(70, 250, 67, 17));
        Editusrid = new QLineEdit(RgsWin);
        Editusrid->setObjectName(QStringLiteral("Editusrid"));
        Editusrid->setGeometry(QRect(160, 90, 191, 31));
        labusrid = new QLabel(RgsWin);
        labusrid->setObjectName(QStringLiteral("labusrid"));
        labusrid->setGeometry(QRect(70, 100, 67, 17));
        Editusrpwd = new QLineEdit(RgsWin);
        Editusrpwd->setObjectName(QStringLiteral("Editusrpwd"));
        Editusrpwd->setGeometry(QRect(160, 190, 191, 31));
        label = new QLabel(RgsWin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 200, 31, 20));
        label_2 = new QLabel(RgsWin);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 250, 31, 20));

        retranslateUi(RgsWin);

        QMetaObject::connectSlotsByName(RgsWin);
    } // setupUi

    void retranslateUi(QWidget *RgsWin)
    {
        RgsWin->setWindowTitle(QApplication::translate("RgsWin", "Form", Q_NULLPTR));
        labTitle->setText(QApplication::translate("RgsWin", "\347\224\250\346\210\267\346\263\250\345\206\214", Q_NULLPTR));
        BtnCancel->setText(QApplication::translate("RgsWin", "\345\217\226\346\266\210", Q_NULLPTR));
        labusrname->setText(QApplication::translate("RgsWin", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        labusrpwd->setText(QApplication::translate("RgsWin", "\345\257\206\347\240\201", Q_NULLPTR));
        BtnOK->setText(QApplication::translate("RgsWin", "\347\241\256\345\256\232", Q_NULLPTR));
        labusrpwd1->setText(QApplication::translate("RgsWin", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        labusrid->setText(QApplication::translate("RgsWin", "\345\270\220\345\217\267", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RgsWin: public Ui_RgsWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RGSWIN_H
