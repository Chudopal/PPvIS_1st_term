#include "dialog.h"
#include "ui_dialog.h"
#include "get_money.h"
#include <QDebug>

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
    show_money balans(this_cart);
    balans.initialise(this_cart);
    balans.setModal(true);
    balans.exec();
}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
    replenish a;
    a.write_money(this_cart);
    a.setModal(true);
    a.exec();
}

void Dialog::on_pushButton_3_clicked()
{
   get_money a;
   this->close();
   a.write_money(this_cart);
   a.exec();
   a.show();
}

void Dialog::initialise_cart(cart inp){
    this_cart = inp;
}
