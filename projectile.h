#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QPoint>

class Projectile
{
private:
    QPoint pointImpact;
protected:
    int tailleImpact;
public:
    Projectile(QPoint point, QPoint direction, int puissance);

    QPoint getPointImpact() const;
    int getTailleImpact();
    void setTailleImpact(int value);
};

#endif // PROJECTILE_H
