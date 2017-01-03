#ifndef TERRAIN_H
#define TERRAIN_H
#include "obstacle.h"
#include "joueur.h"
#define NMAX 25
class Terrain
{
private:
    Obstacle ter[NMAX][NMAX];
    Joueur *j1;
    Joueur *j2;
public:
    Terrain();
};

#endif // TERRAIN_H
