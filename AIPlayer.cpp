#include "AIPlayer.hpp"

#include <climits>
#include <unordered_map>

//constructors/destructors
AIPlayer::AIPlayer()
{
}

AIPlayer::AIPlayer(char symbolIn, int idIn)
: Player (symbolIn, idIn)
{
    setShouldPickRandomly(true);
}

//initializers

//getters/setters

//misc functions
bool AIPlayer::isHuman()
{
    return false;
}

int AIPlayer::minimax(Player* playerIn, Board& boardIn, Player* tempPlayerIn, int& finalMoveIn)
{
    Board tempBoard = boardIn;
    int runningMove = 0;
    int runningScore = 0;
    int tempMove = 0;
    int tempMoveScore = 0;
    std::unordered_map<int, int> moves;
    std::vector<Spot> availableSpots = boardIn.availableSpots();
    
    if (boardIn.checkWin(playerIn->getOtherPlayer()))
    {
        return -1;
    }
    
    else if (boardIn.checkWin(playerIn))
    {
        return 1;
    }
    
    else if (availableSpots.size() == 0)
    {
        return 0;
    }
    
    //runs minimax algo
    for (int i = 0; i < availableSpots.size(); i++)
    {
        tempMove = availableSpots[i].getLocation();
        tempBoard = boardIn;
        boardIn.takeSpot(tempPlayerIn, tempMove);
        tempMoveScore = minimax(playerIn, boardIn, tempPlayerIn->getOtherPlayer(), finalMoveIn);
        boardIn = tempBoard;
        moves[tempMove] = tempMoveScore;
        
        if (playerIn == tempPlayerIn)
        {
            runningScore = INT_MIN;
            
            for (auto it = moves.begin(); it != moves.end(); it++)
            {
                if (it->second > runningScore)
                {
                    runningScore = it->second;
                    runningMove = it->first;
                }
            }
        }
        
        else
        {
            runningScore = INT_MAX;
            
            for (auto it = moves.begin(); it != moves.end(); it++)
            {
                if (it->second < runningScore)
                {
                    runningScore = it->second;
                    runningMove = it->first;
                }
            }
        }
    }
    
    finalMoveIn = runningMove;
    return runningScore;
}

void AIPlayer::runTurn(Board& boardIn)
{
    boardIn.sendBoard();
    
    io.proceed();
    io.sendLine(this->isMovingMessage());
    
    //minimax algo takes a while to run on 8 empty spaces,
    //so only do the think if there are less than 8 left
    if (boardIn.availableSpots().size() != boardIn.getBoardSize() - 1)
    {
        io.think(3000);
    }
    
    int move;
    
    if (getShouldPickRandomly())
    {
        move = rand() % boardIn.getBoardSize();
        setShouldPickRandomly(false);
        getOtherPlayer()->setShouldPickRandomly(false);
    }
    
    else
    {
        minimax(this, boardIn, this, move);
    }
    
    boardIn.takeSpot(this, move);
    io.sendLine(this->takeSpotMessage(move));
    
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
}
