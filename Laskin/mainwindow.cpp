#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <string>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    state=1;
    operand=0;
    connect(ui->N0,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N1,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N2,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N3,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N4,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N5,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N6,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N7,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N8,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N9,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);

    connect(ui->add,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);
    connect(ui->sub,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);
    connect(ui->mul,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);
    connect(ui->div,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);

    connect(ui->clear,&QPushButton::clicked,this,&MainWindow::clearAndEnterClickHandler);
    connect(ui->enter,&QPushButton::clicked,this,&MainWindow::clearAndEnterClickHandler);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickedHandler()
{
    QPushButton *button=qobject_cast<QPushButton*>(sender());
    if (!button) return;
    QString name = button->objectName();
    qDebug()<<"button name: "<<name;

    if(!button) return;
    QString value = button->text();
    if(state == 1){
        number1 += value;
        ui->num1->setText(number1);

    }else {
        number2 += value;
        ui->num2->setText(number2);
    }
}

void MainWindow::clearAndEnterClickHandler()
{
    QPushButton *button=qobject_cast<QPushButton*>(sender());
    if(!button) return;


    if(button->objectName()=="clear"){
        resetLineEdits();
    }else if(button->objectName()=="enter"){
        if(number1.isEmpty()|| number2.isEmpty() || operand==0){
            ui->result->setText("error");
            return;

        }

    float num1=number1.toFloat();
    float num2=number2.toFloat();
    float result=0;
    switch(operand){
    case 1: result = num1 + num2; break;
    case 2: result = num1 - num2; break;
    case 3: result = num1 * num2; break;
    case 4:
        if(num2 == 0) {
            ui->result->setText("error");
            return;
        }
        result = num1 / num2;
        break;

    }
        ui->result->setText(QString::number(result));
    }



}

void MainWindow::addSubMulDivClickHandler()
{
    QPushButton *button=qobject_cast<QPushButton*>(sender());
    if(!button || number1.isEmpty()) return;
    QString op = button->text();

    if(op == "+") operand = 1;
    else if(op == "-") operand = 2;
    else if(op == "*") operand = 3;
    else if(op == "/") operand = 4;
    state = 2;
    }

void MainWindow::resetLineEdits()
{

    number1.clear();
    number2.clear();
    state=1;
    operand=0;
    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();

}

