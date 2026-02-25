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
            std::cout << "Hy there, wanna play Tic-Tac-Toe with me?" << std::endl;
            std::cout << "If you want to play, write 'Y', if not 'N'" << std::endl;
            std::cin >> quest;
        
            if(quest == "N"){
                std::cout << "OK, Good bye!!! :D" << std::endl;
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
            std::cout << "To play with me you have to choose betwen 'X' or 'O' to play, so write here please." << std::endl;
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