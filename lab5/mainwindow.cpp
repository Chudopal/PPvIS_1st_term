#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::make_matrix(Matrix &a, Matrix &b){
    QString c = ui->lineEdit_1matr_colms->text();
    QString r = ui->lineEdit_1matr_rows->text();
    int column = c.toInt();
    int row = r.toInt();
    QString str = ui->textEdit_first_matr->toPlainText();
    if(column == 1 && row == 1){
        firstIsMatrix = false;
        valA = str.toInt();
    }
    else {
        firstIsMatrix = true;
        std::string buff = str.toStdString();
        std::stringstream ss;
        ss << buff;
        int k;
        std::vector<float> oneRow;
        for(int i = 0; i < row; i++) {
            for(int h = 0; h < column; h++) {
                ss >> k;

                oneRow.push_back(k);
            }
            a.make(oneRow, row, column);
            oneRow.clear();
        }
    }
    c = ui->lineEdit_2matr_colms->text();
    r = ui->lineEdit_2matr_rows->text();
    column = c.toInt();
    row = r.toInt();
    str = ui->textEdit_second_matr->toPlainText();
    if(column == 1 && row == 1){
        secondIsMatrix = false;
        valB = str.toFloat();
        //qDebug() << str;
        //qDebug() << valB;
    }
    else {
        secondIsMatrix = true;
        std::string buff = str.toStdString();
        std::stringstream ss;
        ss << buff;
        int k;
        std::vector<float> oneRow;
        for(int i = 0; i < row; i++) {
            for(int h = 0; h < column; h++) {
                ss >> k;
                oneRow.push_back(k);
            }
            b.make(oneRow, row, column);
            oneRow.clear();
        }
    }
}

void MainWindow::showMatr(Matrix res){
    QString buff;
    vector<vector <float>> matr;
    matr = res.getMatrix();
    for(int i = 0; i < matr.size(); i++) {
        for(int k = 0; k < matr[i].size(); k++){
            QString p;
            p.setNum(matr[i][k]);
            buff += p;
            buff += " ";
        }
        buff += "\n";
    }
    ui->label_show->setText(buff);
}

void MainWindow::on_pushButton_sum_clicked()
{
    Matrix a;
    Matrix b;
    ui->label_show->clear();
    make_matrix(a,b);
    Matrix sum;
    if(firstIsMatrix && secondIsMatrix){
        sum = a+b;
    }
    if(!firstIsMatrix && secondIsMatrix){
        sum = valA + b;
    }
    if(firstIsMatrix && !secondIsMatrix) {
        sum = a + valB;
        //qDebug() << valB;
    }
    showMatr(sum);
}

void MainWindow::on_pushButton_step_clicked()
{
    if(ui->lineEdit_2matr_rows->text() != "1" || ui->lineEdit_2matr_colms->text() != "1"){

        ui->label_show->setText("В степень матрицы\n нельзя возводить");
    }
    else {
        Matrix a;
        Matrix b;
        ui->label_show->clear();
        make_matrix(a,b);
        Matrix st;
        st = a^valB;
        showMatr(st);
    }
}


void MainWindow::on_pushButton_mul_clicked()
{
    ui->label_show->clear();
    if(ui->lineEdit_1matr_colms->text() != ui->lineEdit_2matr_rows->text()) {
        ui->label_show->setText("Киличество столбцов первой\n матрицы не равно количеству\n строк второй");
    }
    else {
    Matrix a;
    Matrix b;
    make_matrix(a,b);
    Matrix mul;
    if(firstIsMatrix && secondIsMatrix){
        mul = a*b;
    }
    if(!firstIsMatrix && secondIsMatrix){
        mul = valA + a;
    }
    if(firstIsMatrix && !secondIsMatrix) {
        mul = b + valB;
    }
    showMatr(mul);
    }
}

void MainWindow::on_pushButton_det_clicked()
{
    ui->label_show->clear();
    if(ui->lineEdit_1matr_rows->text() != ui->lineEdit_1matr_colms->text()) {
        ui->label_show->setText("Матрицв не является квадратной");
    }
    else {
    Matrix a;
    Matrix b;
    ui->label_show->clear();
    make_matrix(a,b);
    ui->label_show->setNum(a.GetDet());
    }
}
