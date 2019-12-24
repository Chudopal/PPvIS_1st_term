#ifndef SHOW_MONEY_H
#define SHOW_MONEY_H

#include "cart.h"
#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class show_money;
}

class show_money : public QDialog
{
    Q_OBJECT

public:
    explicit show_money(cart={}, QWidget *parent = nullptr);
    ~show_money();
    void initialise(cart);
private slots:
    void on_pushButton_clicked();
private:
    Ui::show_money *ui;
    cart this_cart;
};

#endif // SHOW_MONEY_H
