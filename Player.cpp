#include "Player.hpp"

//constructors/destructors
Player::Player()
{
}

Player::~Player()
{
}

Player::Player(char symbolIn, int idIn)
{
    id = idIn;
    symbol = symbolIn;
}

//initializers

//getters/setters
bool Player::getShouldPickRandomly()
{
    return shouldPickRandomly;
}

char Player::getSymbol() const
{
    return symbol;
}

Player* Player::getOtherPlayer() const
{
    return otherPlayer;
}

void Player::setOtherPlayer(Player* playerIn)
{
    otherPlayer = playerIn;
}

void Player::setShouldPickRandomly(bool in)
{
    shouldPickRandomly = in;
}

//misc functions
std::string Player::isMovingMessage() const
{
    return playerString() + " is moving...";
}

std::string Player::playerString() const
{
    return "Player " + std::to_string(id);
}

std::string Player::playerTieMessage() const
{
    return playerString() + " ties the game with " + getOtherPlayer()->playerString() + "! Thank you for playing.";
}

std::string Player::playerWinMessage() const
{
    return playerString() + " wins! Thank you for playing.";
}

std::string Player::promptMoveMessage() const
{
    return playerString() + ", please pick a spot 0-8 that has not been taken yet"
        " to make your move.";
}

std::string Player::takeSpotMessage(int moveIn) const
{
    return playerString() + " takes spot " + std::to_string(moveIn) + ":";
}
