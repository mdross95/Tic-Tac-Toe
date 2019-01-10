#ifndef Game_hpp
#define Game_hpp

#include "Board.hpp"
#include "InputOutput.hpp"
#include "Player.hpp"

#include <string>

//represents a game of tic tac toe, with two players and a board
class Game
{
private:
    Board board;
    InputOutput io; 
    int gameType; //human v human, human v computer, computer v computer (1 2 or 3)
    Player* playerOne;
    Player* playerTwo;
    Player* firstPlayer;
    Player* secondPlayer;
    std::string gameStartMessageAIOnly;
    std::string gameStartMessageWithHuman;
    std::string moveErrorMessage;
    
public:
    //constructors/destructors
    Game();
    Game(int gameTypeIn, char playerOneSymbolIn, char playerTwoSymbolIn, int firstPlayerIn);
    
    //initializers
    void initializeMessages();
    void initializePlayers(int gameType, char playerOneSymbol, char playerTwoSymbol, int firstPlayerIn);
    
    //getters/setters
    
    //misc functions
    void performStart();
    void runGame();
};

#endif /* Game_hpp */
