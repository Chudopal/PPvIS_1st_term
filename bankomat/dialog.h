#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "show_money.h"
#include "replenish.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    bool get_is_closed() const;
private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    bool is_closed;
};

#endif // DIALOG_H
