#ifndef CreatePlayers_hpp
#define CreatePlayers_hpp

#include "Player.hpp"

class CreatePlayers
{
public:
    CreatePlayers();
    void createPlayers(int gameTypeIn, char playerOneSymbolIn, char playerTwoSymbolIn, int firstPlayerIn,
                                            Player*& playerOneIn, Player*& playerTwoIn, Player*& firstPlayer, Player*& secondPlayer);
};

#endif /* CreatePlayers_hpp */
