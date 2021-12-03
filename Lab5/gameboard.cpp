#include "gameboard.h"

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

void GameBoard::set_parameters(int side)
{
    size_side_px = side ;
    size_cells = side/ amount_point;

    setFixedSize(size_side_px,size_side_px);
    QPixmap image_board(":/images/image/board.png");
    image_board = image_board.scaled(this->width(),this->height());
    scene->setSceneRect(0,0,image_board.width(),image_board.height());
    scene->setBackgroundBrush(image_board);
}

void GameBoard::mousePressEvent(QMouseEvent *event)
{
        //перевіряєм чи хід можливий
    if(board.is_move(current_player))
    {
        int mouse_x = event->position().x();
        int mouse_y = event->position().y();

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

                    // перевірка можливості фарбування вибраних двох клітинок
                if (row_cell1 >= 0 && row_cell2 < amount_point)
                {
                    PainterCube::paint_first_cube(scene, column_cells * size_cells, row_cell1 * size_cells, size_cells, size_cells*2);
                    int index1 =  row_cell1 * amount_point  + column_cells;
                    int index2 =  row_cell2 * amount_point  + column_cells;
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

                    // перевірка можливості фарбування вибраних двох клітинок
                if (column_cell1 / amount_point == column_cell2 / amount_point)
                {
                    PainterCube::paint_second_cube(scene, column_cell1 * size_cells, row_cells * size_cells, size_cells*2, size_cells);
                    int index1 =  row_cells * amount_point  + column_cell1;
                    int index2 =  row_cells * amount_point  + column_cell2;
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

void GameBoard::resizeEvent(QResizeEvent *event)
{
    fitInView(sceneRect(), Qt::IgnoreAspectRatio);
}
