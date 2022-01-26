#include "gameboard.h"
#include <iostream>

#include <unistd.h>
#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QBrush>
#include "paintercube.h"

GameBoard::GameBoard(QWidget *parent):
    QGraphicsView(parent),
    board(amount_point)
{
    scene = new QGraphicsScene;
    setScene(scene);

    current_player = 1;
}

GameBoard::~GameBoard()
{
    delete scene;
}

void GameBoard::set_parameters(int side, bool g_with_pc)
{
    size_side_px = side ;
    size_cells = side/ amount_point;

    game_with_pc = g_with_pc;

    setFixedSize(size_side_px,size_side_px);
    QPixmap image_board(":/images/image/board.png");
    image_board = image_board.scaled(this->width(),this->height());
    scene->setSceneRect(0,0,image_board.width(),image_board.height());
    scene->setBackgroundBrush(image_board);
}

void GameBoard::set_parameters(int side, bool g_with_pc, bool pc_first, int level_dif)
{
    size_side_px = side ;
    size_cells = side/ amount_point;

    game_with_pc = g_with_pc;
    computer_first = pc_first;
    difficulty = level_dif;
    level_recur = difficulty;
    finished = false;

    switch (difficulty)
    {
        case 1: time_deley = 400; break;
        case 2: time_deley = 200; break;
        case 3: time_deley = 50; break;
    }

    setFixedSize(size_side_px,size_side_px);
    QPixmap image_board(":/images/image/board.png");
    image_board = image_board.scaled(this->width(),this->height());
    scene->setSceneRect(0,0,image_board.width(),image_board.height());
    scene->setBackgroundBrush(image_board);

    if(pc_first)
    {
        PainterCube::paint_first_cube(scene, 1 * size_cells, 0 * size_cells, size_cells, size_cells*2);
        board.set_adj_cells(1, 9, current_player);
        current_player = 2;
    }
}

void GameBoard::download_game(int side, bool g_with_pc, bool pc_first1, int diffic, int current, bool finish, bool pl_win, Board b)
{
    size_side_px = side ;
    size_cells = side/ amount_point;

    game_with_pc = g_with_pc;
    computer_first = pc_first1;
    difficulty = diffic;
    current_player = current;
    finished = finish;
    player_win = pl_win;
    board = b;

    level_recur = difficulty;
    if(game_with_pc)
    {
        switch (difficulty)
        {
            case 1: time_deley = 400; break;
            case 2: time_deley = 200; break;
            case 3: time_deley = 50; break;
        }
    }

    setFixedSize(size_side_px,size_side_px);
    QPixmap image_board(":/images/image/board.png");
    image_board = image_board.scaled(this->width(),this->height());
    scene->setSceneRect(0,0,image_board.width(),image_board.height());
    scene->setBackgroundBrush(image_board);

    view_board();
}

void GameBoard::view_board()
{
    for (int i=0; i < board.get_size() ; i++ )
    {
       if(board.get_number_player_cells(i) != -1)
       {
           if (i < board.get_index_edj_cells(i))
           {
               int row = i / board.get_amount_point_side();
               int column = i % board.get_amount_point_side();

               if(board.get_number_player_cells(i) == 1)
                   PainterCube::paint_first_cube(scene, column * size_cells, row * size_cells, size_cells, size_cells*2);
               else
                   PainterCube::paint_second_cube(scene, column * size_cells, row * size_cells, size_cells*2, size_cells);
           }
       }
    }
}

void GameBoard::mousePressEvent(QMouseEvent *event)
{
    int mouse_x = event->position().x();
    int mouse_y = event->position().y();

    if(game_with_pc)
    {
        player_vs_computer(mouse_x, mouse_y);
    }
    else
    {
        player_vs_player(mouse_x, mouse_y);
    }

}

void GameBoard::player_vs_player(int mouse_x, int mouse_y)
{
        //перевіряєм чи хід можливий
    if(board.is_move(current_player))
    {

            // перевірка якого гравця хід
        if(current_player == 1)
        {
                int column_cells = mouse_x / size_cells;
                int row_cell1;
                int row_cell2;

                    // визначення номерів двох вибраних клітинок
                if (mouse_y % size_cells < size_cells/2)
                {
                    row_cell2 = mouse_y / size_cells;
                    row_cell1 = row_cell2-1;
                }
                else
                {
                    row_cell1 = mouse_y / size_cells;
                    row_cell2 = row_cell1+1;
                }

                int index1 =  row_cell1 * amount_point  + column_cells;
                int index2 =  row_cell2 * amount_point  + column_cells;

                    // перевірка можливості фарбування вибраних двох клітинок
                if (row_cell1 >= 0 && row_cell2 < amount_point && board.is_cell_empty(index1) && board.is_cell_empty(index2))
                {
                    PainterCube::paint_first_cube(scene, column_cells * size_cells, row_cell1 * size_cells, size_cells, size_cells*2);
                    board.set_adj_cells(index1, index2, current_player);
                    current_player = 2;

                }

        }
        else
        {
                int row_cells = mouse_y / size_cells;
                int column_cell1;
                int column_cell2;

                    // визначення номерів двох вибраних клітинок
                if (mouse_x % size_cells < size_cells/2)
                {
                    column_cell2 = mouse_x / size_cells;
                    column_cell1 = column_cell2-1;
                }
                else
                {
                    column_cell1 = mouse_x / size_cells;
                    column_cell2 = column_cell1+1;
                }

                int index1 =  row_cells * amount_point  + column_cell1;
                int index2 =  row_cells * amount_point  + column_cell2;

                    // перевірка можливості фарбування вибраних двох клітинок
                if ((index1/amount_point == index2/amount_point ) && board.is_cell_empty(index1) && board.is_cell_empty(index2))
                {
                    PainterCube::paint_second_cube(scene, column_cell1 * size_cells, row_cells * size_cells, size_cells*2, size_cells);
                    board.set_adj_cells(index1, index2, current_player);
                    current_player = 1;
                }

        }

    }

        // перевіряєм чи ігра закінчена
    if(!(board.is_move(current_player)))
    {
            // визначаєм переможця
        if(current_player == 1)
        {
            QString text = "Переміг другий гравець(червоний)";
            QString title = "Ігра закінчилася";
            QMessageBox:: about(this,title,text);
        }
        else
        {
            QString text = "Переміг перший гравець(синій)";
            QString title = "Ігра закінчилася";
            QMessageBox:: about(this,title,text);
        }
    }

}

void GameBoard::player_vs_computer(int mouse_x, int mouse_y)
{
    if(computer_first)
        player_move_second(mouse_x,mouse_y);
    else
        player_move_first(mouse_x,mouse_y);

}

void GameBoard::player_move_second(int mouse_x, int mouse_y)
{
    if(board.is_move(current_player))
    {

            // хід гравця
        if(current_player == 2)
        {
                int row_cells = mouse_y / size_cells;
                int column_cell1;
                int column_cell2;

                    // визначення номерів двох вибраних клітинок
                if (mouse_x % size_cells < size_cells/2)
                {
                    column_cell2 = mouse_x / size_cells;
                    column_cell1 = column_cell2-1;
                }
                else
                {
                    column_cell1 = mouse_x / size_cells;
                    column_cell2 = column_cell1+1;
                }

                int index1 =  row_cells * amount_point  + column_cell1;
                int index2 =  row_cells * amount_point  + column_cell2;

                    // перевірка можливості фарбування вибраних двох клітинок
                if ((index1/amount_point == index2/amount_point ) && board.is_cell_empty(index1) && board.is_cell_empty(index2))
                {
                    PainterCube::paint_second_cube(scene, column_cell1 * size_cells, row_cells * size_cells, size_cells*2, size_cells);
                    board.set_adj_cells(index1, index2, current_player);
                    current_player = 1;

                    QTimer::singleShot(time_deley, this, &GameBoard::pc_move_first);
                }

        }

    }

    else
    {
        if (player_win)
        {
            QString text = "ТИ ПЕРЕМІГ";
            QString title = "Ігра закінчилася";
            QMessageBox:: about(this,title,text);
        }
        else
        {
            QString text = "ТИ ПРОГРАВ";
            QString title = "Ігра закінчилася";
            QMessageBox:: about(this,title,text);
        }
    }
}

void GameBoard::pc_move_first()
{
    if(board.is_move(current_player))
    {
        // хід компютера
        EnemyComputer computer(board, level_recur, 1, 2, board.get_size(), board.get_amount_point_side());

        pair<int,int> inds = computer.alfa_beta_pruning();
        int index1;
        int index2;
        if(inds.first < inds.second)
        {
            index1 = inds.first;
            index2 = inds.second;
        }
        else
        {
            index1 = inds.second;
            index2 = inds.first;
        }
        int column = index1 % amount_point;
        int row = index1 / amount_point;

        PainterCube::paint_first_cube(scene, column * size_cells, row * size_cells, size_cells, size_cells*2);
        board.set_adj_cells(index1, index2, current_player);
        current_player = 2;

        if(!board.is_move(current_player))
        {
            QString text = "ТИ ПРОГРАВ";
            QString title = "Ігра закінчилася";
            QMessageBox:: about(this,title,text);
            finished = true;
            player_win = false;
        }
    }
    else
    {
        QString text = "ТИ ПЕРЕМІГ";
        QString title = "Ігра закінчилася";
        QMessageBox:: about(this,title,text);
        finished = true;
        player_win = true;
    }
}

void GameBoard::player_move_first(int mouse_x, int mouse_y)
{
    if(board.is_move(current_player))
    {
        if (current_player == 1)
        {
            // хід гравця
            int column_cells = mouse_x / size_cells;
            int row_cell1;
            int row_cell2;

                // визначення номерів двох вибраних клітинок
            if (mouse_y % size_cells < size_cells/2)
            {
                row_cell2 = mouse_y / size_cells;
                row_cell1 = row_cell2-1;
            }
            else
            {
                row_cell1 = mouse_y / size_cells;
                row_cell2 = row_cell1+1;
            }

            int index1 =  row_cell1 * amount_point  + column_cells;
            int index2 =  row_cell2 * amount_point  + column_cells;

                // перевірка можливості фарбування вибраних двох клітинок
            if (row_cell1 >= 0 && row_cell2 < amount_point && board.is_cell_empty(index1) && board.is_cell_empty(index2))
            {
                PainterCube::paint_first_cube(scene, column_cells * size_cells, row_cell1 * size_cells, size_cells, size_cells*2);
                board.set_adj_cells(index1, index2, current_player);
                current_player = 2;

                QTimer::singleShot(time_deley, this, &GameBoard::pc_move_second);

            }
        }

    }
    else
    {
        if (player_win)
        {
            QString text = "ТИ ПЕРЕМІГ";
            QString title = "Ігра закінчилася";
            QMessageBox:: about(this,title,text);
        }
        else
        {
            QString text = "ТИ ПРОГРАВ";
            QString title = "Ігра закінчилася";
            QMessageBox:: about(this,title,text);
        }

    }
}



void GameBoard::pc_move_second()
{
    if(board.is_move(current_player))
    {
        // хід компютера
        EnemyComputer computer(board, level_recur, 2, 1, board.get_size(), board.get_amount_point_side());

        pair<int,int> inds = computer.alfa_beta_pruning();
        int index1;
        int index2;
        if(inds.first <inds.second)
        {
            index1 = inds.first;
            index2 = inds.second;
        }
        else
        {
            index1 = inds.second;
            index2 = inds.first;
        }
        int column = index1 % amount_point;
        int row = index1 / amount_point;

        PainterCube::paint_second_cube(scene, column * size_cells, row * size_cells, size_cells*2, size_cells);
        board.set_adj_cells(index1, index2, current_player);
        current_player = 1;

        if(!board.is_move(current_player))
        {
            QString text = "ТИ ПРОГРАВ";
            QString title = "Ігра закінчилася";
            QMessageBox:: about(this,title,text);
            finished = true;
            player_win = false;
        }
    }
    else
    {
        QString text = "ТИ ПЕРЕМІГ";
        QString title = "Ігра закінчилася";
        QMessageBox:: about(this,title,text);
        finished = true;
        player_win = true;
    }
}

void GameBoard::resizeEvent(QResizeEvent *event)
{
    fitInView(sceneRect(), Qt::IgnoreAspectRatio);
}

bool GameBoard::get_game_with_pc()
{
    return game_with_pc;
}
bool GameBoard::get_computer_first()
{
    return computer_first;
}
int GameBoard::get_difficulty()
{
    return difficulty;
}
int GameBoard::get_current_player()
{
    return current_player;
}
bool GameBoard::get_finished()
{
    return finished;
}
bool GameBoard::get_player_win()
{
    return player_win;
}
Board GameBoard::get_board()
{
    return board;
}
