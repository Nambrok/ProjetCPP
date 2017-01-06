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
#include <time.h>

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
    Joueur* getJ1();
    Joueur* getJ2();
};

#endif // TERRAIN_H
