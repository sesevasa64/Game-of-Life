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
    connect(ui->widget, SIGNAL(intervalChanged(int)), this, SLOT(setTimeInterval(int)));
    connect(ui->widget, SIGNAL(statusChanged(QString)), this, SLOT(setStatus(QString)));
    connect(ui->widget, SIGNAL(menuStatusChanged(QString)), this, SLOT(setMenuStatus(QString)));

    connect(ui->action_9, SIGNAL(triggered()), ui->widget, SLOT(setColor()));
    connect(ui->action_3, SIGNAL(triggered()), ui->widget, SLOT(swapTime()));
    connect(ui->action_8, SIGNAL(triggered()), ui->widget, SLOT(eraseAll()));
    connect(ui->action, SIGNAL(triggered()), ui->widget, SLOT(speedUp()));
    connect(ui->action_2, SIGNAL(triggered()), ui->widget, SLOT(speedDown()));
    connect(ui->action_6, SIGNAL(triggered()), ui->widget, SLOT(loadColony()));
    connect(ui->action_7, SIGNAL(triggered()), ui->widget, SLOT(saveColony()));
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

void MainWindow::setMenuStatus(QString str)
{
    ui->action_3->setText(str);
}

void MainWindow::setTimeInterval(int interval)
{
    ui->label_10->setText(QString::number(interval));
}
