#include "arbre.h"

Arbre::Arbre() : Obstacle(1)
{
    //setResistance(getResistance());
    setCouleur(QColor(91, 60, 17));
    setTexture(new QPixmap(":/sprites/RessourcesProjet/arbre.jpg"));
}
