#include "missile.h"

Missile::Missile(QPoint point, int direction, int puissance) : Projectile(point, direction, puissance)
{
    setTailleImpact(2);
    setTexture(new QPixmap(":sprites/RessourcesProjet/missile.png"));

}

Missile::~Missile()
{

}
