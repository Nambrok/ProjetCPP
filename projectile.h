#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QPoint>

class Projectile
{
private:
    int pointImpact;
public:
    Projectile(QPoint point, QPoint direction, int puissance);

    int getPointImpact() const;
};

#endif // PROJECTILE_H
