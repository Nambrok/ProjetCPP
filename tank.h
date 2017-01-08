#ifndef TANK_H
#define TANK_H
#define NBOBUS2 10
#define NBOBUS3 5
#define T_OBUS 0
#define T_MISSILE 1
#define T_NUKE 2

#include <QPixmap>
#include <QPoint>
#include <QPointF>
#include <random>
#include <vector>
#include <projectile.h>
#include <obus.h>
#include <missile.h>
#include <nuke.h>

class Tank
{
private:
    int horizon; //Angle du canon horizontalement de 0 à 360°
    int angleDeTir;
    int capacite; //capacité de déplacement restant au tank initialisé à L/10
    int nbObus2 = NBOBUS2;
    int nbObus3 = NBOBUS3;
    bool alive;
    QPoint add;
    int orientation; // orientation, 0 haut, 1 gauche, 2 bas, 3 droite
    QPixmap * textureHaut;
    QPixmap * textureBas;
    QPixmap * textureGauche;
    QPixmap * textureDroite;

public:
    Tank();
    bool isAlive();
    Projectile *useObus(QPoint posTank, int dir, int puis);
    Projectile *useMissile(QPoint posTank, int dir, int puis);
    Projectile *useNuke(QPoint posTank, int dir, int puis);
    int getNbObus2() const;
    int getNbObus3() const;

    int getOrientation() const;
    void setOrientation(int value);

    bool enleverCapacite();
    bool enleverCapacite(int cx);
    void makeZeroCapacite();
    bool capaciteRestante();
    void setCapacite(int newCap);

    QPixmap getTexture();
    void setTextureGauche(QPixmap* newTexture);
    void setTextureDroite(QPixmap* newTexture);
    void setTextureHaut(QPixmap* newTexture);
    void setTextureBas(QPixmap* newTexture);
    QPoint getAdd() const;
    void setAdd(const QPoint &value);

    void moveBy(int dx, int dy);
    int getHorizon() const;
    void setHorizon(int value);
    int getAngleDeTir() const;
    void setAngleDeTir(int value);

    ~Tank();
    Projectile *useProjectile(QPoint posTank, int dir, int puis, int type);
};

#endif // TANK_H
