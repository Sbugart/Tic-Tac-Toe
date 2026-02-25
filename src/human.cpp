#include "../lib/human.hpp"
#include <iostream>

Human::Human()
    :move(-1),
    pos({0,0})
    {};

void Human::DefineSide(side new_side) {
    // pode armazenar se quiser
}

void Human::getHumanMove(){
    int mov = 0;
    while(mov < 1 || mov > 9){
        std::cout << "Please enter a number (1-9) to choose where you want to place your piece:\n";

        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                std::cout << " " << (i * 3 + (j + 1)) << (j < 2 ? " |" : "\n");
            }
            std::cout << (i < 2 ? "---|---|---\n" : "\n");
        }

        std::cin >> mov;
    }
 
    move = mov;
}

position Human::MakeMove(const Board& board){
    std::cout << "Your turn!!!" << std::endl;
    getHumanMove();

    pos[0] = (move - 1) / 3;
    pos[1] = (move - 1) % 3;
    return pos;
}