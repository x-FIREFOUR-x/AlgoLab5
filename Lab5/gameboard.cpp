#include "gameboard.h"

#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QBrush>

GameBoard::GameBoard(QWidget *parent):
    QGraphicsView(parent)
{
    scene = new QGraphicsScene;
    setScene(scene);
}

GameBoard::~GameBoard()
{
    delete scene;
}

void GameBoard::set_parameters(int side)
{
    size_side_px = side ;
    setFixedSize(size_side_px,size_side_px);
    QPixmap image_board(":/images/image/board.png");
    scene->setSceneRect(0,0,image_board.width(),image_board.height());
    scene->setBackgroundBrush(image_board);
}

void GameBoard::mouse_click_event(QMouseEvent *event)
{
    int mouse_x = event->position().x();
    int mouse_y = event->position().y();
}

void GameBoard::resizeEvent(QResizeEvent *event)
{
    fitInView(sceneRect(), Qt::IgnoreAspectRatio);
}
