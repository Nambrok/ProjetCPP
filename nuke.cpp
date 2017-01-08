#include "nuke.h"

Nuke::Nuke(QPoint point, int direction, int puissance) : Projectile(point, direction, puissance)
{
    setTailleImpact(5);
    setTexture(new QPixmap(":sprites/RessourcesProjet/nuke.png"));
}
