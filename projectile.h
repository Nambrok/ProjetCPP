#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QPoint>
#include <QPixmap>
#include <QDebug>

class Projectile
{
private:
    QPoint pointImpact;
    int tailleImpact;
    QPixmap* texture;

public:
    Projectile(QPoint point, int direction, int puissance);

    QPoint getPointImpact() const;
    int getTailleImpact();
    void setTailleImpact(int value);
    QPixmap *getTexture() const;
    void setTexture(QPixmap *value);

    ~Projectile();
};

#endif // PROJECTILE_H
