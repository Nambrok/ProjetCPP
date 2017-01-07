#include "arbre.h"

Obus::Obus() : Obstacle(1, 0)
{
    //setResistance(getResistance());
    setCouleur(QColor(91, 60, 17));
    setTexture(new QPixmap(":/sprites/RessourcesProjet/arbre.jpg"));
}
