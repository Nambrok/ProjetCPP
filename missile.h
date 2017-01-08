#ifndef MISSILE_H
#define MISSILE_H

#include <QDebug>
#include <projectile.h>
#include <QPoint>

class Missile : public Projectile
{
public:
    Missile(QPoint point, int direction, int puissance);
    ~Missile();
};

#endif // MISSILE_H
