#ifndef TERRAIN_H
#define TERRAIN_H
#include "obstacle.h"
#include "terrainnormal.h"
#include "joueur.h"
#include <random>

#define NMAX 25
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
