#include "terrainnormal.h"

TerrainNormal::TerrainNormal() : Obstacle(0)
{
    setCouleur(Qt::green);
    setTexture(new QPixmap(":/sprites/RessourcesProjet/terrainNormal.jpg"));
}
