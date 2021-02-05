#include "mywidget.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->widget, SIGNAL(sizeChanged(int)), this, SLOT(setSize(int)));
    connect(ui->widget, SIGNAL(newGeneration(int)), this, SLOT(setGeneration(int)));
    connect(ui->widget, SIGNAL(scaleChanged(double)), this, SLOT(setScale(double)));
    connect(ui->widget, SIGNAL(statusChanged(QString)), this, SLOT(setStatus(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSize(int size)
{
    ui->label_8->setText(QString::number(size));
}

void MainWindow::setGeneration(int i)
{
    ui->label_6->setText(QString::number(i));
}

void MainWindow::setScale(double scale)
{
    ui->label_4->setText(QString::number(scale, 'g', 3));
}

void MainWindow::setStatus(QString str)
{
    ui->label_2->setText(str);
}

/*
void MainWindow::setSpeed(QString str) {
    ui->label_10->setText(str);
}
*/
