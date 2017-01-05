#include "eau.h"
#define RMAX 100
Eau::Eau() : Obstacle(RMAX)
{
    setCouleur(Qt::blue);
    setTexture(new QPixmap(":/sprites/RessourcesProjet/eau.jpg"));
}
