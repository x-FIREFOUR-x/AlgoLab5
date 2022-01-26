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
    /*
    this->close();
    MainWindow * menu = new MainWindow;
    menu->setWindowTitle("Domineering 8x8");
    menu->show();*/
    WindowsWorker::open_MainWindow();
    WindowsWorker::close_GameWindow();
}
void GameWindow::save_game()
{
   /* bool game_with_pc = game_board->get_game_with_pc();
    bool finished = game_board->get_finished();
    int who_move_first =  game_board->get_who_move_first();
    int current_player = game_board->get_current_player();
    vector<int> scores = game_board->get_scores();

    FileWorker::save_game_state(game_with_pc,finished, who_move_first, current_player, scores);


    vector<bool> flags = game_board->get_flags();
    pair<int,int> converted_card = game_board->get_card_converted();

    FileWorker::save_game_effects(flags, converted_card);


    vector<pair<int,int>> hands1 = game_board->get_cards_hands1();
    vector<pair<int,int>> hands2 = game_board->get_cards_hands2();
    vector<pair<int,int>> deck = game_board->get_cards_deck();
    pair<int,int> top_card = game_board->get_top_card();
    vector<pair<int,int>> discard = game_board->get_diacardcards_deck();

    FileWorker::save_game_cards(hands1, hands2, deck, top_card, discard);

    QMessageBox::about(this, "Збережено", "Гра успішно збережена");*/
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
    FileWorker::save_game_file(game_with_pc, computer_first, difficulty, current_player, finished, player_win, board);
    game_board->download_game(this->width(),game_with_pc, computer_first, difficulty, current_player, finished, player_win, board);

}
