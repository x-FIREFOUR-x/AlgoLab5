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
    int amount_point_side = board.get_amount_point_side();
    if (number_computer_move == 1)
    {
        for(int i =0; i <board.get_size(); i++)
        {
            if (i / amount_point_side != amount_point_side - 1 )
            {
                if(board.get_number_player_cells(i) == -1 && board.get_number_player_cells(i+amount_point_side) == -1)
                {
                    value++;
                }
            }

        }

    }
    else
    {
        for(int i =0; i < board.get_size(); i++)
        {
            if (i % amount_point_side != amount_point_side - 1 )
            {
                if(board.get_number_player_cells(i) == -1 && board.get_number_player_cells(i+1) == -1)
                {
                    value++;
                }
            }
        }
    }

}

void StateBoard::calculate_terminal_value(int number_computer, int depth_of_recourse)
{
    if (number_computer == 1)
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

EnemyComputer::EnemyComputer(Board gboard, int depth, int num_computer, int s, int amount_pt_sd)
{
    unique_ptr<StateBoard> p(new StateBoard(gboard)) ;
    row.swap(p) ;
    max_depth = depth;
    number_computer = num_computer;
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
        bool succes_adj = b.set_adj_cells(i, i+amount_point_side, number_computer);
        if (succes_adj)
        {
            row->ptrs_board.push_back(new StateBoard(b));
            vals = min_move(row->ptrs_board[row->ptrs_board.size()-1]);

        }
        if(vals.second == 1)
        {
            terminate_value =1;
            value = amount_point_side * (amount_point_side - 1);
            indexs_move.first = i;
            indexs_move.second = i +amount_point_side;
        }
        else
            if(value < vals.first)
            {
                 value = vals.first;
                 indexs_move.first = i;
                 indexs_move.second = i +amount_point_side;
            }

    }

    return indexs_move;
}

pair<int,int> EnemyComputer::max_move(StateBoard* cur_node)
{
    current_depth++;
    pair<int,int> vals;
    if(cur_node->board.is_move(number_computer))
    {
        if(current_depth <= max_depth)
        {

            for(int i =0; i < size; i++)
            {
                Board b = row->board;
                bool succes_adj = b.set_adj_cells(i, i+amount_point_side, number_computer);
                if (succes_adj)
                {
                    row->ptrs_board.push_back(new StateBoard(b));
                    vals = min_move(row->ptrs_board[row->ptrs_board.size()-1]);

                }

                if(vals.second == 1)
                {
                    cur_node->terminal_value =1;
                    cur_node->value = amount_point_side * (amount_point_side - 1);
                }
                else
                    if(cur_node->value < vals.first)
                    {
                         cur_node->value = vals.first;
                         cur_node->value =0;
                    }
            }

            return pair<int,int>(cur_node->value, cur_node->terminal_value);
        }
        else
        {
            cur_node->calculate_value(number_computer);
            pair<int,int> vals(cur_node->value, 0);
            return vals;
        }
    }
    else
    {
        pair<int,int> vals(-1, -1);
        return vals;
    }
}

pair<int,int> EnemyComputer::min_move(StateBoard* cur_node)
{
    current_depth++;
    pair<int,int> vals;

        // перевірка на териінальний стан
    if(cur_node->board.is_move(number_player))
    {
            // перевірка глибини
        if(current_depth <= max_depth)
        {
                // перебір можливих ходів що зробить гравець
            for(int i =0; i < size; i++)
            {
                Board b = row->board;
                bool succes_adj = b.set_adj_cells(i, i+1, number_player);
                if (succes_adj)
                {
                    row->ptrs_board.push_back(new StateBoard(b));
                    vals = max_move(row->ptrs_board[row->ptrs_board.size()-1]);

                }

                if(vals.second == -1)
                {
                    cur_node->terminal_value = -1;
                    cur_node->value = -1;
                }
                else
                    if(cur_node->value > vals.first)
                    {
                         cur_node->value = vals.first;
                         cur_node->value =0;
                    }

            }

             return pair<int,int>(cur_node->value, cur_node->terminal_value);

        }
        else
        {
            cur_node->calculate_value(number_computer);
            pair<int,int> vals(cur_node->value, 0);
            return vals;
        }
    }
    else
    {
        int max_value = amount_point_side * (amount_point_side-1);
        pair<int,int> vals(max_value, 1);
        return vals;
    }
}
