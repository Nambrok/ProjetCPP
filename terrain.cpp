#include "terrain.h"

Terrain::Terrain(){
    j1 = new Joueur(new Tank());
    j2 = new Joueur(new Tank());

    for(int i = 0; i<NMAX; i++){
        for(int j = 0; j<NMAX; j++){
            switch (rand() % 5) {
             case 0:
                ter[i][j] = new Arbre();
                break;
             case 1:
                ter[i][j] = new Crevasse();
                break;
              case 2:
                ter[i][j] = new Eau();
                break;
              case 3:
                ter[i][j] = new Roche();
                break;
              case 4:
                ter[i][j] = new TerrainNormal();
                break;
              default:
                break;
            }
        }
    }
}

Obstacle *Terrain::getCase(int i, int j)
{
    return ter[i][j];
}
