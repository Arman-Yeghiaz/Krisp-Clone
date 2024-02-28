#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QFile>

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

void MainWindow::on_actionOpen_triggered()
{

    filename = QFileDialog::getOpenFileName(this,tr("Open File"),"Text File (*.txt)");

    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    QTextStream stream(&file);
    ui->textEdit->setText(file.readAll());

    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    QFile file(filename);
    if (file.open(QIODevice::Truncate | QIODevice::ReadWrite)){
        QTextStream stream(&file);
        stream<<ui->textEdit->toPlainText();
    }
    file.close();
}


void MainWindow::on_actionQuit_triggered()
{
    QMessageBox::about(this,"Reality","You need a better TextEditor");
    QApplication::quit();
}

