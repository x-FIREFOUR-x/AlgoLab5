#include "presettingwindow.h"
#include "ui_presettingwindow.h"
#include "mainwindow.h"

PresettingWindow::PresettingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PresettingWindow)
{
    ui->setupUi(this);
}

PresettingWindow::~PresettingWindow()
{
    delete ui;
}

void PresettingWindow::on_ButtonGoGame_clicked()
{
    bool play_with_pc = ui->radioButtonPlayPC->isChecked();
    this->close();
    GameWindow * game_window = new GameWindow(play_with_pc, this);
    game_window->setWindowTitle("Domineering 8x8");
    game_window->show();
}


void PresettingWindow::on_ButtonBack_clicked()
{
    this->close();
    MainWindow * menu = new MainWindow;
    menu->setWindowTitle("Domineering 8x8");
    menu->show();
}

