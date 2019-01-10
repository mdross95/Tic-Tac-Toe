#ifndef Board_hpp
#define Board_hpp

#include "InputOutput.hpp"
#include "Player.hpp"
#include "Spot.hpp"

#include <string>
#include <vector>

//represents a tic tac toe board
class Board
{
private:
    InputOutput io;
    static const int boardSize = 9;
    std::string moveErrorMessage;
    std::vector<Spot> boardVec;
    
public:
    //constructors/destructors
    Board();
    
    //initializers
    void initializeMessages();
    
    //getters/setters
    int getBoardSize() const;
    std::vector<Spot> getBoardVec() const;
    
    //misc functions
    bool checkTie();
    bool checkWin(Player* playerIn);
    std::vector<Spot> availableSpots();
    void sendBoard();
    void takeSpot(Player* playerIn, int spotIn);
};

#endif /* Board_hpp */
