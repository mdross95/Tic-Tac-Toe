#ifndef Player_hpp
#define Player_hpp

class Board;

#include "Board.hpp"
#include "InputOutput.hpp"
#include "Validate.hpp"

#include <string>

//represents a player
class Player
{
protected:
    bool shouldPickRandomly;
    char symbol;
    int id;
    Player* otherPlayer;
    
public:
    //constructors/destructors
    Player();
    Player(char symbolIn, int idIn);
    virtual ~Player();
    
    //initializers
    
    //getters/setters
    bool getShouldPickRandomly();
    char getSymbol() const;
    Player* getOtherPlayer() const;
    void setOtherPlayer(Player* playerIn);
    void setShouldPickRandomly(bool in);
    
    //misc functions
    std::string isMovingMessage() const;
    std::string playerWinMessage() const;
    std::string playerTieMessage() const;
    std::string playerString() const;
    std::string promptMoveMessage() const;
    std::string takeSpotMessage(int moveIn) const;
    virtual bool isHuman() = 0;
    virtual void runTurn(Board& boardIn) = 0;

};

#endif /* Player_hpp */
