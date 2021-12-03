#include "board.h"

#include <iostream>
Board::Board(int amount_p)
{
    amount_point_side = amount_p;
    size = amount_point_side*amount_point_side;
    arr_board.assign(size, pair<int,int>(-1,-1));
}

int Board::get_size()
{
    return size;
}

int Board::get_index_edj_cells(int index)
{
    return arr_board[index].first;
}

int Board::get_number_player_cells(int index)
{
    return arr_board[index].second;
}

void Board::set_adj_cells(int index1, int index2, int number_player)
{
    arr_board[index1].first = index2;
    arr_board[index1].second = number_player;
    arr_board[index2].first = index1;
    arr_board[index2].second = number_player;
}

bool Board::is_move(int number_player)
{
    bool is_move = false;
    if(number_player == 1)
    {
        for(int i = 0; i< size; i++)
        {
            if(arr_board[i].second == -1)
            {
                    // перевірка чи є верхня сусідня клітка
                if(i - amount_point_side >= 0)
                {
                    if(arr_board[i-amount_point_side].second == -1)
                    {
                        is_move = true;
                        break;
                    }
                }
                    // перевірка чи є нижня сусідня клітка
                if(i + amount_point_side < size)
                {
                    if(arr_board[i+amount_point_side].second == -1)
                    {
                        is_move = true;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        for(int i = 0; i< size; i++)
        {
            if(arr_board[i].second == -1)
            {
                    // перевірка чи є ліва сусідня клітка
                if( (i/ amount_point_side) == ((i - 1)/ amount_point_side) )
                {
                    if(arr_board[i-1].second == -1)
                    {
                        is_move = true;
                        break;
                    }
                }
                    // перевірка чи є права сусідня клітка
                if((i/ amount_point_side) == ((i + 1)/ amount_point_side))
                {
                    if(arr_board[i+1].second == -1)
                    {
                        is_move = true;
                        break;
                    }
                }
            }
        }
    }
    return is_move;
}

void Board::console_log()
{
    for(int i =0; i< size; i++)
    {
        cout << i << " " << arr_board[i].first << " " << arr_board[i].second << " " << endl;
    }
}

 bool Board::is_cell_empty(int index)
 {
     bool is_cell_empty = false;

     if(arr_board[index].second == -1)
         is_cell_empty = true;

     return is_cell_empty;
 }
