#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>

bool check(QLineEdit* lineEdit){
    return lineEdit->text().isEmpty();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setValidator( new QIntValidator);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int age = ui->lineEdit_2->text().toInt();
    if((check(ui->lineEdit) || check(ui->lineEdit_2)) || (age<=0 || age>130)){
        QMessageBox::critical(this,"Error Message","Something is wrong");
    }else{
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Everything is Okay","Need something to change?",QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::No){
            QApplication::quit();
        }
    }
}

