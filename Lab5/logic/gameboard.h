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
    bool computer_first;    // чи перший ходить компютер
    int difficulty;         // рівень складності (1 легкий, 2 середній, 3 тяжкий)

    int level_recur;        // глибина рекурсії рівна складності
    int time_deley = 10;    // час затримки перд ходом компютера

    int current_player;      //номер гравця чий хід

    bool finished;          // гра закінчена
    bool player_win;        //гравець виграв

    QGraphicsScene *scene;  // покажчик на графічну сцену

    Board board;            //доска (дані з'єднань)

public:
    GameBoard(QWidget *parent = nullptr);
    ~GameBoard();

        //Метод, що використовується для встановлення розміру, ігрового поля і параметра g_with_pc(false) виклик при грі 2 гравців
    void set_parameters(int side, bool g_with_pc);
        //Метод, що використовується для встановлення розміру, ігрового поля і параметра g_with_pc(true) виклик при грі з пк і встановлення порядку ходу, рівня тяжкості
    void set_parameters(int side, bool g_with_pc, bool pc_first, int level_dif);

        //встановлення параметрів загруженої гри
    void download_game(int side, bool g_with_pc, bool pc_first1, int diffic, int current, bool finish, bool pl_win, Board b);

protected:
         // метод що реагує на клік миші по цьому класу віджету GameBoard на вікні GameWindow для ходу гравця
    virtual void mousePressEvent(QMouseEvent *event);

        //Метод, який при зміні розміру області перегляду масштабує сцену
    void resizeEvent(QResizeEvent *event);

private:
        // гра йде гравець проти гравця
    void player_vs_player(int mouse_x, int mouse_y);


        // гра йде гравець проти комп'ютера
    void player_vs_computer(int mouse_x, int mouse_y);

        // функція ходу гравця коли він ходить другим граючи з компютером і асинхронний виклик першого ходу компютера pc_move_first
    void player_move_second(int mouse_x, int mouse_y);
    void pc_move_first();

        // функція ходу гравця коли він ходить першим граючи з компютером і асинхронний виклик другого ходу компютера pc_move_second
    void player_move_first(int mouse_x, int mouse_y);
    void pc_move_second();

        //відображення ігрового поля загруженої гри
    void view_board();

public:
    bool get_game_with_pc();
    bool get_computer_first();
    int get_difficulty();
    int get_current_player();
    bool get_finished();
    bool get_player_win();
    Board get_board();
};

#endif // GAMEBOARD_H
