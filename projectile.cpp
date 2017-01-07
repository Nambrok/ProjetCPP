#include "projectile.h"

QPoint Projectile::getPointImpact() const
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

Projectile::Projectile(QPoint point, QPoint direction, int puissance)
{
    for(int i = 0; i<puissance; i++){
        point += direction;
    }

    pointImpact = point;
}
