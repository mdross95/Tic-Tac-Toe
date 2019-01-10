#ifndef Validate_hpp
#define Validate_hpp

#include "Board.hpp"

#include <string>
#include <vector>

class Validate
{
private:
    const int firstPlayerFailToken = -1;
    const int moveFailToken = -1;
    const int gameTypeFailToken = -1;
    const std::pair<char,char> symbolFailToken = std::make_pair('*', '*');
    InputOutput io;
    std::string firstPlayerErrorMessage;
    std::string moveErrorMessage;
    std::string symbolsAlnumErrorMessage;
    std::string symbolsEqualErrorMessage;
    std::string symbolsStructureErrorMessage;
    std::string typeErrorMessage;
    std::vector<std::string> gameTypeOptionsMessages;
public:
    //constructors/destructors
    Validate();
    
    //initializers
    void initializeMessages();
    
    //getters/setters
    int getFirstPlayerFailToken();
    int getGameTypeFailToken();
    int getMoveFailToken();
    std::pair<char,char> getSymbolFailToken();
    
    //misc functions
    int validateFirstPlayer(std::string firstPlayerInputIn);
    int validateGameType(std::string typeIn);
    int validateMove(std::string& moveIn, Board& boardIn);
    std::pair<char, char> validateSymbols(std::string symbolsIn);

};

#endif /* Validate_hpp */
