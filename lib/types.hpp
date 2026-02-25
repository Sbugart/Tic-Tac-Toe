#ifndef TYPES_HPP
#define TYPES_HPP

#include <array>

using position = std::array<int, 2>;

enum class side {
    X, O, none
};

enum class MoveResult {
    Invalid,
    Valid,
    WinX,
    WinO,
    Draw
};

#endif