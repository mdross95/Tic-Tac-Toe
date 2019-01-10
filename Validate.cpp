#include "Validate.hpp"

//constructors/destructors
Validate::Validate()
{
    initializeMessages();
}

//initializers
void Validate::initializeMessages()
{
    firstPlayerErrorMessage = "Please enter 1 or 2.";
    gameTypeOptionsMessages = {"Human vs. Human", "Human vs. Computer", "Computer vs. Computer"};
    moveErrorMessage = "Please enter a choice 0-8 that has not been taken yet.";
    symbolsAlnumErrorMessage = "Symbols must be alphanumeric, i.e. 0-9, a-z, A-Z. Please try again.";
    symbolsEqualErrorMessage = "Symbols must be distinct. Please try again.";
    symbolsStructureErrorMessage = "Please enter two single-digit/-character symbols separated by a space.";
    typeErrorMessage = "Valid values for game type are: 1, 2, 3. Please try again.";
}

//getters/setters
int Validate::getFirstPlayerFailToken()
{
    return firstPlayerFailToken;
}

int Validate::getGameTypeFailToken()
{
    return gameTypeFailToken;
}

int Validate::getMoveFailToken()
{
    return moveFailToken;
}

std::pair<char,char> Validate::getSymbolFailToken()
{
    return symbolFailToken;
}

//misc functions
int Validate::validateFirstPlayer(std::string firstPlayerInputIn)
{
    if (firstPlayerInputIn.length() != 1 || (firstPlayerInputIn[0] != '1' && firstPlayerInputIn[0] != '2'))
    {
        io.sendLine(firstPlayerErrorMessage);
        return firstPlayerFailToken;
    }
    
    return stoi(firstPlayerInputIn);
}

int Validate::validateGameType(std::string typeIn)
{
    try
    {
        if (typeIn.length() != 1 || 0 >= stoi(typeIn) || stoi(typeIn) > gameTypeOptionsMessages.size())
        {
            io.sendLine(typeErrorMessage);
            return gameTypeFailToken;
        }
    }
    
    catch (const std::invalid_argument& ia)
    {
        io.sendLine(typeErrorMessage);
        return gameTypeFailToken;
    }
    
    return stoi(typeIn);
}

int Validate::validateMove(std::string& moveIn, Board& boardIn)
{
    
    try
    {
        if (moveIn.length() != 1 || 0 > stoi(moveIn) || 8 < stoi(moveIn))
        {
            boardIn.sendBoard();
            io.sendLine(moveErrorMessage);
            return getMoveFailToken();
        }
        
        else if (boardIn.getBoardVec()[stoi(moveIn)].getIsTaken())
        {
            boardIn.sendBoard();
            io.sendLine(moveErrorMessage);
            return getMoveFailToken();
        }
        
    }
    
    catch (const std::invalid_argument& ia)
    {
        boardIn.sendBoard();
        io.sendLine(moveErrorMessage);
        return getMoveFailToken();
    }
    
    return stoi(moveIn);
}

std::pair<char,char> Validate::validateSymbols(std::string symbolsIn)
{
    if (symbolsIn.length() != 3 ||
        (symbolsIn.length() ==  3 &&
         (symbolsIn[1] != ' ' || symbolsIn[0] == ' ' || symbolsIn[2] == ' ')))
    {
        io.sendLine(symbolsStructureErrorMessage);
        return symbolFailToken;
    }
    
    else if (!isalnum(symbolsIn[0]) || !isalnum(symbolsIn[2]))
    {
        io.sendLine(symbolsAlnumErrorMessage);
        return symbolFailToken;
    }
    
    else if (symbolsIn[0] == symbolsIn[2])
    {
        io.sendLine(symbolsEqualErrorMessage);
        return symbolFailToken;
    }

    return std::make_pair(symbolsIn[0], symbolsIn[2]);
}
