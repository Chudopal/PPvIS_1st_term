#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "matrix.h"
#include <sstream>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    //Matrix a;
    //Matrix b;
    float valA;
    float valB;
    bool firstIsMatrix = false;
    bool secondIsMatrix = false;
    void make_matrix(Matrix &, Matrix &);
    void showMatr(Matrix);
private slots:
    void on_pushButton_sum_clicked();
    void on_pushButton_step_clicked();
    void on_pushButton_mul_clicked();
    void on_pushButton_det_clicked();
};
#endif // MAINWINDOW_H
