#include "terrain.h"

Terrain::Terrain(){
    j1 = new Joueur(new Tank());
    j1i = rand() % 25; j1j = rand() % 25;
    j2i = rand() % 25; j2j = rand() % 25;
    j2 = new Joueur(new Tank());
}
