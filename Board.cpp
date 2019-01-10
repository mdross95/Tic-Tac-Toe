#include "Board.hpp"

#include <cmath>

//constructors/destructors
Board::Board()
{
    for (int i = 0; i < getBoardSize(); i++)
    {
        boardVec.push_back(Spot(i, false, nullptr));
    }
    
    initializeMessages();
}

//initializers
void Board::initializeMessages()
{
    moveErrorMessage = "Please enter a choice 0-8 that has not been taken yet.";
}

//getters/setters
int Board::getBoardSize() const
{
    return boardSize;
}

std::vector<Spot> Board::getBoardVec() const
{
    return boardVec;
}

//misc functions
bool Board::checkTie()
{
    return availableSpots().size() == 0;
}

bool Board::checkWin(Player *playerIn)
{
    //left column
    if (getBoardVec()[0] == getBoardVec()[3] &&
        getBoardVec()[3] == getBoardVec()[6] &&
        getBoardVec()[0].getTakenBy() == playerIn)
    {
        return true;
    }
    
    //middle column
    if (getBoardVec()[1] == getBoardVec()[4] &&
        getBoardVec()[4] == getBoardVec()[7] &&
        getBoardVec()[1].getTakenBy() == playerIn)
    {
        return true;
    }
    
    //right column
    if (getBoardVec()[2] == getBoardVec()[5] &&
        getBoardVec()[5] == getBoardVec()[8] &&
        getBoardVec()[2].getTakenBy() == playerIn)
    {
        return true;
    }
    
    //top row
    if (getBoardVec()[0] == getBoardVec()[1] &&
        getBoardVec()[1] == getBoardVec()[2] &&
        getBoardVec()[0].getTakenBy() == playerIn)
    {
        return true;
    }
    
    //middle row
    if (getBoardVec()[3] == getBoardVec()[4] &&
        getBoardVec()[4] == getBoardVec()[5] &&
        getBoardVec()[3].getTakenBy() == playerIn)
    {
        return true;
    }
    
    //bottom row
    if (getBoardVec()[6] == getBoardVec()[7] &&
        getBoardVec()[7] == getBoardVec()[8] &&
        getBoardVec()[6].getTakenBy() == playerIn)
    {
        return true;
    }
    
    //top left to bottom right
    if (getBoardVec()[0] == getBoardVec()[4] &&
        getBoardVec()[4] == getBoardVec()[8] &&
        getBoardVec()[0].getTakenBy() == playerIn)
    {
        return true;
    }
    
    //top right to bottom left
    if (getBoardVec()[2] == getBoardVec()[4] &&
        getBoardVec()[4] == getBoardVec()[6] &&
        getBoardVec()[2].getTakenBy() == playerIn)
    {
        return true;
    }
    
    return false;
}


std::vector<Spot> Board::availableSpots()
{
    std::vector<Spot> result;
    
    for (int i = 0; i < boardSize; i++)
    {
        if (!boardVec[i].getIsTaken())
        {
            result.push_back(boardVec[i]);
        }
    }
    
    return result;
}

void Board::sendBoard()
{
    int repeat = int(sqrt(getBoardSize()));
    
    for (int i = 0; i < repeat; i++)
    {
        io.send("| ");
        
        for (int j = 0; j < repeat; j++)
        {
            boardVec[(i*repeat)+j].sendSpot();
            io.send(" | ");
        }
        
        io.send("  ");
        
        for (int j = 0; j < repeat; j++)
        {
            io.send(" | " + std::to_string((i*repeat)+j));
        }
    
        io.send(" |\n");
    }
    
    io.send("\n");
}

void Board::takeSpot (Player* playerIn, int spotIn)
{
    boardVec[spotIn].setIsTaken();
    boardVec[spotIn].setTakenBy(playerIn);
}
