#include "obus.h"


Obus::Obus(QPoint point, int direction, int puissance) : Projectile(point, direction, puissance)
{
 setTailleImpact(1);
 setTexture(new QPixmap(":/sprites/RessourcesProjet/obus.png"));
}

Obus::~Obus(){

}
