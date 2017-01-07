#include "eau.h"
#define RMAX 100
Eau::Eau() : Obstacle(RMAX, 2)
{
    setCouleur(Qt::blue);
    setTexture(new QPixmap(":/sprites/RessourcesProjet/eau.jpg"));
}

Eau::~Eau()
{

}
