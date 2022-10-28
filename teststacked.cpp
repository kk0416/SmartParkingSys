#include "teststacked.h"
#include "ui_teststacked.h"

teststacked::teststacked(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::teststacked)
{
    ui->setupUi(this);
}

teststacked::~teststacked()
{
    delete ui;
}

void teststacked::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void teststacked::on_pushButton_4_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void teststacked::on_pushButton_3_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void teststacked::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}
