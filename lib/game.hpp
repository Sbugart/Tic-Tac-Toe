#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"
#include "player.hpp"
#include "human.hpp"
#include "minimax.hpp"

#include <iostream>
#include <memory>


/*
 * Class responsible to 
 */
class Game {
public:
    Game();
    void Reset();
    void Play(side human_side);

private:
    Board board;
    std::array<std::unique_ptr<Player>, 2> players;
    side human;
    side turn;
    int current;

    MoveResult PlayTurn(Player& player);
    void EndGame(MoveResult gaming);
};

#endif