#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QVector>
#include "board.h"

class GameBoard: public QGraphicsView
{
    int amount_point = 8;    // кількість точок (на стороні)
    int size_side_px;        // розмір сторони в пікселях
    int size_cells;          // розмір одної клітинки

    int current_player;      //номер гравця чий хід

    QGraphicsScene *scene;  // покажчик на графічну сцену

    Board board;            //доска (дані з'єднань)

public:
    GameBoard(QWidget *parent = nullptr);
    ~GameBoard();

        //Метод, що використовується для встановлення розміру, ігрового поля
    void set_parameters(int side);

protected:
         // метод що реагує на клік миші по цьому класу віджету GameBoard на вікні GameWindow
    virtual void mousePressEvent(QMouseEvent *event);

        //Метод, який при зміні розміру області перегляду масштабує сцену
    void resizeEvent(QResizeEvent *event);
};

#endif // GAMEBOARD_H
