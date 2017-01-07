#include "joueur.h"

Tank *Joueur::getTank() const
{
    return tank;
}

void Joueur::setTank(Tank *value)
{
    tank = value;
}

Joueur::~Joueur()
{
    delete tank;
}

Joueur::Joueur(Tank *newTank)
{
    setTank(newTank);
}
