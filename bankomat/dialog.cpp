#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_4_clicked()
{
    is_closed = true;
    this->close();

}

bool Dialog::get_is_closed() const{
    return is_closed;
}

void Dialog::on_pushButton_clicked()
{
    this->close();
    show_money balans;
    balans.setModal(true);
    balans.exec();
}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
    replenish a;
    a.setModal(true);
    a.exec();
}
