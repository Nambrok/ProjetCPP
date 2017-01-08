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

int Tank::getAngleDeTir() const
{
    return angleDeTir;
}

void Tank::setAngleDeTir(int value)
{
    angleDeTir = value;
}

Tank::~Tank()
{
    delete textureBas;
    delete textureDroite;
    delete textureGauche;
    delete textureHaut;
}

Tank::Tank()
{
    capacite = 100;
    setOrientation(rand()%4);
    setHorizon(0);
    setAngleDeTir(1);
    alive = true;
}

bool Tank::isAlive()
{
    return alive;
}

void Tank::setDead()
{
    alive = false;
}

Projectile* Tank::useProjectile(QPoint posTank, int dir, int puis, int type){
    if(type == T_OBUS){
        return useObus(posTank, dir, puis);
    }
    else if(type == T_MISSILE){
        return useMissile(posTank, dir, puis);
    }
    else if(type == T_NUKE){
        return useNuke(posTank, dir, puis);
    }
    else{
        qDebug()<<"Tank::useObus(QPoint, int dir, int puis, int type) : Type donner inconnu "<<type;
        return NULL;
    }
}

Projectile* Tank::useObus(QPoint posTank, int dir, int puis)
{
    return new Obus(posTank, dir, puis);
}

Projectile* Tank::useMissile(QPoint posTank, int dir, int puis)
{
    if(nbObus2 > 0){
        nbObus2--;
        return new Missile(posTank, dir, puis);
    }
    else{
        return NULL;
    }
    return NULL;
}

Projectile* Tank::useNuke(QPoint posTank, int dir, int puis)
{
    if(nbObus3 > 0){
        nbObus3--;
        return new Nuke(posTank, dir, puis);
    }
    else{
        return NULL;
    }
    return NULL;
}
