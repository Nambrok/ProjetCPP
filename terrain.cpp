#include "terrain.h"

Terrain::Terrain(){
    j1 = new Joueur(new Tank());
    j2 = new Joueur(new Tank());

    for(int i = 0; i<NMAX; i++){
        for(int j = 0; j<NMAX; j++){
            ter[i][j] = new TerrainNormal();
        }
    }

    delete ter[10][10];
    ter[10][10] = j1->getTank();
    delete ter[0][3];
    ter[0][3] = j2->getTank();
}

Obstacle *Terrain::getCase(int i, int j)
{
    return ter[i][j];
}
