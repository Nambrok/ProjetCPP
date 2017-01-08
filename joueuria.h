#ifndef JOUEURIA_H
#define JOUEURIA_H

#include <joueur.h>
class JoueurIA : public Joueur
{
public:
    JoueurIA(Tank *newTank);
    void setTir(Tank *tankEnnemi);
};

#endif // JOUEURIA_H
