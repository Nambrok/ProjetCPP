#ifndef OBUS_H
#define OBUS_H
#include <QPixmap>
#include <QPoint>
#include <random>
#include <QColor>

class Tank
{
private:
    int degats;
    int radius; //point central + rayon de radius
    QColor couleur;
    QPixmap *texture;
    QPoint impact;
public:
    Obstacle();
    void setDegats(int newDmg);
    int getRadius();
    int getDegats();
    QColor getCouleur();
    void setCouleur(QColor newCouleur);
    QPixmap getTexture();

protected:
    void setTexture(QPixmap *newTexture);
#endif // OBUS_H
