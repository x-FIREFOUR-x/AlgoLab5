#ifndef BOARD_H
#define BOARD_H
#include <vector>


using namespace std;
class Board
{
private:
    int amount_point_side;      // кількість точок(клітинок) на стороні поля
    int size;                   // всього точок на полі (клітинок)

        //масив доски(поля) рядки= к-ть клітинок на полі стовбці = 2 (індекс суміжної клітинки, номер гравця власника клітинки) (-1 відсутність суміжної власника)
    vector<pair<int,int>> arr_board;


public:
    Board(){};
    Board(int amount_p);
    Board(const Board& obj_board);

        // повернути розмір доски кількість клітинок
    int get_size();

    int get_amount_point_side();

        //витягнути індекс з'єднаної(покрашеної одним блоком) клітинки з клітинкою номера index (-1 якщо не з'єднано)
    int get_index_edj_cells(int index);

         //витягнути номер гравця що закрасив клітинку блоком (1,2, -1 якщо не з'єднано)
    int get_number_player_cells(int index);

        //з'єднати клітинки з індексами index1, index2 блоком гравця number_player
    bool set_adj_cells(int index1, int index2, int number_player);

        // перевірка чи в гравця номер number_player є хід
    bool is_move(int number_player);

        // перевірка чи клітинка номер index не зайняти блоками
    bool is_cell_empty(int index);


    void console_log();
};

#endif // BOARD_H
