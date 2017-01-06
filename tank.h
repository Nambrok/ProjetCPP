#ifndef TANK_H
#define TANK_H
#define NBOBUS2 10
#define NBOBUS3 5

#include <QPixmap>
#include <QPoint>
#include <random>

class Tank
{
private:
    int horizon; //Angle du canon horizontalement de 0 à 360°
    int angleDeTir; //0 à 90°
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
    bool useObus1();
    bool useObus2();
    bool useObus3();
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
};

#endif // TANK_H
