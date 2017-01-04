#include "terrain.h"

Terrain::Terrain(){
    j1 = new Joueur(new Tank());
    j2 = new Joueur(new Tank());

    for(int i = 0; i<NMAX; i++){
        for(int j = 0; j<NMAX; j++){
            ter[i][j] = new TerrainNormal();
        }
    }
}

Obstacle *Terrain::getCase(int i, int j)
{
    return ter[i][j];
}
