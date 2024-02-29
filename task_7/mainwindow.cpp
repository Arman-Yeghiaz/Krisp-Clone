#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QMessageBox>

double firstNum;
QString mathButton;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: black;");
    ui->lineEdit->setStyleSheet("background-color: black;");



    this->centralWidget()->setLayout(ui->gridLayout);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::getDigits);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::getDigits);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::getDigits);
    connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::getDigits);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::getDigits);
    connect(ui->pushButton_12, &QPushButton::clicked, this, &MainWindow::getDigits);
    connect(ui->pushButton_15, &QPushButton::clicked, this, &MainWindow::getDigits);
    connect(ui->pushButton_13, &QPushButton::clicked, this, &MainWindow::getDigits);
    connect(ui->pushButton_16, &QPushButton::clicked, this, &MainWindow::getDigits);
    connect(ui->pushButton_19, &QPushButton::clicked, this, &MainWindow::getDigits);

    connect(ui->pushButton_20,&QPushButton::clicked,this,&MainWindow::dotButton);

    connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWindow::operations);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&MainWindow::operations);

    connect(ui->pushButton_4,&QPushButton::clicked,this,&MainWindow::mathOperations);
    connect(ui->pushButton_6,&QPushButton::clicked,this,&MainWindow::mathOperations);
    connect(ui->pushButton_10,&QPushButton::clicked,this,&MainWindow::mathOperations);
    connect(ui->pushButton_14,&QPushButton::clicked,this,&MainWindow::mathOperations);

    connect(ui->pushButton_18,&QPushButton::clicked,this,&MainWindow::equalSign);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getDigits(){
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString str;
    double numbers = (ui->lineEdit->text()+button->text()).toDouble();
    str = QString::number(numbers);
    ui->lineEdit->setText(str);
}

void MainWindow::dotButton(){
    if(!(ui->lineEdit->text().contains("."))){
        ui->lineEdit->setText(ui->lineEdit->text()+".");
    }

}
void MainWindow::operations(){
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString str;
    if (ui->lineEdit->text() != ""){
        double num = ui->lineEdit->text().toDouble();
        if (button->text() == "+/-"){
            num *= -1;
        }else if(button->text() == "%"){
            num*=0.01;
        }
        str = QString::number(num);
    }
    ui->lineEdit->setText(str);
}
void MainWindow::mathOperations(){
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    mathButton = button->text();
    firstNum = (ui->lineEdit->text()).toDouble();
    ui->lineEdit->setText("");
}

void MainWindow::equalSign(){
    double result=0,secondNum;
    QString str;
    secondNum = ui->lineEdit->text().toDouble();

    if(mathButton == "+"){
        result = secondNum + firstNum;
    }else if(mathButton == "-"){
        result = firstNum - secondNum;
    }else if(mathButton == "/"){
        if (secondNum != 0){
            result = firstNum/secondNum;
        }
    }else if(mathButton == "x"){
        result = firstNum*secondNum;
    }

    if(mathButton == "/" && secondNum == 0){
        ui->lineEdit->setText("Lav eli inch bajanac 0");
    }else{
        str = QString::number(result);
        ui->lineEdit->setText(str);
    }


}

void MainWindow::on_pushButton_clicked()
{
    mathButton = "";
    ui->lineEdit->setText("");
}

