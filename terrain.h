#ifndef TERRAIN_H
#define TERRAIN_H
#include "obstacle.h"
#include "joueur.h"
#include <random>

#define NMAX 25
class Terrain
{
private:
    Obstacle ter[NMAX][NMAX];
    Joueur *j1;
    int j1i, j1j;
    int j2i, j2j;
    Joueur *j2;
public:
    Terrain();
};

#endif // TERRAIN_H
