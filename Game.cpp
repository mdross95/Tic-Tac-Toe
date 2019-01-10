#include "Board.hpp"
#include "CreatePlayers.hpp" 
#include "Game.hpp"
#include "InputOutput.hpp"
#include "Player.hpp"
#include "SetupGame.hpp"

#include <ctime>
#include <unordered_map>
#include <vector>

//constructors/destructors
Game::Game()
{
}

Game::Game(int gameTypeIn, char playerOneSymbolIn, char playerTwoSymbolIn, int firstPlayerIn)
{
    srand(int(time(NULL))); //randomizes seed for rand() in runTurn()
    gameType = gameTypeIn;
    initializePlayers(gameTypeIn, playerOneSymbolIn, playerTwoSymbolIn, firstPlayerIn);
    initializeMessages();
    runGame();
}

//initializers
void Game::initializeMessages()
{
    gameStartMessageWithHuman = "Perfect, let's play! " + firstPlayer->playerString() + " goes first."
        " The board to the left is the game board. Asterisks signify untaken spots. The board to the right"
        " is simply a visual reference.";
    gameStartMessageAIOnly = gameStartMessageWithHuman + " Proceed when ready, then sit back and enjoy!";
    moveErrorMessage = "Please enter a choice 0-8 that has not been taken yet.";
}

void Game::initializePlayers(int gameTypeIn, char playerOneSymbolIn, char playerTwoSymbolIn, int firstPlayerIn)
{
    CreatePlayers cp;
    cp.createPlayers(gameTypeIn, playerOneSymbolIn, playerTwoSymbolIn, firstPlayerIn,
                      playerOne, playerTwo, firstPlayer, secondPlayer);
    
}

//getters/setters

//misc functions
void Game::performStart()
{
    if (gameType != 3)
    {
        io.sendLine(gameStartMessageWithHuman);
    }
    
    else
    {
        io.sendLine(gameStartMessageAIOnly);
    }
}
void Game::runGame()
{
    performStart();
    
    while(1)
    {
        firstPlayer->runTurn(board);
        secondPlayer->runTurn(board);
    }
}

