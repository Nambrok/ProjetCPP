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
    Projectile(QPointF point, int direction, int puissance);

    QPointF getPointImpact() const;
    int getTailleImpact();
    void setTailleImpact(int value);
    QPixmap *getTexture() const;
    void setTexture(QPixmap *value);

    ~Projectile();
};

#endif // PROJECTILE_H
