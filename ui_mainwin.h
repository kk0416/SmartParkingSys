/********************************************************************************
** Form generated from reading UI file 'mainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWin
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *page_13;
    QLabel *LabInImg;
    QLabel *label_24;
    QLabel *label_26;
    QLineEdit *EditInTime;
    QLabel *LabInCarNumImg;
    QLabel *label_27;
    QLineEdit *EditInCarNum;
    QPushButton *BtnInGetCarNum;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *BtnOut_6;
    QPushButton *BtnMngParkn_6;
    QPushButton *BtnQueryCar_6;
    QPushButton *BtnSettings_6;
    QLabel *label_23;
    QTableWidget *tableWidget;
    QWidget *page_15;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLineEdit *EditOuttime;
    QLabel *LabOutImg;
    QLineEdit *EditCarNum;
    QLabel *LabOCarNumimg;
    QLabel *label_19;
    QLabel *LabInTime;
    QLabel *label_34;
    QLabel *LabAllTime;
    QLabel *label_36;
    QLabel *LabCharge;
    QPushButton *BtnOGetCarNum;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *BtnIn_2;
    QPushButton *BtnMngParkn_7;
    QPushButton *BtnQueryCar_7;
    QPushButton *BtnSettings_7;
    QLabel *label_25;
    QCheckBox *ckBox_ism;
    QPushButton *BtnGo;
    QWidget *page_14;
    QLabel *LabParkimg;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *BtnIn;
    QPushButton *BtnOut_5;
    QPushButton *BtnQueryCar_5;
    QPushButton *BtnSettings_5;
    QLabel *label_20;
    QPushButton *pushButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QCheckBox *checkBox;
    QWidget *page;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QTreeWidget *treeWidget;
    QListWidget *listWidget;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *pushButton_11;
    QLabel *label_53;
    QPushButton *pushButton_12;
    QWidget *page_2;
    QPushButton *pushButton_20;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QLabel *label_11;
    QComboBox *comboBox;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLabel *label_8;
    QProgressBar *progressBar;
    QLabel *label_7;
    QPushButton *pushButton_19;
    QWidget *page_3;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_13;
    QLineEdit *Editsrchcarnum;
    QLabel *label_12;
    QLineEdit *Editsrchintime;
    QLabel *label_14;
    QLineEdit *Editserchoutime;
    QPushButton *BtnSerchCarinfo;
    QTableWidget *tableWidget_2;
    QPushButton *BtnDataOut;
    QPushButton *BtnRetnMain;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_22;
    QLabel *label_21;
    QLabel *LabCurrentTime;

    void setupUi(QWidget *MainWin)
    {
        if (MainWin->objectName().isEmpty())
            MainWin->setObjectName(QStringLiteral("MainWin"));
        MainWin->resize(773, 569);
        verticalLayoutWidget = new QWidget(MainWin);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 30, 731, 521));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(verticalLayoutWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page_13 = new QWidget();
        page_13->setObjectName(QStringLiteral("page_13"));
        LabInImg = new QLabel(page_13);
        LabInImg->setObjectName(QStringLiteral("LabInImg"));
        LabInImg->setGeometry(QRect(0, 50, 481, 401));
        label_24 = new QLabel(page_13);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(510, 50, 269, 42));
        label_26 = new QLabel(page_13);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(510, 130, 81, 41));
        EditInTime = new QLineEdit(page_13);
        EditInTime->setObjectName(QStringLiteral("EditInTime"));
        EditInTime->setGeometry(QRect(510, 80, 171, 41));
        LabInCarNumImg = new QLabel(page_13);
        LabInCarNumImg->setObjectName(QStringLiteral("LabInCarNumImg"));
        LabInCarNumImg->setGeometry(QRect(510, 180, 171, 41));
        label_27 = new QLabel(page_13);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(510, 230, 67, 17));
        EditInCarNum = new QLineEdit(page_13);
        EditInCarNum->setObjectName(QStringLiteral("EditInCarNum"));
        EditInCarNum->setGeometry(QRect(510, 250, 171, 41));
        BtnInGetCarNum = new QPushButton(page_13);
        BtnInGetCarNum->setObjectName(QStringLiteral("BtnInGetCarNum"));
        BtnInGetCarNum->setGeometry(QRect(590, 130, 89, 41));
        layoutWidget = new QWidget(page_13);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 731, 33));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        BtnOut_6 = new QPushButton(layoutWidget);
        BtnOut_6->setObjectName(QStringLiteral("BtnOut_6"));

        horizontalLayout_12->addWidget(BtnOut_6);

        BtnMngParkn_6 = new QPushButton(layoutWidget);
        BtnMngParkn_6->setObjectName(QStringLiteral("BtnMngParkn_6"));

        horizontalLayout_12->addWidget(BtnMngParkn_6);

        BtnQueryCar_6 = new QPushButton(layoutWidget);
        BtnQueryCar_6->setObjectName(QStringLiteral("BtnQueryCar_6"));

        horizontalLayout_12->addWidget(BtnQueryCar_6);

        BtnSettings_6 = new QPushButton(layoutWidget);
        BtnSettings_6->setObjectName(QStringLiteral("BtnSettings_6"));

        horizontalLayout_12->addWidget(BtnSettings_6);

        label_23 = new QLabel(layoutWidget);
        label_23->setObjectName(QStringLiteral("label_23"));

        horizontalLayout_12->addWidget(label_23);

        tableWidget = new QTableWidget(page_13);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem7);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(490, 300, 201, 181));
        stackedWidget->addWidget(page_13);
        page_15 = new QWidget();
        page_15->setObjectName(QStringLiteral("page_15"));
        label_28 = new QLabel(page_15);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(530, 130, 81, 41));
        label_29 = new QLabel(page_15);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(530, 230, 67, 17));
        label_30 = new QLabel(page_15);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(530, 50, 191, 42));
        EditOuttime = new QLineEdit(page_15);
        EditOuttime->setObjectName(QStringLiteral("EditOuttime"));
        EditOuttime->setGeometry(QRect(530, 90, 181, 31));
        LabOutImg = new QLabel(page_15);
        LabOutImg->setObjectName(QStringLiteral("LabOutImg"));
        LabOutImg->setGeometry(QRect(10, 60, 501, 401));
        EditCarNum = new QLineEdit(page_15);
        EditCarNum->setObjectName(QStringLiteral("EditCarNum"));
        EditCarNum->setGeometry(QRect(530, 250, 191, 41));
        LabOCarNumimg = new QLabel(page_15);
        LabOCarNumimg->setObjectName(QStringLiteral("LabOCarNumimg"));
        LabOCarNumimg->setGeometry(QRect(530, 170, 161, 41));
        label_19 = new QLabel(page_15);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(530, 320, 67, 17));
        LabInTime = new QLabel(page_15);
        LabInTime->setObjectName(QStringLiteral("LabInTime"));
        LabInTime->setGeometry(QRect(610, 320, 111, 21));
        label_34 = new QLabel(page_15);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(530, 350, 67, 17));
        LabAllTime = new QLabel(page_15);
        LabAllTime->setObjectName(QStringLiteral("LabAllTime"));
        LabAllTime->setGeometry(QRect(610, 350, 111, 21));
        label_36 = new QLabel(page_15);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(530, 390, 67, 17));
        LabCharge = new QLabel(page_15);
        LabCharge->setObjectName(QStringLiteral("LabCharge"));
        LabCharge->setGeometry(QRect(590, 390, 67, 17));
        BtnOGetCarNum = new QPushButton(page_15);
        BtnOGetCarNum->setObjectName(QStringLiteral("BtnOGetCarNum"));
        BtnOGetCarNum->setGeometry(QRect(610, 130, 89, 31));
        layoutWidget_2 = new QWidget(page_15);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 0, 731, 33));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        BtnIn_2 = new QPushButton(layoutWidget_2);
        BtnIn_2->setObjectName(QStringLiteral("BtnIn_2"));

        horizontalLayout_13->addWidget(BtnIn_2);

        BtnMngParkn_7 = new QPushButton(layoutWidget_2);
        BtnMngParkn_7->setObjectName(QStringLiteral("BtnMngParkn_7"));

        horizontalLayout_13->addWidget(BtnMngParkn_7);

        BtnQueryCar_7 = new QPushButton(layoutWidget_2);
        BtnQueryCar_7->setObjectName(QStringLiteral("BtnQueryCar_7"));

        horizontalLayout_13->addWidget(BtnQueryCar_7);

        BtnSettings_7 = new QPushButton(layoutWidget_2);
        BtnSettings_7->setObjectName(QStringLiteral("BtnSettings_7"));

        horizontalLayout_13->addWidget(BtnSettings_7);

        label_25 = new QLabel(layoutWidget_2);
        label_25->setObjectName(QStringLiteral("label_25"));

        horizontalLayout_13->addWidget(label_25);

        ckBox_ism = new QCheckBox(page_15);
        ckBox_ism->setObjectName(QStringLiteral("ckBox_ism"));
        ckBox_ism->setGeometry(QRect(530, 440, 101, 23));
        BtnGo = new QPushButton(page_15);
        BtnGo->setObjectName(QStringLiteral("BtnGo"));
        BtnGo->setGeometry(QRect(630, 430, 89, 41));
        stackedWidget->addWidget(page_15);
        page_14 = new QWidget();
        page_14->setObjectName(QStringLiteral("page_14"));
        LabParkimg = new QLabel(page_14);
        LabParkimg->setObjectName(QStringLiteral("LabParkimg"));
        LabParkimg->setGeometry(QRect(0, 60, 511, 401));
        layoutWidget1 = new QWidget(page_14);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 731, 33));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        BtnIn = new QPushButton(layoutWidget1);
        BtnIn->setObjectName(QStringLiteral("BtnIn"));

        horizontalLayout_10->addWidget(BtnIn);

        BtnOut_5 = new QPushButton(layoutWidget1);
        BtnOut_5->setObjectName(QStringLiteral("BtnOut_5"));

        horizontalLayout_10->addWidget(BtnOut_5);

        BtnQueryCar_5 = new QPushButton(layoutWidget1);
        BtnQueryCar_5->setObjectName(QStringLiteral("BtnQueryCar_5"));

        horizontalLayout_10->addWidget(BtnQueryCar_5);

        BtnSettings_5 = new QPushButton(layoutWidget1);
        BtnSettings_5->setObjectName(QStringLiteral("BtnSettings_5"));

        horizontalLayout_10->addWidget(BtnSettings_5);

        label_20 = new QLabel(layoutWidget1);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_10->addWidget(label_20);

        pushButton = new QPushButton(page_14);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(520, 60, 121, 31));
        gridLayoutWidget = new QWidget(page_14);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(530, 140, 191, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 1, 1, 1);

        verticalLayoutWidget_2 = new QWidget(page_14);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(540, 280, 181, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(verticalLayoutWidget_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(verticalLayoutWidget_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        checkBox = new QCheckBox(verticalLayoutWidget_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout->addWidget(checkBox);

        stackedWidget->addWidget(page_14);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        horizontalLayoutWidget = new QWidget(page);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 721, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QFont font;
        font.setFamily(QStringLiteral("AR PL UKai TW MBE"));
        font.setPointSize(15);
        font.setBold(false);
        font.setWeight(50);
        font.setKerning(true);
        pushButton_2->setFont(font);

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QFont font1;
        font1.setFamily(QStringLiteral("AR PL UKai TW"));
        font1.setPointSize(15);
        pushButton_3->setFont(font1);

        horizontalLayout->addWidget(pushButton_3);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        verticalLayoutWidget_3 = new QWidget(page);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 80, 191, 411));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radioButton = new QRadioButton(verticalLayoutWidget_3);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        horizontalLayout_2->addWidget(radioButton);

        radioButton_2 = new QRadioButton(verticalLayoutWidget_3);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout_2->addWidget(radioButton_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        treeWidget = new QTreeWidget(verticalLayoutWidget_3);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setHeaderHidden(true);
        treeWidget->header()->setVisible(false);

        verticalLayout_2->addWidget(treeWidget);

        listWidget = new QListWidget(page);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(190, 120, 531, 321));
        horizontalLayoutWidget_3 = new QWidget(page);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(230, 450, 431, 41));
        horizontalLayout_18 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        pushButton_11 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        horizontalLayout_18->addWidget(pushButton_11);

        label_53 = new QLabel(horizontalLayoutWidget_3);
        label_53->setObjectName(QStringLiteral("label_53"));
        label_53->setLayoutDirection(Qt::LeftToRight);
        label_53->setAlignment(Qt::AlignCenter);

        horizontalLayout_18->addWidget(label_53);

        pushButton_12 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        horizontalLayout_18->addWidget(pushButton_12);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        pushButton_20 = new QPushButton(page_2);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setGeometry(QRect(10, 0, 41, 41));
        horizontalLayoutWidget_5 = new QWidget(page_2);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(550, 430, 121, 41));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(horizontalLayoutWidget_5);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_5->addWidget(label_10);

        label_11 = new QLabel(horizontalLayoutWidget_5);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_5->addWidget(label_11);

        comboBox = new QComboBox(page_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(410, 430, 111, 41));
        horizontalLayoutWidget_4 = new QWidget(page_2);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(90, 430, 121, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(horizontalLayoutWidget_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_4->addWidget(label_9);

        label_8 = new QLabel(horizontalLayoutWidget_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        progressBar = new QProgressBar(page_2);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(90, 390, 581, 23));
        progressBar->setValue(24);
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(80, 10, 561, 341));
        pushButton_19 = new QPushButton(page_2);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(270, 430, 89, 41));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        horizontalLayoutWidget_6 = new QWidget(page_3);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(0, 0, 721, 51));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(horizontalLayoutWidget_6);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_6->addWidget(label_13);

        Editsrchcarnum = new QLineEdit(horizontalLayoutWidget_6);
        Editsrchcarnum->setObjectName(QStringLiteral("Editsrchcarnum"));

        horizontalLayout_6->addWidget(Editsrchcarnum);

        label_12 = new QLabel(horizontalLayoutWidget_6);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_6->addWidget(label_12);

        Editsrchintime = new QLineEdit(horizontalLayoutWidget_6);
        Editsrchintime->setObjectName(QStringLiteral("Editsrchintime"));

        horizontalLayout_6->addWidget(Editsrchintime);

        label_14 = new QLabel(horizontalLayoutWidget_6);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_6->addWidget(label_14);

        Editserchoutime = new QLineEdit(horizontalLayoutWidget_6);
        Editserchoutime->setObjectName(QStringLiteral("Editserchoutime"));

        horizontalLayout_6->addWidget(Editserchoutime);

        BtnSerchCarinfo = new QPushButton(horizontalLayoutWidget_6);
        BtnSerchCarinfo->setObjectName(QStringLiteral("BtnSerchCarinfo"));

        horizontalLayout_6->addWidget(BtnSerchCarinfo);

        tableWidget_2 = new QTableWidget(page_3);
        if (tableWidget_2->columnCount() < 7)
            tableWidget_2->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem14);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(10, 70, 711, 361));
        BtnDataOut = new QPushButton(page_3);
        BtnDataOut->setObjectName(QStringLiteral("BtnDataOut"));
        BtnDataOut->setGeometry(QRect(10, 440, 89, 31));
        BtnRetnMain = new QPushButton(page_3);
        BtnRetnMain->setObjectName(QStringLiteral("BtnRetnMain"));
        BtnRetnMain->setGeometry(QRect(610, 440, 89, 31));
        stackedWidget->addWidget(page_3);

        verticalLayout_3->addWidget(stackedWidget);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_22 = new QLabel(verticalLayoutWidget);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_11->addWidget(label_22);

        label_21 = new QLabel(verticalLayoutWidget);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_11->addWidget(label_21);

        LabCurrentTime = new QLabel(verticalLayoutWidget);
        LabCurrentTime->setObjectName(QStringLiteral("LabCurrentTime"));

        horizontalLayout_11->addWidget(LabCurrentTime);


        verticalLayout_3->addLayout(horizontalLayout_11);


        retranslateUi(MainWin);

        stackedWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(MainWin);
    } // setupUi

    void retranslateUi(QWidget *MainWin)
    {
        MainWin->setWindowTitle(QApplication::translate("MainWin", "Form", Q_NULLPTR));
        LabInImg->setText(QApplication::translate("MainWin", "\345\205\245\345\234\272\346\250\241\345\274\217", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWin", "\345\205\245\345\234\272\346\227\266\351\227\264", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWin", "\350\275\246\347\211\214\345\233\276\347\211\207", Q_NULLPTR));
        LabInCarNumImg->setText(QApplication::translate("MainWin", "\350\275\246\347\211\214\347\205\247\347\211\207", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWin", "\350\275\246\347\211\214\345\217\267\347\240\201", Q_NULLPTR));
        BtnInGetCarNum->setText(QApplication::translate("MainWin", "GetCarNum", Q_NULLPTR));
        BtnOut_6->setText(QApplication::translate("MainWin", "\345\207\272\345\234\272\346\250\241\345\274\217", Q_NULLPTR));
        BtnMngParkn_6->setText(QApplication::translate("MainWin", "\345\201\234\350\275\246\345\234\272\345\206\205\351\203\250\347\256\241\347\220\206", Q_NULLPTR));
        BtnQueryCar_6->setText(QApplication::translate("MainWin", "\350\275\246\350\276\206\344\277\241\346\201\257\346\237\245\350\257\242", Q_NULLPTR));
        BtnSettings_6->setText(QApplication::translate("MainWin", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWin", "\346\231\272\346\205\247\345\201\234\350\275\246\344\272\221\345\271\263\345\217\260\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWin", "\345\272\217\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWin", "\350\275\246\347\211\214\345\217\267\347\240\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWin", "\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWin", "\344\275\215\347\275\256", Q_NULLPTR));
        label_28->setText(QApplication::translate("MainWin", "\350\275\246\347\211\214\345\233\276\347\211\207", Q_NULLPTR));
        label_29->setText(QApplication::translate("MainWin", "\350\275\246\347\211\214\345\217\267\347\240\201", Q_NULLPTR));
        label_30->setText(QApplication::translate("MainWin", "\345\207\272\345\234\272\346\227\266\351\227\264", Q_NULLPTR));
        LabOutImg->setText(QApplication::translate("MainWin", "\345\207\272\345\234\272\346\250\241\345\274\217", Q_NULLPTR));
        LabOCarNumimg->setText(QApplication::translate("MainWin", "\350\275\246\347\211\214\347\205\247\347\211\207", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWin", "\345\205\245\345\234\272\346\227\266\351\227\264", Q_NULLPTR));
        LabInTime->setText(QString());
        label_34->setText(QApplication::translate("MainWin", "\345\201\234\350\275\246\346\227\266\351\225\277", Q_NULLPTR));
        LabAllTime->setText(QString());
        label_36->setText(QApplication::translate("MainWin", "\346\224\266\350\264\271\357\274\232", Q_NULLPTR));
        LabCharge->setText(QString());
        BtnOGetCarNum->setText(QApplication::translate("MainWin", "GetCarNum", Q_NULLPTR));
        BtnIn_2->setText(QApplication::translate("MainWin", "\345\205\245\345\234\272\346\250\241\345\274\217", Q_NULLPTR));
        BtnMngParkn_7->setText(QApplication::translate("MainWin", "\345\201\234\350\275\246\345\234\272\345\206\205\351\203\250\347\256\241\347\220\206", Q_NULLPTR));
        BtnQueryCar_7->setText(QApplication::translate("MainWin", "\350\275\246\350\276\206\344\277\241\346\201\257\346\237\245\350\257\242", Q_NULLPTR));
        BtnSettings_7->setText(QApplication::translate("MainWin", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWin", "\346\231\272\346\205\247\345\201\234\350\275\246\344\272\221\345\271\263\345\217\260\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        ckBox_ism->setText(QApplication::translate("MainWin", "\346\230\257\345\220\246\346\230\257\346\234\210\345\215\241", Q_NULLPTR));
        BtnGo->setText(QApplication::translate("MainWin", "\346\224\276\350\241\214", Q_NULLPTR));
        LabParkimg->setText(QApplication::translate("MainWin", "\345\201\234\350\275\246\345\234\272", Q_NULLPTR));
        BtnIn->setText(QApplication::translate("MainWin", "\345\205\245\345\234\272\346\250\241\345\274\217", Q_NULLPTR));
        BtnOut_5->setText(QApplication::translate("MainWin", "\345\207\272\345\234\272\346\250\241\345\274\217", Q_NULLPTR));
        BtnQueryCar_5->setText(QApplication::translate("MainWin", "\350\275\246\350\276\206\344\277\241\346\201\257\346\237\245\350\257\242", Q_NULLPTR));
        BtnSettings_5->setText(QApplication::translate("MainWin", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWin", "\346\231\272\346\205\247\345\201\234\350\275\246\344\272\221\345\271\263\345\217\260\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWin", "\347\233\221\346\216\247\345\233\236\346\224\276\346\250\241\345\274\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWin", "\357\274\221\357\274\221\350\276\206", Q_NULLPTR));
        label->setText(QApplication::translate("MainWin", "\346\234\254\350\275\246\345\234\272\350\275\246\350\276\206\346\200\273\346\225\260\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWin", "\347\233\256\345\211\215\350\275\246\345\234\272\347\251\272\351\227\262\350\275\246\344\275\215", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWin", "\357\274\221\357\274\221\350\276\206", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWin", "\344\272\272\347\211\251\345\222\214\350\275\246\350\276\206\347\211\271\345\276\201\345\233\276\347\211\207\346\212\223\346\213\215", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWin", "\345\201\234\350\275\246\345\234\272\347\233\221\346\216\247\345\275\225\345\210\266", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWin", "\350\247\206\351\242\221\347\233\221\346\216\247\350\207\252\345\212\250\345\275\225\345\210\266", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWin", "\345\201\234\350\275\246\345\234\272\347\233\221\346\216\247", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWin", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWin", "\346\231\272\346\205\247\345\201\234\350\275\246\347\263\273\347\273\237", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWin", "\346\214\211\346\234\210\346\230\276\347\244\272", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWin", "\346\214\211\345\244\251\346\230\276\347\244\272", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWin", "\346\227\245\346\234\237", Q_NULLPTR));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWin", "2022-05", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWin", "2022-05-01", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWin", "2022-05-02", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWin", "2022-05-03", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem1->child(3);
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWin", "2022-05-04", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem1->child(4);
        ___qtreewidgetitem6->setText(0, QApplication::translate("MainWin", "2022-05-05", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem1->child(5);
        ___qtreewidgetitem7->setText(0, QApplication::translate("MainWin", "2022-05-06", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem1->child(6);
        ___qtreewidgetitem8->setText(0, QApplication::translate("MainWin", "2022-05-07", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem1->child(7);
        ___qtreewidgetitem9->setText(0, QApplication::translate("MainWin", "2022-05-08", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem1->child(8);
        ___qtreewidgetitem10->setText(0, QApplication::translate("MainWin", "2022-05-09", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem1->child(9);
        ___qtreewidgetitem11->setText(0, QApplication::translate("MainWin", "2022-05-10", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem1->child(10);
        ___qtreewidgetitem12->setText(0, QApplication::translate("MainWin", "2022-05-11", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem1->child(11);
        ___qtreewidgetitem13->setText(0, QApplication::translate("MainWin", "2022-05-12", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem1->child(12);
        ___qtreewidgetitem14->setText(0, QApplication::translate("MainWin", "2022-05-13", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem15 = ___qtreewidgetitem1->child(13);
        ___qtreewidgetitem15->setText(0, QApplication::translate("MainWin", "2022-05-14", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem16 = ___qtreewidgetitem1->child(14);
        ___qtreewidgetitem16->setText(0, QApplication::translate("MainWin", "2022-05-15", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem17 = ___qtreewidgetitem1->child(15);
        ___qtreewidgetitem17->setText(0, QApplication::translate("MainWin", "2022-05-16", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem18 = ___qtreewidgetitem1->child(16);
        ___qtreewidgetitem18->setText(0, QApplication::translate("MainWin", "2022-05-17", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem19 = ___qtreewidgetitem1->child(17);
        ___qtreewidgetitem19->setText(0, QApplication::translate("MainWin", "2022-05-18", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem20 = ___qtreewidgetitem1->child(18);
        ___qtreewidgetitem20->setText(0, QApplication::translate("MainWin", "2022-05-19", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem21 = ___qtreewidgetitem1->child(19);
        ___qtreewidgetitem21->setText(0, QApplication::translate("MainWin", "2022-05-20", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem22 = ___qtreewidgetitem1->child(20);
        ___qtreewidgetitem22->setText(0, QApplication::translate("MainWin", "2022-05-21", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem23 = ___qtreewidgetitem1->child(21);
        ___qtreewidgetitem23->setText(0, QApplication::translate("MainWin", "2022-05-22", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem24 = ___qtreewidgetitem1->child(22);
        ___qtreewidgetitem24->setText(0, QApplication::translate("MainWin", "2022-05-23", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem25 = ___qtreewidgetitem1->child(23);
        ___qtreewidgetitem25->setText(0, QApplication::translate("MainWin", "2022-05-24", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem26 = ___qtreewidgetitem1->child(24);
        ___qtreewidgetitem26->setText(0, QApplication::translate("MainWin", "2022-05-25", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem27 = ___qtreewidgetitem1->child(25);
        ___qtreewidgetitem27->setText(0, QApplication::translate("MainWin", "2022-05-26", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem28 = ___qtreewidgetitem1->child(26);
        ___qtreewidgetitem28->setText(0, QApplication::translate("MainWin", "2022-05-27", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem29 = ___qtreewidgetitem1->child(27);
        ___qtreewidgetitem29->setText(0, QApplication::translate("MainWin", "2022-05-28", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem30 = ___qtreewidgetitem1->child(28);
        ___qtreewidgetitem30->setText(0, QApplication::translate("MainWin", "2022-05-29", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem31 = ___qtreewidgetitem1->child(29);
        ___qtreewidgetitem31->setText(0, QApplication::translate("MainWin", "2022-05-30", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem32 = ___qtreewidgetitem1->child(30);
        ___qtreewidgetitem32->setText(0, QApplication::translate("MainWin", "2022-05-31", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem33 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem33->setText(0, QApplication::translate("MainWin", "2022-06", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem34 = ___qtreewidgetitem33->child(0);
        ___qtreewidgetitem34->setText(0, QApplication::translate("MainWin", "2022-06-01", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem35 = ___qtreewidgetitem33->child(1);
        ___qtreewidgetitem35->setText(0, QApplication::translate("MainWin", "2022-06-02", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem36 = ___qtreewidgetitem33->child(2);
        ___qtreewidgetitem36->setText(0, QApplication::translate("MainWin", "2022-06-03", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem37 = ___qtreewidgetitem33->child(3);
        ___qtreewidgetitem37->setText(0, QApplication::translate("MainWin", "2022-06-04", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem38 = ___qtreewidgetitem33->child(4);
        ___qtreewidgetitem38->setText(0, QApplication::translate("MainWin", "2022-06-05", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem39 = ___qtreewidgetitem33->child(5);
        ___qtreewidgetitem39->setText(0, QApplication::translate("MainWin", "2022-06-06", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem40 = ___qtreewidgetitem33->child(6);
        ___qtreewidgetitem40->setText(0, QApplication::translate("MainWin", "2022-06-07", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem41 = ___qtreewidgetitem33->child(7);
        ___qtreewidgetitem41->setText(0, QApplication::translate("MainWin", "2022-06-08", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem42 = ___qtreewidgetitem33->child(8);
        ___qtreewidgetitem42->setText(0, QApplication::translate("MainWin", "2022-06-09", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem43 = ___qtreewidgetitem33->child(9);
        ___qtreewidgetitem43->setText(0, QApplication::translate("MainWin", "2022-06-10", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem44 = ___qtreewidgetitem33->child(10);
        ___qtreewidgetitem44->setText(0, QApplication::translate("MainWin", "2022-06-11", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem45 = ___qtreewidgetitem33->child(11);
        ___qtreewidgetitem45->setText(0, QApplication::translate("MainWin", "2022-06-12", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem46 = ___qtreewidgetitem33->child(12);
        ___qtreewidgetitem46->setText(0, QApplication::translate("MainWin", "2022-06-13", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem47 = ___qtreewidgetitem33->child(13);
        ___qtreewidgetitem47->setText(0, QApplication::translate("MainWin", "2022-06-14", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem48 = ___qtreewidgetitem33->child(14);
        ___qtreewidgetitem48->setText(0, QApplication::translate("MainWin", "2022-06-15", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem49 = ___qtreewidgetitem33->child(15);
        ___qtreewidgetitem49->setText(0, QApplication::translate("MainWin", "2022-06-16", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem50 = ___qtreewidgetitem33->child(16);
        ___qtreewidgetitem50->setText(0, QApplication::translate("MainWin", "2022-06-17", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem51 = ___qtreewidgetitem33->child(17);
        ___qtreewidgetitem51->setText(0, QApplication::translate("MainWin", "2022-06-18", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem52 = ___qtreewidgetitem33->child(18);
        ___qtreewidgetitem52->setText(0, QApplication::translate("MainWin", "2022-06-19", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem53 = ___qtreewidgetitem33->child(19);
        ___qtreewidgetitem53->setText(0, QApplication::translate("MainWin", "2022-06-20", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem54 = ___qtreewidgetitem33->child(20);
        ___qtreewidgetitem54->setText(0, QApplication::translate("MainWin", "2022-06-21", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem55 = ___qtreewidgetitem33->child(21);
        ___qtreewidgetitem55->setText(0, QApplication::translate("MainWin", "2022-06-22", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem56 = ___qtreewidgetitem33->child(22);
        ___qtreewidgetitem56->setText(0, QApplication::translate("MainWin", "2022-06-23", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem57 = ___qtreewidgetitem33->child(23);
        ___qtreewidgetitem57->setText(0, QApplication::translate("MainWin", "2022-06-24", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem58 = ___qtreewidgetitem33->child(24);
        ___qtreewidgetitem58->setText(0, QApplication::translate("MainWin", "2022-06-25", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem59 = ___qtreewidgetitem33->child(25);
        ___qtreewidgetitem59->setText(0, QApplication::translate("MainWin", "2022-06-26", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem60 = ___qtreewidgetitem33->child(26);
        ___qtreewidgetitem60->setText(0, QApplication::translate("MainWin", "2022-06-27", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem61 = ___qtreewidgetitem33->child(27);
        ___qtreewidgetitem61->setText(0, QApplication::translate("MainWin", "2022-06-28", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem62 = ___qtreewidgetitem33->child(28);
        ___qtreewidgetitem62->setText(0, QApplication::translate("MainWin", "2022-06-29", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem63 = ___qtreewidgetitem33->child(29);
        ___qtreewidgetitem63->setText(0, QApplication::translate("MainWin", "2022-06-30", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem64 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem64->setText(0, QApplication::translate("MainWin", "2022-07", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem65 = ___qtreewidgetitem64->child(0);
        ___qtreewidgetitem65->setText(0, QApplication::translate("MainWin", "2022-07-01", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem66 = ___qtreewidgetitem64->child(1);
        ___qtreewidgetitem66->setText(0, QApplication::translate("MainWin", "2022-07-02", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem67 = ___qtreewidgetitem64->child(2);
        ___qtreewidgetitem67->setText(0, QApplication::translate("MainWin", "2022-07-03", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem68 = ___qtreewidgetitem64->child(3);
        ___qtreewidgetitem68->setText(0, QApplication::translate("MainWin", "2022-07-04", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem69 = ___qtreewidgetitem64->child(4);
        ___qtreewidgetitem69->setText(0, QApplication::translate("MainWin", "2022-07-05", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem70 = ___qtreewidgetitem64->child(5);
        ___qtreewidgetitem70->setText(0, QApplication::translate("MainWin", "2022-07-06", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem71 = ___qtreewidgetitem64->child(6);
        ___qtreewidgetitem71->setText(0, QApplication::translate("MainWin", "2022-07-07", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem72 = ___qtreewidgetitem64->child(7);
        ___qtreewidgetitem72->setText(0, QApplication::translate("MainWin", "2022-07-08", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem73 = ___qtreewidgetitem64->child(8);
        ___qtreewidgetitem73->setText(0, QApplication::translate("MainWin", "2022-07-09", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem74 = ___qtreewidgetitem64->child(9);
        ___qtreewidgetitem74->setText(0, QApplication::translate("MainWin", "2022-07-10", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem75 = ___qtreewidgetitem64->child(10);
        ___qtreewidgetitem75->setText(0, QApplication::translate("MainWin", "2022-07-11", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem76 = ___qtreewidgetitem64->child(11);
        ___qtreewidgetitem76->setText(0, QApplication::translate("MainWin", "2022-07-12", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem77 = ___qtreewidgetitem64->child(12);
        ___qtreewidgetitem77->setText(0, QApplication::translate("MainWin", "2022-07-13", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem78 = ___qtreewidgetitem64->child(13);
        ___qtreewidgetitem78->setText(0, QApplication::translate("MainWin", "2022-07-14", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem79 = ___qtreewidgetitem64->child(14);
        ___qtreewidgetitem79->setText(0, QApplication::translate("MainWin", "2022-07-15", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem80 = ___qtreewidgetitem64->child(15);
        ___qtreewidgetitem80->setText(0, QApplication::translate("MainWin", "2022-07-16", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem81 = ___qtreewidgetitem64->child(16);
        ___qtreewidgetitem81->setText(0, QApplication::translate("MainWin", "2022-07-17", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem82 = ___qtreewidgetitem64->child(17);
        ___qtreewidgetitem82->setText(0, QApplication::translate("MainWin", "2022-07-18", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem83 = ___qtreewidgetitem64->child(18);
        ___qtreewidgetitem83->setText(0, QApplication::translate("MainWin", "2022-07-19", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem84 = ___qtreewidgetitem64->child(19);
        ___qtreewidgetitem84->setText(0, QApplication::translate("MainWin", "2022-07-20", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem85 = ___qtreewidgetitem64->child(20);
        ___qtreewidgetitem85->setText(0, QApplication::translate("MainWin", "2022-07-21", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem86 = ___qtreewidgetitem64->child(21);
        ___qtreewidgetitem86->setText(0, QApplication::translate("MainWin", "2022-07-22", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem87 = ___qtreewidgetitem64->child(22);
        ___qtreewidgetitem87->setText(0, QApplication::translate("MainWin", "2022-07-23", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem88 = ___qtreewidgetitem64->child(23);
        ___qtreewidgetitem88->setText(0, QApplication::translate("MainWin", "2022-07-24", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem89 = ___qtreewidgetitem64->child(24);
        ___qtreewidgetitem89->setText(0, QApplication::translate("MainWin", "2022-07-25", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem90 = ___qtreewidgetitem64->child(25);
        ___qtreewidgetitem90->setText(0, QApplication::translate("MainWin", "2022-07-26", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem91 = ___qtreewidgetitem64->child(26);
        ___qtreewidgetitem91->setText(0, QApplication::translate("MainWin", "2022-07-27", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem92 = ___qtreewidgetitem64->child(27);
        ___qtreewidgetitem92->setText(0, QApplication::translate("MainWin", "2022-07-28", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem93 = ___qtreewidgetitem64->child(28);
        ___qtreewidgetitem93->setText(0, QApplication::translate("MainWin", "2022-07-29", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem94 = ___qtreewidgetitem64->child(29);
        ___qtreewidgetitem94->setText(0, QApplication::translate("MainWin", "2022-07-30", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem95 = ___qtreewidgetitem64->child(30);
        ___qtreewidgetitem95->setText(0, QApplication::translate("MainWin", "2022-07-31", Q_NULLPTR));
        treeWidget->setSortingEnabled(__sortingEnabled);

        pushButton_11->setText(QApplication::translate("MainWin", "<<\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        label_53->setText(QApplication::translate("MainWin", "\347\254\2541\351\241\265", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("MainWin", "\344\270\213\344\270\200\351\241\265>>", Q_NULLPTR));
        pushButton_20->setText(QApplication::translate("MainWin", "\350\277\224\345\233\236", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWin", "\346\200\273\346\227\266\351\225\277", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWin", "0:0", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWin", "0.5X", Q_NULLPTR)
         << QApplication::translate("MainWin", "0.7X", Q_NULLPTR)
         << QApplication::translate("MainWin", "1.0X", Q_NULLPTR)
         << QApplication::translate("MainWin", "1.2X", Q_NULLPTR)
         << QApplication::translate("MainWin", "1.5X", Q_NULLPTR)
         << QApplication::translate("MainWin", "1.7X", Q_NULLPTR)
         << QApplication::translate("MainWin", "2.0X", Q_NULLPTR)
        );
        label_9->setText(QApplication::translate("MainWin", "\345\267\262\346\222\255\346\224\276", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWin", "0:0", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWin", "\350\247\206\351\242\221", Q_NULLPTR));
        pushButton_19->setText(QApplication::translate("MainWin", "\346\232\202\345\201\234", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWin", "\350\276\223\345\205\245\350\275\246\347\211\214\345\217\267\347\240\201\357\274\232", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWin", "\345\205\245\345\234\272\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWin", "\345\207\272\345\234\272\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        BtnSerchCarinfo->setText(QApplication::translate("MainWin", "\346\237\245\350\257\242", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWin", "\345\272\217\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWin", "\350\275\246\347\211\214\344\277\241\346\201\257", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWin", "\345\205\245\345\234\272\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWin", "\345\207\272\345\234\272\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWin", "\345\205\245\345\234\272\345\233\276\347\211\207", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWin", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWin", "\345\201\234\350\275\246\351\207\221\351\242\235", Q_NULLPTR));
        BtnDataOut->setText(QApplication::translate("MainWin", "\346\225\260\346\215\256\345\257\274\345\207\272", Q_NULLPTR));
        BtnRetnMain->setText(QApplication::translate("MainWin", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWin", "\345\211\251\344\275\231\350\275\246\344\275\215\357\274\232", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWin", "\345\275\223\345\211\215\347\224\250\346\210\267\357\274\232", Q_NULLPTR));
        LabCurrentTime->setText(QApplication::translate("MainWin", "\345\275\223\345\211\215\347\263\273\347\273\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWin: public Ui_MainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
