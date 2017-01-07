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

Projectile::Projectile(QPointF point, QPoint direction, int puissance)
{
    for(int i = 0; i<puissance; i++){
        point += direction;
    }

    pointImpact = point;
}
