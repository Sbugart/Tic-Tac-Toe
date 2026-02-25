#ifndef MINIMAX_HPP
#define MINIMAX_HPP

#include "player.hpp"


class Minimax : public Player {
public:
    Minimax(side my_side);
    position MakeMove(const Board& board) override;
    void DefineSide(side new_side) override;
private:
    side my_side;
    int BuildTree(Board board, bool isMax);
    side Opponent(side s);
};

#endif