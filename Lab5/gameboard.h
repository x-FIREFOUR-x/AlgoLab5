#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QVector>
#include "board.h"
#include "enemycomputer.h"

class GameBoard: public QGraphicsView
{
    int amount_point = 8;    // кількість точок (на стороні)
    int size_side_px;        // розмір сторони в пікселях
    int size_cells;          // розмір одної клітинки

    bool game_with_pc;      //тип гри з комп'ютером чи два гравці
    bool computer_first;          // чи перший ходить компютер
    int difficulty;         // рівень складності (1 легкий, 2 середній, 3 тяжкий)

    int current_player;      //номер гравця чий хід

    QGraphicsScene *scene;  // покажчик на графічну сцену

    Board board;            //доска (дані з'єднань)

public:
    GameBoard(QWidget *parent = nullptr);
    ~GameBoard();

        //Метод, що використовується для встановлення розміру, ігрового поля
    void set_parameters(int side, bool g_with_pc);
    void set_parameters(int side, bool g_with_pc, bool pc_first, int level_dif);

protected:
         // метод що реагує на клік миші по цьому класу віджету GameBoard на вікні GameWindow
    virtual void mousePressEvent(QMouseEvent *event);

        //Метод, який при зміні розміру області перегляду масштабує сцену
    void resizeEvent(QResizeEvent *event);

private:
        // гра йде гравець проти гравця
    void player_vs_player(int mouse_x, int mouse_y);

        // гра йде гравець проти комп'ютера
    void player_vs_computer(int mouse_x, int mouse_y);
};

#endif // GAMEBOARD_H
