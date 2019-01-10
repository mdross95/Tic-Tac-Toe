#ifndef SetupGame_hpp
#define SetupGame_hpp

#include "InputOutput.hpp"
#include "Validate.hpp"

/*gathers parameters for game (player symbols, game type, etc.)
and creates Game object with those parameters*/
class SetupGame
{
private:
    char playerOneSymbol;
    char playerTwoSymbol;
    InputOutput io;
    int firstPlayer;
    int gameType; //human v human, human v computer, computer v computer (1 2 or 3)
    std::string requestFirstPlayerMessage;
    std::string requestGameTypeMessage;
    std::string requestPlayerSymbolsMessage;
    std::string welcomeMessage;
    std::vector<std::string> gameTypeOptionsMessages;
    Validate vldt;
    
public:
    //constructors/destructors
    SetupGame();
    
    //initializers
    void initializeMessages();
    
    //getters/setters
    
    //misc functions
    void chooseFirstPlayer();
    void chooseGameParams();
    void chooseGameType();
    void choosePlayerSymbols();
    void performWelcome();
};

#endif /* SetupGame_hpp */
