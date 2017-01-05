#include "tank.h"

int Tank::getNbObus2() const
{
    return nbObus2;
}

int Tank::getNbObus3() const
{
    return nbObus3;
}

int Tank::getOrientation() const
{
    return orientation;
}

void Tank::setOrientation(int value)
{
    orientation = value;
}

QPixmap Tank::getTexture()
{
    switch (getOrientation()) {
    case 0:
        return *textureHaut;
        break;
    case 1:
        return *textureGauche;
        break;
    case 2:
        return *textureBas;
        break;
    case 3:
        return *textureDroite;
        break;
    default:
        return *textureHaut;
        break;
    }
}

void Tank::setTextureGauche(QPixmap *newTexture)
{
    this->textureGauche = newTexture;
}

void Tank::setTextureDroite(QPixmap *newTexture)
{
    this->textureDroite = newTexture;
}

void Tank::setTextureHaut(QPixmap *newTexture)
{
    this->textureHaut = newTexture;
}

void Tank::setTextureBas(QPixmap *newTexture)
{
    this->textureBas = newTexture;
}

QPoint Tank::getAdd() const
{
    return add;
}

void Tank::setAdd(const QPoint &value)
{
    add = value;
}

Tank::Tank()
{
    capacite = 100;
    setOrientation(rand()%4);
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
