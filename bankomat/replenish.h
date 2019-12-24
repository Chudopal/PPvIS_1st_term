#ifndef REPLENISH_H
#define REPLENISH_H

#include <QDialog>
#include "cart.h"

namespace Ui {
class replenish;
}

class replenish : public QDialog
{
    Q_OBJECT

public:
    explicit replenish(QWidget *parent = nullptr);
    ~replenish();
    void write_money(cart);


private slots:
    void on_pushButton_clicked();

private:
    Ui::replenish *ui;
    cart this_cart;
};

#endif // REPLENISH_H
