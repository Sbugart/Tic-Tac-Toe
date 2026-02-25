#include "../lib/game.hpp"


Game::Game()
    :   board(),
    current(0),
    turn(side::X),
    players{
        std::make_unique<Human>(),
        std::make_unique<Minimax>(side::X)
    }
    {};

void Game::Reset(){
    current = 0;
    turn = side::X;
    board.Reset();
}

void Game::Play(side human_side){
    human = human_side;
    side bot_side;
    if(human == side::O){
        current = 1;
        bot_side = side::X;
    }
    else bot_side = side::O;
    
    players[1]->DefineSide(bot_side);
    MoveResult gaming = MoveResult::Valid;
    while(gaming == MoveResult::Valid){
        do{
        gaming = PlayTurn(*players[current]);
        }while(gaming == MoveResult::Invalid);
        board.PrintGrid();
        current = ((current + 1) % 2);
        turn = (turn == side::X ? side::O : side::X);
    }
    EndGame(gaming);
}

MoveResult Game::PlayTurn(Player& player){
    position pos = player.MakeMove(board);
    return board.Place(pos, turn);
}

void Game::EndGame(MoveResult gaming){
    side winner = (gaming == MoveResult::WinX ? side::X : side::O);
    if(gaming == MoveResult::Draw){
        std::cout << "Game ended in a Draw!" << std::endl;
    }
    else if(human == winner){
        std::cout << "Congratulations, you won the game!" << std::endl;
    }
    else{
        std::cout << "You lost the game, maybe in another time?" << std::endl;
    }
    Reset();
}