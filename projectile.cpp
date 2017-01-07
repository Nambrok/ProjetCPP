#include "projectile.h"

QPointF Projectile::getPointImpact() const
{
    return pointImpact;
}

int Projectile::getTailleImpact()
{
    return tailleImpact;
}

void Projectile::setTailleImpact(int value)
{
    tailleImpact = value;
}

QPixmap *Projectile::getTexture() const
{
    return texture;
}

void Projectile::setTexture(QPixmap *value)
{
    texture = value;
}

Projectile::Projectile(QPointF point, int direction, int puissance)
{

    QPointF tmp(point.x() + (puissance*cos(direction)), point.y() + (puissance*sin(direction)));
    //On imagine un cercle de rayon puissance avec pour centre le tank et on en extrait le point à l'angle direction
    pointImpact = tmp;
}
