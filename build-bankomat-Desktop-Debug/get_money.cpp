#include "get_money.h"
#include "ui_get_money.h"

get_money::get_money(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::get_money)
{
    ui->setupUi(this);
}

get_money::~get_money()
{
    delete ui;
}
