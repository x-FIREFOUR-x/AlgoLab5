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
    WindowsWorker::open_PresettingWindow();
    WindowsWorker::close_MainWindow();

}

void MainWindow::on_ButtonEnd_clicked()
{
   QApplication::quit();
}


void MainWindow::on_ButtonDownload_clicked()
{
    WindowsWorker::open_DownloadWindow();
    WindowsWorker::close_MainWindow();

}


void MainWindow::on_ButtonRules_clicked()
{
    WindowsWorker::open_WindowRules();
    WindowsWorker::close_MainWindow();
}

