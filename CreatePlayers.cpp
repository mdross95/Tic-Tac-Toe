#include "AIPlayer.hpp"
#include "CreatePlayers.hpp"
#include "HumanPlayer.hpp"

CreatePlayers::CreatePlayers()
{
}

void CreatePlayers::createPlayers(int gameTypeIn, char playerOneSymbolIn, char playerTwoSymbolIn, int firstPlayerIn,
                                                       Player*& playerOneIn, Player*& playerTwoIn, Player*& firstPlayer, Player*& secondPlayer)
{
        switch(gameTypeIn)
        {
            case(1):
            {
                playerOneIn = new HumanPlayer(playerOneSymbolIn, 1);
                playerTwoIn = new HumanPlayer(playerTwoSymbolIn, 2);
                break;
            }
            case(2):
            {
                playerOneIn = new HumanPlayer(playerOneSymbolIn, 1);
                playerTwoIn = new AIPlayer(playerTwoSymbolIn, 2);
                break;
            }
            case(3):
            {
                playerOneIn = new AIPlayer(playerOneSymbolIn, 1);
                playerTwoIn = new AIPlayer(playerTwoSymbolIn, 2);
                break;
            }
        }
    
        playerOneIn->setOtherPlayer(playerTwoIn);
        playerTwoIn->setOtherPlayer(playerOneIn);
    
        if (firstPlayerIn == 1)
        {
            firstPlayer = playerOneIn;
            secondPlayer = playerTwoIn;
        }
    
        else
        {
            firstPlayer = playerTwoIn;
            secondPlayer = playerOneIn;
        }
}
