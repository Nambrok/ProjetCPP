#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QPoint>
#include <QPixmap>

class Projectile
{
private:
    QPointF pointImpact;
    int tailleImpact;
    QPixmap* texture;

public:
    Projectile(QPointF point, QPoint direction, int puissance);

    QPointF getPointImpact() const;
    int getTailleImpact();
    void setTailleImpact(int value);
    QPixmap *getTexture() const;
    void setTexture(QPixmap *value);
};

#endif // PROJECTILE_H
