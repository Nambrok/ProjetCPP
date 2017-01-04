#include "tank.h"

int Tank::getNbObus2() const
{
    return nbObus2;
}

int Tank::getNbObus3() const
{
    return nbObus3;
}

Tank::Tank() : Obstacle(-10)
{
    capacite = 100;
    setCouleur(Qt::red);

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
