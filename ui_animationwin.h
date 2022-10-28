/********************************************************************************
** Form generated from reading UI file 'animationwin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMATIONWIN_H
#define UI_ANIMATIONWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnimationWin
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *AnimationWin)
    {
        if (AnimationWin->objectName().isEmpty())
            AnimationWin->setObjectName(QStringLiteral("AnimationWin"));
        AnimationWin->resize(652, 426);
        verticalLayoutWidget = new QWidget(AnimationWin);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 30, 541, 361));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(AnimationWin);

        QMetaObject::connectSlotsByName(AnimationWin);
    } // setupUi

    void retranslateUi(QWidget *AnimationWin)
    {
        AnimationWin->setWindowTitle(QApplication::translate("AnimationWin", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AnimationWin: public Ui_AnimationWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMATIONWIN_H
