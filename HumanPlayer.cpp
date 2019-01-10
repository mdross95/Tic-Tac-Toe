#include "HumanPlayer.hpp"

//constructors/destructors
HumanPlayer::HumanPlayer()
{
}

HumanPlayer::HumanPlayer(char symbolIn, int idIn)
: Player (symbolIn, idIn)
{
    setShouldPickRandomly(false);
}

//initializers

//getters/setters

//misc functions
bool HumanPlayer::isHuman()
{
    return true;
}

void HumanPlayer::runTurn(Board& boardIn)
{
    boardIn.sendBoard();
    io.sendLine(this->promptMoveMessage());
    std::string move;
    int moveNum;
    io.read(move);
    
    while (vldt.validateMove(move, boardIn) == vldt.getMoveFailToken())
    {
        io.read(move);
    }
    
    moveNum = vldt.validateMove(move, boardIn);
    boardIn.takeSpot(this, moveNum);
    io.sendLine(this->takeSpotMessage(stoi(move)));
    
    if (boardIn.checkWin(this))
    {
        boardIn.sendBoard();
        io.sendLine(playerWinMessage());
        exit(0);
    }
    
    if (boardIn.checkTie())
    {
        boardIn.sendBoard();
        io.sendLine(playerTieMessage());
        exit(0);
    }
    
    if (getOtherPlayer()->getShouldPickRandomly())
    {
        getOtherPlayer()->setShouldPickRandomly(false);
    }
}
