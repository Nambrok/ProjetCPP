#ifndef TERRAIN_H
#define TERRAIN_H
#include "obstacle.h"
#define NMAX 25
class Terrain
{
private:
    Obstacle ter[NMAX][NMAX];
public:
    Terrain();
};

#endif // TERRAIN_H
