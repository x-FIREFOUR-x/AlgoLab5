#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "windows/windowsworker.h"
#include "logic/gameboard.h"
#include "logic/fileworker.h"

GameWindow::GameWindow(bool g_with_pc, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    game_board= ui->graphicsView;
    game_board->set_parameters(ui->graphicsView->width(), g_with_pc);
    setFixedSize(this->width(), this->height());

}
GameWindow::GameWindow(bool g_with_pc, bool pc_first, int level_dif, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    game_board= ui->graphicsView;
    game_board->set_parameters(ui->graphicsView->width(), g_with_pc,pc_first, level_dif);
    setFixedSize(this->width(), this->height());
}
GameWindow::GameWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    game_board= ui->graphicsView;
    download_game();
    setFixedSize(this->width(), this->height());
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_CloseEnd_triggered()
{
    FileWorker::set_filename("");
    WindowsWorker::open_MainWindow();
    WindowsWorker::close_GameWindow();
}

void GameWindow::on_SaveAs_triggered()
{
    WindowsWorker::open_SaveWindow();
    WindowsWorker::hide_WindowGame();
}


void GameWindow::on_Save_triggered()
{
    if(FileWorker::get_filename() == "")
        on_SaveAs_triggered();
    else
        save_game();
}

void GameWindow::save_game()
{
    bool game_with_pc = game_board->get_game_with_pc();
    bool computer_first = game_board->get_computer_first();
    int difficulty = game_board->get_difficulty();
    int current_player = game_board->get_current_player();
    bool finished = game_board->get_finished();
    bool player_win = game_board->get_player_win();
    Board board = game_board->get_board();

    FileWorker::save_game_file(game_with_pc, computer_first, difficulty, current_player, finished, player_win, board);
    QMessageBox::about(this, "Збережено", "Гра успішно збережена");

}

void GameWindow::download_game()
{
    bool game_with_pc;
    bool computer_first;
    int difficulty;
    int current_player;
    bool finished;
    bool player_win;
    Board board;
    FileWorker::download_game_file(game_with_pc, computer_first, difficulty, current_player, finished, player_win, board);
    game_board->download_game(this->width(),game_with_pc, computer_first, difficulty, current_player, finished, player_win, board);

}

void GameWindow::on_Rules_triggered()
{
    WindowsWorker::open_WindowRules();
    WindowsWorker::hide_WindowGame();
}

void GameWindow::style()
{
    /*
    //ui->centralwidget->setStyleSheet("background-color:#2c8616;");
    //ui->scrollArea->setStyleSheet("background-color:white;");
    ui->scrollAreaWidgetContents->setStyleSheet("background-color:#2c8616;");

    ui->label->setStyleSheet("color:black; font: italic 16pt Monotype Corsiva; font-weight: 550;") ;

    for (int i = 0; i < buttons.size(); i++ )
    {
        buttons[i]->setStyleSheet("background-color:yellow; border: 1px solid black; font: italic 12pt Calibri;") ;
        buttons_delete[i]->setStyleSheet("background-color:red; border: 1px solid black; font: 16pt;") ;
    }
    */

}
