#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <QColor>

class Obstacle{
private:
    int resistance;
    int resistanceOriginal;
    void setResistanceOriginal(int resOri);
    QColor couleur;

public:
    Obstacle();
    Obstacle(int resOri);
    void setResistance(int newRes);
    int getResistance();
    int getResistanceOriginal();
    QColor getCouleur();
    void setCouleur(QColor newCouleur);
};

#endif // OBSTACLE_H
