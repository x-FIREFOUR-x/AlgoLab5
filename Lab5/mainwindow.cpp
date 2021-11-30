#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPainter"
#include "QGraphicsEllipseItem"
#include "point.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ButtonEnd->setEnabled(false);
    ui->ButtonEnd->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ButtonStart_clicked()
{
    ui->ButtonStart->setEnabled(false);
    ui->ButtonStart->setVisible(false);
    ui->ButtonEnd->setEnabled(true);
    ui->ButtonEnd->setVisible(true);

}





void MainWindow::on_ButtonEnd_clicked()
{
    ui->ButtonStart->setEnabled(true);
    ui->ButtonStart->setVisible(true);
    ui->ButtonEnd->setEnabled(false);
    ui->ButtonEnd->setVisible(false);
}

