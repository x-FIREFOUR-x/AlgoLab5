#include "presettingwindow.h"
#include "ui_presettingwindow.h"
#include "windows/windowsworker.h"

PresettingWindow::PresettingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PresettingWindow)
{
    ui->setupUi(this);
    style();
    this->setFixedSize(width(), height());
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

void PresettingWindow::style()
{
    ui->centralwidget->setStyleSheet("background-color:#fff200;");

    ui->ButtonBack->setStyleSheet("background-color:#0bc13f; border: 1px solid black; font: italic 12pt Calibri; font-weight: 570;");
    ui->ButtonGoGame->setStyleSheet("background-color:#0bc13f; border: 1px solid black; font: italic 12pt Calibri; font-weight: 570;");

    ui->label->setStyleSheet("font: italic 12pt Calibri; font-weight: 570;");
    ui->label_2->setStyleSheet("font: italic 12pt Calibri; font-weight: 570;");
    ui->label_3->setStyleSheet("font: italic 12pt Calibri; font-weight: 570;");

    ui->radioButtonEazy->setStyleSheet("font: italic 10pt Calibri; font-weight: 570;");
    ui->radioButtonMiddle->setStyleSheet("font: italic 10pt Calibri; font-weight: 570;");
    ui->radioButtonHard->setStyleSheet("font: italic 10pt Calibri; font-weight: 570;");

    ui->radioButtonPCFirst->setStyleSheet("font: italic 10pt Calibri; font-weight: 570;");
    ui->radioButtonPlayerFirst->setStyleSheet("font: italic 10pt Calibri; font-weight: 570;");

    ui->radioButtonPlayPC->setStyleSheet("font: italic 10pt Calibri; font-weight: 570;");
    ui->radioButtonTwoPlayers->setStyleSheet("font: italic 10pt Calibri; font-weight: 570;");
}
