#include "show_money.h"
#include "ui_show_money.h"
#include <sstream>
show_money::show_money(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::show_money)
{
    ui->setupUi(this);
    int l = 100;
    ui->label_2->setNum(l);
}

show_money::~show_money()
{
    delete ui;
}

void show_money::on_pushButton_clicked()
{
    this->close();

}
