#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

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

void MainWindow::on_ButtonStart_clicked()
{
    this->close();
    GameWindow * game_window = new GameWindow(this);
    game_window->setWindowTitle("Domineering 8x8");
    game_window->show();

}

void MainWindow::on_ButtonEnd_clicked()
{
   QApplication::quit();
}

