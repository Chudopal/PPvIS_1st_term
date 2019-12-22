#ifndef REPLENISH_H
#define REPLENISH_H

#include <QDialog>

namespace Ui {
class replenish;
}

class replenish : public QDialog
{
    Q_OBJECT

public:
    explicit replenish(QWidget *parent = nullptr);
    ~replenish();

private:
    Ui::replenish *ui;
};

#endif // REPLENISH_H
