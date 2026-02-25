#include "../lib/minimax.hpp"

Minimax::Minimax(side my_side)
    : my_side(my_side)
    {};

void Minimax::DefineSide(side new_side){
    my_side = new_side;
}

int Minimax::BuildTree(Board board, bool isMax)
{
    MoveResult state = board.GetGameState(); 
    if (state == MoveResult::WinX || state == MoveResult::WinO) {
        side winner = (state == MoveResult::WinX ? side::X : side::O);
        return (winner == my_side) ? 1 : -1;
    }
    if (state == MoveResult::Draw)
        return 0;

    int best = isMax ? -2 : 2;

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(board.IsCellEmpty({i,j})){

                Board next = board;
                side current = isMax ? my_side : Opponent(my_side);
                next.Place({i,j}, current);

                int score = BuildTree(next, !isMax);

                if(isMax)
                    best = std::max(best, score);
                else
                    best = std::min(best, score);
            }
        }
    }

    return best;
}

side Minimax::Opponent(side s){
    return (s == side::X ? side::O : side::X);
}

position Minimax::MakeMove(const Board& board)
{
    int best = -2;
    position bestPos{0,0};

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(board.IsCellEmpty({i,j})){

                Board next = board;
                next.Place({i,j}, my_side);

                int score = BuildTree(next, false);

                if(score > best){
                    best = score;
                    bestPos = {i,j};
                }
            }
        }
    }

    return bestPos;
}