#ifndef JOUEUR_H
#define JOUEUR_H
#include "tank.h"

class Joueur
{
private:
    Tank * tank;
public:
    Joueur(Tank *newTank);
    Tank *getTank() const;
    void setTank(Tank *value);
    ~Joueur();
};

#endif // JOUEUR_H
