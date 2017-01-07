#include "terrain.h"

Terrain::Terrain(){
    j1 = new Joueur(new Tank());
    j2 = new Joueur(new Tank());

    j1->getTank()->setTextureBas(new QPixmap(":/sprites/RessourcesProjet/bleuBas.png"));
    j1->getTank()->setTextureDroite(new QPixmap(":/sprites/RessourcesProjet/bleuDroit.png"));
    j1->getTank()->setTextureGauche(new QPixmap(":/sprites/RessourcesProjet/bleuGauche.png"));
    j1->getTank()->setTextureHaut(new QPixmap(":/sprites/RessourcesProjet/bleuHaut.png"));

    j2->getTank()->setTextureBas(new QPixmap(":/sprites/RessourcesProjet/rougeBas.png"));
    j2->getTank()->setTextureDroite(new QPixmap(":/sprites/RessourcesProjet/rougeDroit.png"));
    j2->getTank()->setTextureGauche(new QPixmap(":/sprites/RessourcesProjet/rougeGauche.png"));
    j2->getTank()->setTextureHaut(new QPixmap(":/sprites/RessourcesProjet/rougeHaut.png"));

    j1->getTank()->setAdd(QPoint(0,0));
    j2->getTank()->setAdd(QPoint(10, 10));
    srand(time(NULL));
    for(int i = 0; i<NMAX; i++){
        for(int j = 0; j<NMAX; j++){
            switch (rand() % 15) {
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
                          default:
                            ter[i][j] = new TerrainNormal();
                            break;
            }
        }
    }
}

Obstacle *Terrain::getCase(int i, int j)
{
    return ter[i][j];
}

Joueur *Terrain::getJ1()
{
    return j1;
}

Joueur *Terrain::getJ2()
{
    return j2;
}

void Terrain::setTerrainNormal(int i, int j)
{
    delete ter[i][j];
    ter[i][j] = new TerrainNormal();
}
