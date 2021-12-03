#include "board.h"

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
