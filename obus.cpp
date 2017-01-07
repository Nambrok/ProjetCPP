#include "obus.h"


Obus::Obus(QPoint point, QPoint direction, int puissance) : Projectile(point, direction, puissance)
{
 setTailleImpact(1);
}
