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
//direction est un entier entre 0 et 359, on doit en déduire la direction sous forme d'un QPoint pour l'utiliser comme vecteur ensuite
    QPointF tmp(point.x() + (puissance*cos(direction)), point.y() + (puissance*sin(direction)));
    pointImpact = tmp;
}
