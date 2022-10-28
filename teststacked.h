#ifndef TESTSTACKED_H
#define TESTSTACKED_H

#include <QWidget>

namespace Ui {
class teststacked;
}

class teststacked : public QWidget
{
    Q_OBJECT

public:
    explicit teststacked(QWidget *parent = nullptr);
    ~teststacked();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::teststacked *ui;
};

#endif // TESTSTACKED_H
