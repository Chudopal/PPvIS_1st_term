#ifndef GET_MONEY_H
#define GET_MONEY_H

#include <QDialog>

namespace Ui {
class get_money;
}

class get_money : public QDialog
{
    Q_OBJECT

public:
    explicit get_money(QWidget *parent = nullptr);
    ~get_money();

private:
    Ui::get_money *ui;
};

#endif // GET_MONEY_H
