#include "tank.h"

Tank::Tank() : Obstacle(-10)
{

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

int Tank::getNbObus2()
{
    return nbObus2;
}

int Tank::getNbObus3()
{
    return nbObus3;
}


