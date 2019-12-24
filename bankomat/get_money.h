#ifndef GET_MONEY_H
#define GET_MONEY_H

#include <QDialog>
#include "cart.h"

namespace Ui {
class get_money;
}

class get_money : public QDialog
{
    Q_OBJECT

public:
    explicit get_money(QWidget *parent = nullptr);
    ~get_money();
    void write_money (cart = {});
private slots:
    void on_pushButton_clicked();
private:
    Ui::get_money *ui;
    cart this_cart;
};

#endif // GET_MONEY_H
