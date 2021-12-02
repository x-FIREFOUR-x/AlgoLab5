#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QVector>

class GameBoard: public QGraphicsView
{
    int amount_point = 8;       // кількість точок (на стороні)
    int size_side_px;       // розмір сторони в пікселях

    QGraphicsScene *scene;  // покажчик на графічну сцену




public:
    GameBoard(QWidget *parent = nullptr);
    ~GameBoard();

    void set_parameters(int side); //Метод, що використовується для встановлення розміру, ігрового поля

protected:
    void mouse_click_event(QMouseEvent *event);

     void resizeEvent(QResizeEvent *event);    //Метод, який при зміні розміру області перегляду масштабує сцену
};

#endif // GAMEBOARD_H
