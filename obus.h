#ifndef OBUS_H
#define OBUS_H
#include "projectile.h"

class Obus : public Projectile
{
public:
    Obus(QPoint point, int direction, int puissance);
    ~Obus();
};

#endif // OBUS_H
