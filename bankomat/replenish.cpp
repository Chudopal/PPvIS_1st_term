#include "replenish.h"
#include "ui_replenish.h"

replenish::replenish(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::replenish)
{
    ui->setupUi(this);
}

replenish::~replenish()
{
    delete ui;
}

void replenish::write_money(cart obj){
    this_cart = obj;
}

void replenish::on_pushButton_clicked()
{
    QString buff = ui->lineEdit->text();
    this_cart.put_money(buff.toInt());
    this_cart.write_amount();
    this->close();
}
