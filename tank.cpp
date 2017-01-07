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

bool Tank::enleverCapacite()
{
    return enleverCapacite(1);
}

bool Tank::enleverCapacite(int cx)
{
    if(capacite > 0){
        capacite -= cx;
        return true;
    }
    else{
        return false;
    }
}

void Tank::makeZeroCapacite()
{
    capacite = 0;
}

bool Tank::capaciteRestante()
{
    if(capacite>0){
        return true;
    }
    else{
        return false;
    }
}

void Tank::setCapacite(int newCap)
{
    this->capacite = newCap;
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

void Tank::moveBy(int dx, int dy)
{
    add += QPoint(dx, dy);
}

int Tank::getHorizon() const
{
    return horizon;
}

void Tank::setHorizon(int value)
{
    horizon = value;
}

Tank::Tank()
{
    capacite = 100;
    setOrientation(rand()%4);
    setHorizon(0);
}

bool Tank::isAlive()
{
    return alive;
}

Projectile* Tank::useObus1(QPointF posTank, QPoint dir, int puis)
{
    return new Obus(posTank, dir, puis);
}

Projectile* Tank::useObus2(QPointF posTank, QPoint dir, int puis)
{
    if(nbObus2 > 0){
        nbObus2--;
    }
    else{
        return NULL;
    }
    return NULL;
}

Projectile* Tank::useObus3(QPointF posTank, QPoint dir, int puis)
{
    if(nbObus3 > 0){
        nbObus3--;

    }
    else{
        return NULL;
    }
    return NULL;
}
