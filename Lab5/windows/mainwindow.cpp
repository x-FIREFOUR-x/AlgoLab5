#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include "windows/windowsworker.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    style();
    setFixedSize(width(),height());
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

void MainWindow::style()
{

    ui->centralwidget->setStyleSheet("background-color:#fff200;");

    ui->ButtonStart->setStyleSheet("background-color:#0bc13f; border: 1px solid black; font: italic 12pt Calibri; font-weight: 570;");
    ui->ButtonEnd->setStyleSheet("background-color:#0bc13f; border: 1px solid black; font: italic 12pt Calibri; font-weight: 570;");
    ui->ButtonRules->setStyleSheet("background-color:#0bc13f; border: 1px solid black; font: italic 12pt Calibri; font-weight: 570;");
    ui->ButtonDownload->setStyleSheet("background-color:#0bc13f; border: 1px solid black; font: italic 12pt Calibri; font-weight: 570;");
}
