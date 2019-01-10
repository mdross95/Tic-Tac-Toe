#ifndef Spot_hpp
#define Spot_hpp

class Player;

#include "Player.hpp"
#include "InputOutput.hpp"

//represents a spot on the tic tac toe board
class Spot
{
private:
    bool isTaken;
    InputOutput io; 
    int location;
    Player* takenBy;
    static const char untakenPlaceholder = '*';
    
public:
    //constructors/destructors
    Spot();
    Spot(int locationIn, bool isTakenIn, Player* takenByIn);
    
    //initializers
    
    //getters/setters
    bool getIsTaken() const;
    int getLocation() const;
    Player* getTakenBy() const;
    void setIsTaken();
    void setTakenBy(Player* playerIn);
    
    //misc functions
    bool operator==(const Spot& spotB) const;
    void sendSpot();
    
    
    
};

#endif /* Spot_hpp */
