#ifndef TERRAIN_H
#define TERRAIN_H
#include "obstacle.h"

#include "arbre.h"
#include "crevasse.h"
#include "eau.h"
#include "roche.h"
#include "terrainnormal.h"

#include "joueur.h"
#include "tank.h"
#include <random>

#define NMAX 30
class Terrain
{
private:
    Obstacle *ter[NMAX][NMAX];
    Joueur *j1;
    Joueur *j2;
public:
    Terrain();
    Obstacle* getCase(int i, int j);
};

#endif // TERRAIN_H
