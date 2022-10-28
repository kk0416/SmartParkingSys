/********************************************************************************
** Form generated from reading UI file 'teststacked.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTSTACKED_H
#define UI_TESTSTACKED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_teststacked
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QPushButton *pushButton;
    QWidget *page_2;
    QStackedWidget *stackedWidget_2;
    QWidget *page_3;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QWidget *page_4;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *teststacked)
    {
        if (teststacked->objectName().isEmpty())
            teststacked->setObjectName(QStringLiteral("teststacked"));
        teststacked->resize(810, 499);
        stackedWidget = new QStackedWidget(teststacked);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(70, 60, 601, 381));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 110, 67, 17));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(330, 20, 89, 25));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget_2 = new QStackedWidget(page_2);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(30, 60, 561, 281));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        pushButton_2 = new QPushButton(page_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 20, 89, 25));
        label_2 = new QLabel(page_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 110, 67, 17));
        stackedWidget_2->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        label_3 = new QLabel(page_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(200, 100, 67, 17));
        stackedWidget_2->addWidget(page_4);
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 20, 89, 25));
        pushButton_4 = new QPushButton(page_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(130, 30, 89, 25));
        stackedWidget->addWidget(page_2);

        retranslateUi(teststacked);

        stackedWidget->setCurrentIndex(1);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(teststacked);
    } // setupUi

    void retranslateUi(QWidget *teststacked)
    {
        teststacked->setWindowTitle(QApplication::translate("teststacked", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("teststacked", "1", Q_NULLPTR));
        pushButton->setText(QApplication::translate("teststacked", "to2", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("teststacked", "to1", Q_NULLPTR));
        label_2->setText(QApplication::translate("teststacked", "2", Q_NULLPTR));
        label_3->setText(QApplication::translate("teststacked", "22", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("teststacked", "t22", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("teststacked", "t21", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class teststacked: public Ui_teststacked {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSTACKED_H
