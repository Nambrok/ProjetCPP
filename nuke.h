#ifndef NUKE_H
#define NUKE_H

#include <QDebug>
#include <QPoint>
#include <projectile.h>

class Nuke : public Projectile
{
public:
    Nuke(QPoint point, int direction, int puissance);
};

#endif // NUKE_H
