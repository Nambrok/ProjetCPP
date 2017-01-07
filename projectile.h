#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QPoint>

class Projectile
{
private:
    int pointImpact;
    int tailleImpact;
public:
    Projectile(QPoint point, QPoint direction, int puissance);

    int getPointImpact() const;
    virtual int getTailleImpact();
    void setTailleImpact(int value);
};

#endif // PROJECTILE_H
