#include "obstacle.h"

Obstacle::Obstacle(){
    resistance = 0;
    resistanceOriginal = 0;
}

Obstacle::Obstacle(int resOri, int newIdentifiant){
    resistanceOriginal = resOri;
    resistance = resistanceOriginal;
    identifiant = newIdentifiant;
}

void Obstacle::setResistanceOriginal(int resOri){
    resistanceOriginal = resOri;
    resistance = resistanceOriginal;
}

int Obstacle::getIdentifiant() const
{
    return identifiant;
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

QPixmap Obstacle::getTexture()
{
    return *texture;
}

void Obstacle::setTexture(QPixmap *newTexture)
{
    texture = newTexture;
}

Obstacle::~Obstacle(){
    delete texture;
}
