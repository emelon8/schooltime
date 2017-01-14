#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->openArrivalButton, SIGNAL(clicked()), this, SLOT(openArrivalButton_wasclicked()));
    QObject::connect(ui->openDepartureButton, SIGNAL(clicked()), this, SLOT(openDepartureButton_wasclicked()));
    QObject::connect(ui->computeButton, SIGNAL(clicked()), this, SLOT(on_computeButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openArrivalButton_wasclicked()
{
    string openfilestring = (ui->openArrivalEdit->text()).toStdString();
    myschooltime.readArrivalTime(openfilestring);

//    string openfilestring = openfilestring_temp;
//    for (string::iterator findtheslash = openfilestring_temp.begin();findtheslash != openfilestring_temp.end();findtheslash++) {
//        if (*findtheslash == "\\")
//            openfilestring.replace(findtheslash-1,0,"\\\\");
//    }
}

void MainWindow::openDepartureButton_wasclicked()
{
    string openfilestring = (ui->openDepartureEdit->text()).toStdString();
    myschooltime.readDepartureTime(openfilestring);
}

void MainWindow::on_computeButton_clicked()
{
    double ast = myschooltime.avgdailyschooltime();
    ui->hourslineEdit->setText(QString::number(myschooltime.schoolhours(ast)));
    ui->minuteslineEdit->setText(QString::number(myschooltime.schoolminutes(ast)));
}
