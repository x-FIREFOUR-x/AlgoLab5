#include "presettingwindow.h"
#include "ui_presettingwindow.h"
#include "windows/windowsworker.h"

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
    if (!play_with_pc)
    {
        WindowsWorker::open_GameWindow(play_with_pc);
    }
    else
    {
        bool pc_first = ui->radioButtonPCFirst->isChecked();
        int level_dif;
        if(ui->radioButtonEazy->isChecked())
            level_dif = 1;
        else
            if(ui->radioButtonMiddle->isChecked())
                level_dif = 2;
            else
                level_dif = 3;

        WindowsWorker::open_GameWindow(play_with_pc,pc_first,level_dif);
    }
    WindowsWorker::close_PresettingWindow();
}


void PresettingWindow::on_ButtonBack_clicked()
{
    WindowsWorker::open_MainWindow();
    WindowsWorker::close_PresettingWindow();
}


void PresettingWindow::on_radioButtonPlayPC_clicked()
{
    ui->frameWhoFirst->setVisible(true);
    ui->frameWhoFirst->setEnabled(true);
    ui->frameDifficulty->setVisible(true);
    ui->frameDifficulty->setEnabled(true);
}


void PresettingWindow::on_radioButtonTwoPlayers_clicked()
{
    ui->frameWhoFirst->setVisible(false);
    ui->frameWhoFirst->setEnabled(false);
    ui->frameDifficulty->setVisible(false);
    ui->frameDifficulty->setEnabled(false);
}

