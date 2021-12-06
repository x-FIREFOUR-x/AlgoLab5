#ifndef ENEMYCOMPUTER_H
#define ENEMYCOMPUTER_H

#include "board.h"
#include <iostream>
#include <memory>

struct StateBoard
{
    Board board;
    vector<shared_ptr<StateBoard>> ptrs_board;
    int value;              // цінність даного стану гри для противника комп'ютера
    int terminal_value;     // термінальна цінність стану доски(гри) 0 не кінець гри 1 перемога комп'ютера -1 програш комп'ютера

    int last_move;          // верхня координа блока останнього зарезервованого ходу на цьому рівні рекурсії
    StateBoard(Board bord);

        // підрахунок цінності стану гри для компютера якщо він грає гравцем номе number_computer_move(1||2)
    void calculate_value(int number_compuer_move);

        // підрахунок термінального стану (чи є таким і в чию користь)
    void calculate_terminal_value(int number_computer, int depth_of_recourse);
};

using namespace std;
class EnemyComputer
{
private:
    shared_ptr<StateBoard> row;   //вказівник на вершину дерева ходів гри(стан гри на даний момент перед можливим ходом комп'ютера)

    int max_depth;                //максимальна глибина рекурсії бачення ходів наперед компютером
    int current_depth;            //поточний рівень заглиблення

    int number_computer;          //номер ходів компютера (1 || 2)
    int number_player;           //номер ходів гравця (1 || 2)

    int size;                   //кількість клітинок на полі
    int amount_point_side;      // кількість точок на одній стороні

    int value;                    // остаточна цінність
    int terminate_value;          // термінальна цінність
    pair<int,int> indexs_move;    // індекси двох кліток для ходу

public:
    EnemyComputer(Board gboard, int depth, int num_computer, int num_player, int s, int amount_pt_sd);

    pair<int,int> alfa_beta_pruning();      // альфа-бета отсікання
    pair<int,int> max_move(shared_ptr<StateBoard> cur_node, pair<int,int>father_value);     // рекурсивний виклик макс
    pair<int,int> min_move(shared_ptr<StateBoard> cur_node, pair<int,int>father_value);     // рекурсивний виклик мін
    pair<int, int> search_last(Board board);        // пошук останнього ходу
};

#endif // ENEMYCOMPUTER_H
