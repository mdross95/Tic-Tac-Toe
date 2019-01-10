#include "Game.hpp"
#include "SetupGame.hpp"

//constructors/destructors
SetupGame::SetupGame()
{
    initializeMessages();
    performWelcome();
    chooseGameParams();
    Game game(gameType, playerOneSymbol, playerTwoSymbol, firstPlayer);
}

//initializers
void SetupGame::initializeMessages()
{
    gameTypeOptionsMessages = {"Human vs. Human", "Human vs. Computer", "Computer vs. Computer"};
    requestFirstPlayerMessage = "Cool! Finally, please choose a player to move first (1 or 2).";
    requestGameTypeMessage = "What type of game would you like to play? Choices are as follows (will be designated Player 1 and Player 2, respectively):";
    requestPlayerSymbolsMessage = "Great! Please choose board symbols for Player 1 and Player 2 respectively (enter both symbols separated by a space)."
        " Valid symbols include any two distinct, single-digit/-character alphanumerics (0-9, a-z, A-Z).";
    welcomeMessage = "Welcome to Tic Tac Toe! You may quit at any time by typing \"" + io.getQuitString() + "\".";
}

//getters/setters

//misc functions
void SetupGame::chooseFirstPlayer()
{
    io.sendLine(requestFirstPlayerMessage);
    std::string firstPlayerInput;
    io.read(firstPlayerInput);
    
    while (vldt.validateFirstPlayer(firstPlayerInput) == vldt.getFirstPlayerFailToken())
    {
        io.read(firstPlayerInput);
    }
    
    firstPlayer = vldt.validateFirstPlayer(firstPlayerInput);
}

void SetupGame::chooseGameParams()
{
    chooseGameType();
    choosePlayerSymbols();
    chooseFirstPlayer();
}

void SetupGame::chooseGameType()
{
    io.sendLine(requestGameTypeMessage);
    int choiceNumber = 0;
    
    for (auto it = gameTypeOptionsMessages.begin(); it != gameTypeOptionsMessages.end(); it++)
    {
        choiceNumber = int(it - gameTypeOptionsMessages.begin() + 1);
        io.sendLine(std::to_string(choiceNumber) + ") " + it->data());
    }
    
    std::string type;
    io.read(type);
    
    while(vldt.validateGameType(type) == vldt.getGameTypeFailToken())
    {
        io.read(type);
    }
    
    gameType = vldt.validateGameType(type);
}

void SetupGame::choosePlayerSymbols()
{
    io.sendLine(requestPlayerSymbolsMessage);
    std::string symbolsIn;
    io.read(symbolsIn);

    while (vldt.validateSymbols(symbolsIn) == vldt.getSymbolFailToken())
    {
        io.read(symbolsIn);
    }
    
    playerOneSymbol = vldt.validateSymbols(symbolsIn).first;
    playerTwoSymbol = vldt.validateSymbols(symbolsIn).second;
}

void SetupGame::performWelcome()
{
    io.sendLine(welcomeMessage);
}


