#include "tank.h"

int Tank::getNbObus2() const
{
    return nbObus2;
}

int Tank::getNbObus3() const
{
    return nbObus3;
}

int Tank::getAddL() const
{
    return addL;
}

void Tank::setAddL(int value)
{
    addL = value;
}

int Tank::getAddC() const
{
    return addC;
}

void Tank::setAddC(int value)
{
    addC = value;
}

int Tank::getOrientation() const
{
    return orientation;
}

void Tank::setOrientation(int value)
{
    orientation = value;
}

Tank::Tank()
{
    capacite = 100;
}

bool Tank::isAlive()
{
    return alive;
}

bool Tank::useObus1()
{
    return true;
}

bool Tank::useObus2()
{
    if(nbObus2 > 0){
        nbObus2--;
        return true;
    }
    else{
        return false;
    }
}

bool Tank::useObus3()
{
    if(nbObus3 > 0){
        nbObus3--;
        return true;
    }
    else{
        return false;
    }
}
