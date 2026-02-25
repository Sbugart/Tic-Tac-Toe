#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "types.hpp"

/*
 * Class responsible to manage the grid by checking
 * if a Cell is empty, placing, printing and checking
 * if someone won the game.
 */
class Board {
public:
    Board();
    /*
    * Resets the board state for a new game.
    */
    void Reset();

    /*
    * Returns true if the given position is empty.
    */
    bool IsCellEmpty(position pos) const;

    /*
    * Places a piece at the given position.
    */
    MoveResult Place(position pos, side XO);

    /*
    * Prints the current board state.
    */
    void PrintGrid() const;

    MoveResult GetGameState();

    /*
    * Checks if the last move resulted in a win.
    */
    MoveResult CheckForWinner(position pos) const;

private:
    int number_of_pieces_placed;
    std::array<std::array<char, 3>, 3> grid;
    std::array<int, 3> row;
    std::array<int, 3> col;
    std::array<int, 2> diag;
    MoveResult game_state;

    /*
    * Returns true if the board is full.
    */
    bool IsFull() const;
};

#endif