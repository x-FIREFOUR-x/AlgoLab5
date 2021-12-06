#include "enemycomputer.h"

StateBoard::StateBoard(Board bord)
{
   board = bord;
   value = -1;
   terminal_value = 0;
}

void StateBoard::calculate_value(int number_computer_move)
{
    value = 0;
    int comp_value= 0;
    int player_value=0;
    int amount_point_side = board.get_amount_point_side();
        //коли компютер ходить першимм
    if (number_computer_move == 1)
    {
        for(int i =0; i <board.get_size(); i++)
        {
                // кількість можливих ходів компютера
            if ((i / amount_point_side) != (amount_point_side - 1) )        // не належить останньому рядку
            {
                if(board.get_number_player_cells(i) == -1 && board.get_number_player_cells(i+amount_point_side) == -1)
                {
                    comp_value++;
                }
            }
                // кількість можливих ходів гравця
            if ((i % amount_point_side) != (amount_point_side - 1) )        // і не належить останній колонці
            {
                if(board.get_number_player_cells(i) == -1 && board.get_number_player_cells(i+1) == -1)
                {
                    player_value++;
                }
            }

        }

        value = comp_value - player_value;
    }
        //коли компютер ходить другим
    else
    {
        for(int i =0; i < board.get_size(); i++)
        {
                // кількість можливих ходів компютера
            if ((i % amount_point_side) != (amount_point_side - 1) )        // і не належить останній колонці
            {
                if(board.get_number_player_cells(i) == -1 && board.get_number_player_cells(i+1) == -1)
                {
                    comp_value++;
                }
            }
                // кількість можливих ходів гравця
            if ((i / amount_point_side) != (amount_point_side - 1) )   // не належить останньому рядку
            {
                if(board.get_number_player_cells(i) == -1 && board.get_number_player_cells(i+amount_point_side) == -1)
                {
                    player_value++;
                }
            }
        }
        value = comp_value - player_value;
    }

}

void StateBoard::calculate_terminal_value(int number_computer, int depth_of_recourse)
{
    if (number_computer == 1)       // цінність ходу визначається кількістб можливих ходів після власного ходу
    {
        if(depth_of_recourse % 2 != 0) // стан півходу з якого робить хід гравець
        {
            if(board.is_move(2))             // перевіряєм чи хід 2гравця (гравця) можливий (компютер 1 гравець)
                terminal_value =0;
            else
                terminal_value = 1;
        }
        else
        {
            if(board.is_move(1))             // перевіряєм чи хід 1гравця (компютера) можливий (компютер 1 гравець)
                terminal_value =0;
            else
                terminal_value = -1;
        }
    }
    else
    {
        if(depth_of_recourse % 2 != 0) // стан півходу з якого робить хід гравець
        {
            if(board.is_move(1))             // перевіряєм чи хід 1гравця (гравця) можливий (компютер 2 гравець)
                terminal_value =0;
            else
                terminal_value = 1;
        }
        else
        {
            if(board.is_move(2))             // перевіряєм чи хід 2гравця (компютера) можливий (компютер 2 гравець)
                terminal_value =0;
            else
                terminal_value = -1;
        }
    }

}

EnemyComputer::EnemyComputer(Board gboard, int depth, int num_computer, int num_player, int s, int amount_pt_sd)
{
    row = make_shared<StateBoard>(gboard);
    //shared_ptr<StateBoard> p(StateBoard(gboard));
    //row.swap(p);
    max_depth = depth;
    number_computer = num_computer;
    number_player = num_player;
    current_depth = 0;
    size = s;
    amount_point_side = amount_pt_sd;
    value =-1;
    terminate_value =0;
    indexs_move.first = -1;
    indexs_move.second = -1;
}

pair<int,int> EnemyComputer:: alfa_beta_pruning()
{
    pair<int,int> vals;
    for(int i =0; i < size; i++)
    {
        Board b = row->board;

        bool succes_adj;
        if (number_computer == 1)
             succes_adj = b.set_adj_cells(i, i+amount_point_side, number_computer);
        else
            succes_adj = b.set_adj_cells(i, i+1, number_computer);

        if (succes_adj)
        {
            row->ptrs_board.push_back(make_shared<StateBoard>(b));
            pair<int,int> father_val(row->value,row->terminal_value);
            vals = min_move(row->ptrs_board[row->ptrs_board.size()-1], father_val);
            if(vals.second == 1)
            {
                terminate_value =1;
                value = amount_point_side * (amount_point_side - 1);
                indexs_move.first = i;
                if(number_computer == 1)
                    indexs_move.second = i +amount_point_side;
                else
                    indexs_move.second = i +1;
            }
            else
                if(value < vals.first && vals.second == 0)
                {
                     value = vals.first;
                     indexs_move.first = i;
                     if(number_computer == 1)
                         indexs_move.second = i +amount_point_side;
                     else
                         indexs_move.second = i +1;
                }
        }


        if(row->terminal_value == 1)
        {
            break;
        }

    }

    if(indexs_move.first == -1 || indexs_move.first > size)
    {
        indexs_move = search_last(row->board);
    }
    return indexs_move;
}

pair<int,int> EnemyComputer::max_move(shared_ptr<StateBoard> cur_node, pair<int,int>father_value)
{
    pair<int,int> vals;
    current_depth++;
        // перевірка на термінальний стан
    if(cur_node->board.is_move(number_computer))
    {
            // перевірка глибини
        if(current_depth < max_depth)
        {
                // перебір можливих ходів що зробить гравець
            for(int i =0; i < size; i++)
            {
                Board b = cur_node->board;

                bool succes_adj;
                if (number_computer == 1)
                     succes_adj = b.set_adj_cells(i, i+amount_point_side, number_computer);
                else
                    succes_adj = b.set_adj_cells(i, i+1, number_computer);

                if (succes_adj)
                {
                    cur_node->ptrs_board.push_back(make_shared<StateBoard>(b));
                    pair<int,int> father_val(cur_node->value, cur_node->terminal_value);
                    vals = min_move(cur_node->ptrs_board[cur_node->ptrs_board.size()-1], father_val);

                        //максимізатор вибирає виграш
                    if(vals.second == 1)
                    {
                        cur_node->terminal_value =1;
                        cur_node->value = amount_point_side * (amount_point_side - 1);
                    }
                        // максимізатор вибирає хід з найбільшою цінністю
                    else
                        if (number_computer == 1)
                        {
                            if(cur_node->value < vals.first && cur_node->value != -1)
                            {
                                cur_node->value = vals.first;
                                cur_node->value =0;
                            }
                        }
                        else
                        {
                            if(cur_node->value < vals.first && cur_node->value != -1)
                            {
                                cur_node->value = vals.first;
                                cur_node->value =0;
                            }
                        }

                }


                    //відсікання
                if(cur_node->terminal_value == 1 || (vals.first >= father_value.first && father_value.first != -1))
                {
                    break;
                }

            }

            return pair<int,int>(cur_node->value, cur_node->terminal_value);
        }
            // перерахунок листової цінності
        else
        {
            cur_node->calculate_value(number_computer);
            pair<int,int> vals(cur_node->value, 0);
            return vals;
        }
    }
        // термінальний стан програш компютера виграш гравця (термінал -1)
    else
    {
        pair<int,int> vals(-2, -1);
        return vals;
    }
}

pair<int,int> EnemyComputer::min_move(shared_ptr<StateBoard> cur_node, pair<int,int>father_value)
{
    current_depth++;
    pair<int,int> vals;

        // перевірка на термінальний стан
    if(cur_node->board.is_move(number_player))
    {
            // перевірка глибини
        if(current_depth < max_depth)
        {
                // перебір можливих ходів що зробить гравець
            for(int i =0; i < size; i++)
            {

                Board b = cur_node->board;
                bool succes_adj;
                if(number_computer == 1)
                    succes_adj = b.set_adj_cells(i, i+1, number_player);
                else
                    succes_adj = b.set_adj_cells(i, i+amount_point_side, number_player);

                if (succes_adj)
                {

                    cur_node->ptrs_board.push_back(make_shared<StateBoard>(b));
                    pair<int,int> father_val(cur_node->value, cur_node->terminal_value);
                    vals = max_move(cur_node->ptrs_board[cur_node->ptrs_board.size()-1], father_val);

                        // мінімізатор вибирає хід де максімізатор програє
                    if(vals.second == -1)
                    {
                        cur_node->terminal_value = -1;
                        cur_node->value = -1;
                    }
                    else
                            // мінімізатор вибирає хід з найменшою цінністю
                        if(cur_node->value > vals.first && cur_node->value != -1)
                        {
                             cur_node->value = vals.first;
                             cur_node->value =0;
                        }

                    }


                    //відсікання
                if(cur_node->terminal_value == -1 || (vals.first <= father_value.first && father_value.first != -1))
                {
                    break;
                }


            }
             return pair<int,int>(cur_node->value, cur_node->terminal_value);

        }
            // перерахунок листової цінності
        else
        {
            cur_node->calculate_value(number_computer);
            pair<int,int> vals(cur_node->value, 0);
            return vals;
        }
    }
        // термінальний стан програш гравця а отже виграш компютера (термінальний 1)
    else
    {
        int max_value = amount_point_side * (amount_point_side-1);
        pair<int,int> vals(max_value, 1);
        return vals;
    }
}

pair<int, int>  EnemyComputer::search_last(Board board)
{
    pair<int,int> inds;
    for(int i =0; i <size; i++ )
    {
        if(number_computer == 1)
        {
            if (i / amount_point_side != amount_point_side - 1)
                if(board.is_cell_empty(i) && board.is_cell_empty(i+amount_point_side))
                {
                    inds.first = i;
                    inds.second = i + amount_point_side;
                }
        }
        else
        {
            if (i / amount_point_side == (i + 1) / amount_point_side)
                if(board.is_cell_empty(i) && board.is_cell_empty(i+1))
                {
                    inds.first = i;
                    inds.second = i + 1;
                }
        }
    }
    return inds;
}
