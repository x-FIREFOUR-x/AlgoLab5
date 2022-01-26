#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include "windows/windowsworker.h"

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
    /*
    this->close();
    PresettingWindow * preset_window = new PresettingWindow(this);
    preset_window->setWindowTitle("Domineering 8x8");
    preset_window->show();*/
    WindowsWorker::open_PresettingWindow();
    WindowsWorker::close_MainWindow();

}

void MainWindow::on_ButtonEnd_clicked()
{
   QApplication::quit();
}

