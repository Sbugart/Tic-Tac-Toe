#include "lib/game.hpp"
#include <string>

class GameController{
public:
    GameController() : 
        game()
        {};

    void AskForNewGame(){
        std::string quest; quest = "-1";
        while(true){
            std::cout << "Hi there! Do you want to play Tic-Tac-Toe with me?" << std::endl;
            std::cout << "Enter 'Y' to play or 'N' to exit:" << std::endl;
            std::cin >> quest;
        
            if(quest == "N"){
                std::cout << "OK, goodbye!" << std::endl;
                break;
            }
            else if(quest == "Y"){
                StartGame();
            }
        } 
    };

private:
    Game game;

    void StartGame(){
        std::string piece; piece = "-1";
        while(piece != "X" && piece != "O"){
            std::cout << "Choose your side ('X' or 'O'): ";
            std::cin >> piece;
        }

        if(piece == "X") game.Play(side::X);
        else game.Play(side::O);
    }
};

int main(){
    GameController game;
    game.AskForNewGame();
    
    return 0;
}