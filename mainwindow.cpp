#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->lineEdit, &QLineEdit::textEdited, [this](QString currentText)
    {

           static QRegularExpression exp("^\\+\\d{11,11}$");
           if(exp.match(currentText).hasMatch())
           {
               setOkLabel();
           }
           else
           {
               setNonOkLabel();
           }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOkLabel()
{
    ui->label->setText("ok");
    ui->label->setStyleSheet("QLabel {color : green}");
}

void MainWindow::setNonOkLabel()
{
    ui->label->setText("fail");
    ui->label->setStyleSheet("QLabel {color : red}");
}

