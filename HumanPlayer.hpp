#ifndef HumanPlayer_hpp
#define HumanPlayer_hpp

#include "Player.hpp"
#include "Board.hpp"
#include "InputOutput.hpp"
#include "Validate.hpp"

class HumanPlayer : public Player
{
private:
    InputOutput io;
    Validate vldt;
public:
    //constructors/destructors
    HumanPlayer();
    HumanPlayer(char symbolIn, int idIn);
    
    //initializers
    
    //getters/setters
    
    //misc functions
    bool isHuman();
    void runTurn(Board& boardIn);
};

#endif /* HumanPlayer_hpp */
