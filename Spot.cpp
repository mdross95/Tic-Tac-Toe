#include "Player.hpp"
#include "Spot.hpp"

//constructors/destructors
Spot::Spot()
{
}

Spot::Spot(int locationIn, bool isTakenIn, Player* takenByIn)
{
    location = locationIn;
    isTaken = isTakenIn;
    takenBy = takenByIn;
}

//initializers

//getters/setters
bool Spot::getIsTaken() const
{
    return isTaken;
}

int Spot::getLocation() const
{
    return location;
}

Player* Spot::getTakenBy() const
{
    return takenBy;
}

void Spot::setIsTaken()
{
    isTaken = true;
}

void Spot::setTakenBy(Player* playerIn)
{
    takenBy = playerIn;
}

//misc functions
bool Spot::operator== (const Spot& spotB) const
{
    return (this->getIsTaken() && spotB.getIsTaken() &&
            this->getTakenBy() == spotB.getTakenBy());
}

void Spot::sendSpot()
{
    if (isTaken)
    {
        io.send(takenBy->getSymbol());
    }
    
    else
    {
        io.send(untakenPlaceholder);
    }
}


