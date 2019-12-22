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
