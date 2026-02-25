#include "../lib/board.hpp"
#include <iostream>
#include <cstdlib>

Board::Board()
    : number_of_pieces_placed(0),
    diag{0,0},
    row{0,0,0},
    col{0,0,0},
    game_state(MoveResult::Valid)
{
    for(auto& r : grid) r.fill('-');
}

void Board::Reset(){
    number_of_pieces_placed = 0;
    diag = {0,0};
    row = {0,0,0};
    col = {0,0,0};
    game_state = MoveResult::Valid;
    for(auto& r : grid) r.fill('-');
}

bool Board::IsCellEmpty(position pos) const{
    return grid[pos[0]][pos[1]] == '-';
}

MoveResult Board::Place(position pos, side XO){
    if(!IsCellEmpty(pos)){
        return game_state = MoveResult::Invalid;
    }
    grid[pos[0]][pos[1]] = (XO == side::X ? 'X' : 'O');
    row[pos[0]] += (XO == side::X ?  1 : - 1);
    col[pos[1]] += (XO == side::X ?  1 : - 1);
    if(pos[0] == pos[1]) diag[0] += (XO == side::X ? 1 : -1);
    if(pos[0] + pos[1] == 2) diag[1] += (XO == side::X ? 1 : -1);
    number_of_pieces_placed++;
    return game_state = CheckForWinner(pos);
}

bool Board::IsFull() const{
    return number_of_pieces_placed == 9;
}

void Board::PrintGrid() const{
    std::cout << "Current Board:" << std::endl;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            std::cout << " " << (grid[i][j] == '-' ? ' ' : grid[i][j]) << (j < 2 ? " |" : "\n");
        }
        std::cout << (i < 2 ? "---|---|---\n" : "\n");
    }
}   

MoveResult Board::CheckForWinner(position pos) const{
    if(abs(row[pos[0]]) == 3){
        if(row[pos[0]] == 3) return MoveResult::WinX;
        else return MoveResult::WinO;
    }
    else if(abs(col[pos[1]]) == 3){
        if(col[pos[1]] == 3) return MoveResult::WinX;
        else return MoveResult::WinO;
    }
    else{
        if(abs(diag[0]) == 3){
            if(diag[0] == 3) return MoveResult::WinX;
            else return MoveResult::WinO;
        }
        if(abs(diag[1]) == 3){
            if(diag[1] == 3) return MoveResult::WinX;
            else return MoveResult::WinO; 
        }
    }
    if(IsFull())
        return MoveResult::Draw;
    else return  MoveResult::Valid;
}

MoveResult Board::GetGameState(){
    return game_state;
}