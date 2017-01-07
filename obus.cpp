#include "obus.h"


Obus::Obus(QPointF point, int direction, int puissance) : Projectile(point, direction, puissance)
{
 setTailleImpact(1);
 setTexture(new QPixmap(":/sprites/RessourcesProjet/obus.png"));
}
