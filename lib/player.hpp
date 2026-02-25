#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "types.hpp"
#include "board.hpp"

class Player {
public:
    virtual position MakeMove(const Board& board) = 0;
    virtual void DefineSide(side new_side) = 0;
    virtual ~Player() = default;
};

#endif