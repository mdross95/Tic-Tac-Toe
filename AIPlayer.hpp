#ifndef AIPlayer_hpp
#define AIPlayer_hpp

#include "Player.hpp"
#include "Board.hpp"
#include "InputOutput.hpp"
#include "Validate.hpp"

class AIPlayer : public Player
{
private:
    InputOutput io;
    Validate vldt;
public:
    //constructors/destructors
    AIPlayer();
    AIPlayer(char symbolIn, int idIn);
    
    //initializers
    
    //getters/setters
    
    //misc functions
    bool isHuman();
    int minimax(Player* playerIn, Board& boardIn, Player* tempPlayerIn, int& finalMoveIn);
    void runTurn(Board& boardIn);
};

#endif /* AIPlayer_hpp */
