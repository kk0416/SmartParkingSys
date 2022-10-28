/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *EditStore;
    QLineEdit *EditPort;
    QLabel *label_9;
    QPushButton *BtnPicAdrs;
    QLineEdit *EditVdAdrs;
    QLineEdit *EditIP;
    QLabel *label_7;
    QLineEdit *EditPicAdrs;
    QPushButton *BtnVdAdrs;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *LabPort;
    QLabel *label_12;
    QLabel *label_10;
    QPushButton *BtnOK;
    QPushButton *BtnReturn;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(647, 468);
        gridLayoutWidget_2 = new QWidget(Settings);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(50, 50, 531, 321));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        EditStore = new QLineEdit(gridLayoutWidget_2);
        EditStore->setObjectName(QStringLiteral("EditStore"));

        gridLayout_2->addWidget(EditStore, 5, 2, 1, 1);

        EditPort = new QLineEdit(gridLayoutWidget_2);
        EditPort->setObjectName(QStringLiteral("EditPort"));

        gridLayout_2->addWidget(EditPort, 2, 2, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 4, 0, 1, 1);

        BtnPicAdrs = new QPushButton(gridLayoutWidget_2);
        BtnPicAdrs->setObjectName(QStringLiteral("BtnPicAdrs"));

        gridLayout_2->addWidget(BtnPicAdrs, 3, 3, 1, 1);

        EditVdAdrs = new QLineEdit(gridLayoutWidget_2);
        EditVdAdrs->setObjectName(QStringLiteral("EditVdAdrs"));

        gridLayout_2->addWidget(EditVdAdrs, 4, 2, 1, 1);

        EditIP = new QLineEdit(gridLayoutWidget_2);
        EditIP->setObjectName(QStringLiteral("EditIP"));

        gridLayout_2->addWidget(EditIP, 1, 2, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        EditPicAdrs = new QLineEdit(gridLayoutWidget_2);
        EditPicAdrs->setObjectName(QStringLiteral("EditPicAdrs"));

        gridLayout_2->addWidget(EditPicAdrs, 3, 2, 1, 1);

        BtnVdAdrs = new QPushButton(gridLayoutWidget_2);
        BtnVdAdrs->setObjectName(QStringLiteral("BtnVdAdrs"));

        gridLayout_2->addWidget(BtnVdAdrs, 4, 3, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 5, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 3, 0, 1, 1);

        LabPort = new QLabel(gridLayoutWidget_2);
        LabPort->setObjectName(QStringLiteral("LabPort"));

        gridLayout_2->addWidget(LabPort, 2, 0, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 5, 3, 1, 1);

        label_10 = new QLabel(Settings);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(240, 10, 191, 31));
        BtnOK = new QPushButton(Settings);
        BtnOK->setObjectName(QStringLiteral("BtnOK"));
        BtnOK->setGeometry(QRect(120, 400, 89, 41));
        BtnReturn = new QPushButton(Settings);
        BtnReturn->setObjectName(QStringLiteral("BtnReturn"));
        BtnReturn->setGeometry(QRect(400, 400, 89, 41));

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Form", Q_NULLPTR));
        label_9->setText(QApplication::translate("Settings", "\350\247\206\351\242\221\345\275\225\345\210\266\344\277\235\345\255\230\345\234\260\345\235\200", Q_NULLPTR));
        BtnPicAdrs->setText(QApplication::translate("Settings", "...", Q_NULLPTR));
        label_7->setText(QApplication::translate("Settings", "\346\234\215\345\212\241\345\231\250ip\345\234\260\345\235\200", Q_NULLPTR));
        BtnVdAdrs->setText(QApplication::translate("Settings", "...", Q_NULLPTR));
        label_11->setText(QApplication::translate("Settings", "\346\234\254\345\234\260\347\263\273\347\273\237\345\255\230\345\202\250\345\244\247\345\260\217", Q_NULLPTR));
        label_8->setText(QApplication::translate("Settings", "\350\275\246\347\211\214\345\233\276\347\211\207\344\277\235\345\255\230\345\234\260\345\235\200", Q_NULLPTR));
        LabPort->setText(QApplication::translate("Settings", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        label_12->setText(QApplication::translate("Settings", "       GB", Q_NULLPTR));
        label_10->setText(QApplication::translate("Settings", "\346\231\272\346\205\247\345\201\234\350\275\246\347\263\273\347\273\237\350\256\276\347\275\256\347\225\214\351\235\242", Q_NULLPTR));
        BtnOK->setText(QApplication::translate("Settings", "\347\241\256\345\256\232", Q_NULLPTR));
        BtnReturn->setText(QApplication::translate("Settings", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
