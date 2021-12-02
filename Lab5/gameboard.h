#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsView>
#include <QGraphicsItem>

class GameBoard: public QGraphicsView
{
    int amount_point;       // кількість точок (на стороні)
    int size_side_px;       // розмір сторони в пікседях
    QGraphicsScene *scene;  // покажчик на графічну сцену
public:
    GameBoard(QWidget *parent = nullptr);
    ~GameBoard();

protected:
    void mouse_click_event(QMouseEvent *e);
};

#endif // GAMEBOARD_H
