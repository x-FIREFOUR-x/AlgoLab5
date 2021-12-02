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

void GameBoard::mouse_click_event(QMouseEvent *e)
{
    int mouse_x = e->position().x();
    int mouse_y = e->position().y();
}
