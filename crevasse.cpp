#include "crevasse.h"

Crevasse::Crevasse() : Obstacle(-2, 1)
{
    setCouleur(Qt::black);
    setTexture(new QPixmap(":/sprites/RessourcesProjet/crevasse.jpg"));
}

Crevasse::~Crevasse(){

}
