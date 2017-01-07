#include "roche.h"

Roche::Roche() : Obstacle(7, 3)
{
    setCouleur(Qt::gray);
    setTexture(new QPixmap(":/sprites/RessourcesProjet/roche.jpg"));
}

Roche::~Roche()
{

}
