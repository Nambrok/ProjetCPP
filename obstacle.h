#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <QColor>
#include <QPixmap>

class Obstacle{
private:
    int resistance;
    int resistanceOriginal;
    void setResistanceOriginal(int resOri);
    QColor couleur;
    QPixmap *texture;

public:
    Obstacle();
    Obstacle(int resOri);
    void setResistance(int newRes);
    int getResistance();
    int getResistanceOriginal();
    QColor getCouleur();
    void setCouleur(QColor newCouleur);
    QPixmap getTexture();
protected:
    void setTexture(QPixmap *newTexture);
};

#endif // OBSTACLE_H
