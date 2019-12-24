#include "get_money.h"
#include "ui_get_money.h"

get_money::get_money(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::get_money)
{
    ui->setupUi(this);
}

get_money::~get_money(){
    delete ui;
}

void get_money::write_money(cart obj){
    this_cart = obj;
}

void get_money::on_pushButton_clicked(){
    QString buff = ui->lineEdit->text();
    int sr = buff.toInt();
    if(sr > this_cart.get_amount()) {
        ui->label_2->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; color:#cc0000;\">У вас недостаточно средств</span></p></body></html>");
    }
    else {
        this_cart.take_money(sr);
        this_cart.write_amount();
        this->close();
    }
}
