#include "board.h"

#include <iostream>
Board::Board(int amount_p)
{
    amount_point_side = amount_p;
    size = amount_point_side*amount_point_side;
    arr_board.assign(size, pair<int,int>(-1,-1));
}

Board::Board(const Board& obj_board)
{
    amount_point_side = obj_board.amount_point_side;
    size = obj_board.size;
    arr_board = obj_board.arr_board;
}

int Board::get_size()
{
    return size;
}
int Board::get_amount_point_side()
{
    return amount_point_side;
}

int Board::get_index_edj_cells(int index)
{
    return arr_board[index].first;
}

int Board::get_number_player_cells(int index)
{
    return arr_board[index].second;
}

bool Board::set_adj_cells(int index1, int index2, int number_player)
{
    bool succes_adj = false;
    if (number_player == 1)
    {
        if(index2 < size && index1 < size && (index1 + amount_point_side == index2 || index2 + amount_point_side == index1))
        {
            if(arr_board[index1].second == -1 && arr_board[index2].second == -1)
            {
                arr_board[index1].first = index2;
                arr_board[index1].second = number_player;
                arr_board[index2].first = index1;
                arr_board[index2].second = number_player;

                succes_adj = true;
            }
        }
    }
    else
    {
        if(index1 >= 0 && index2 >=0 && index2 < size && index1 < size && (index1+1 == index2 || index2 + 1 == index1) &&(index1 / amount_point_side == index2 / amount_point_side ))
        {
            if(arr_board[index1].second == -1 && arr_board[index2].second == -1)
            {
                arr_board[index1].first = index2;
                arr_board[index1].second = number_player;
                arr_board[index2].first = index1;
                arr_board[index2].second = number_player;

                succes_adj = true;
            }
        }
    }
   return succes_adj;
}

void Board::set_amount_side(int amount_side)
{
    amount_point_side = amount_side;
}
void Board::set_size(int all_amount)
{
   size = all_amount;
}

void Board::set_board(vector<pair<int,int>> b)
{
    arr_board = b;
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
                    // ?????????????????? ???? ?? ???????????? ?????????????? ????????????
                if(i - amount_point_side >= 0)
                {
                    if(arr_board[i-amount_point_side].second == -1)
                    {
                        is_move = true;
                        break;
                    }
                }
                    // ?????????????????? ???? ?? ?????????? ?????????????? ????????????
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
                    // ?????????????????? ???? ?? ???????? ?????????????? ????????????
                if( (i/ amount_point_side) == ((i - 1)/ amount_point_side) )
                {
                    if(arr_board[i-1].second == -1)
                    {
                        is_move = true;
                        break;
                    }
                }
                    // ?????????????????? ???? ?? ?????????? ?????????????? ????????????
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


