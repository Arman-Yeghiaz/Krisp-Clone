#include "mainwindow.h"
#include "ui_mainwindow.h"

static int counter = 0;

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

void MainWindow::on_pushButton_clicked()
{
    counter++;
    QString str = QString::number(counter);
    ui->label->setText(str);
}

