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
    int identifiant;

public:
    Obstacle();
    Obstacle(int resOri, int newIdentifiant);
    void setResistance(int newRes);
    int getResistance();
    int getResistanceOriginal();
    QColor getCouleur();
    void setCouleur(QColor newCouleur);
    QPixmap getTexture();
    int getIdentifiant() const;
    ~Obstacle();

protected:
    void setTexture(QPixmap *newTexture);
};

#endif // OBSTACLE_H
