#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

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

private:
    Ui::Dialog *ui;
    bool is_closed;
};

#endif // DIALOG_H
