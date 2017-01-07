#ifndef OBUS_H
#define OBUS_H
#include "projectile.h"

class Obus : public Projectile
{
public:
    Obus(QPointF point, QPoint direction, int puissance);
};

#endif // OBUS_H
