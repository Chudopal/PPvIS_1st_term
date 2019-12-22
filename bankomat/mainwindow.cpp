#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_enter_clicked()
{
    QString password = ui->pass->text();
    string buff = password.toStdString();
    cart a(buff);
    if(!a.get_is_pass_correct()){
        ui->label_2->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; color:#cc0000;\">Неверный пароль</span></p></body></html>");
    }
    else{
        this->close();
        Dialog sec_wind;
        sec_wind.setModal(true);
        sec_wind.exec();
        //if(sec_wind.get_is_closed()){
        //   this->close();
        //}
    }
}

void MainWindow::on_exit_clicked()
{
    this->close();
}
