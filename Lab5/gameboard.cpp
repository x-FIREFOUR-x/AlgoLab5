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
    int mouse_x = event->position().x();
    int mouse_y = event->position().y();

    QString text = QString::number(mouse_x)+ " " + QString::number(mouse_y) + " " + QString::number(size_cells) + " " +QString::number(size_cells*2);
    QString title;
    QMessageBox:: about(this,title,text);

    //PainterCube::paint_second_cube(scene, 0, 0, size_cells);
    if(current_player == 1)
    {

        PainterCube::paint_first_cube(scene, mouse_x, mouse_y, size_cells, size_cells*2);
        current_player = 2;
    }
    else
    {
        PainterCube::paint_second_cube(scene, mouse_x, mouse_y, size_cells*2, size_cells);
        current_player = 1;
    }

}

void GameBoard::resizeEvent(QResizeEvent *event)
{
    fitInView(sceneRect(), Qt::IgnoreAspectRatio);
}
