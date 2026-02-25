#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "player.hpp"

class Human : public Player {
public:
    Human();
    position MakeMove(const Board& board) override;
    void DefineSide(side new_side) override;
private:
    int move;
    position pos;

    void getHumanMove();
};

#endif