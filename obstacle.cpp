#include "obstacle.h"

Obstacle::Obstacle(){
    resistance = 0;
    resistanceOriginal = 0;
}

Obstacle::Obstacle(int resOri){
    resistanceOriginal = resOri;
    resistance = resistanceOriginal;
}

void Obstacle::setResistanceOriginal(int resOri){
    resistanceOriginal = resOri;
    resistance = resistanceOriginal;
}

void Obstacle::setResistance(int newRes){
 resistance = newRes;
}

int Obstacle::getResistance(){
    return resistance;
}

int Obstacle::getResistanceOriginal(){
    return resistanceOriginal;
}

QColor Obstacle::getCouleur()
{
    return couleur;
}

void Obstacle::setCouleur(QColor newCouleur)
{
    couleur = newCouleur;
}
