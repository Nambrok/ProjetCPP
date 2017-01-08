#include "projectile.h"

QPoint Projectile::getPointImpact() const
{
    return pointImpact;
}

int Projectile::getTailleImpact()
{
    return tailleImpact;
}

void Projectile::setTailleImpact(int value)
{
    tailleImpact = value;
}

QPixmap *Projectile::getTexture() const
{
    return texture;
}

void Projectile::setTexture(QPixmap *value)
{
    texture = value;
}

Projectile::~Projectile()
{
    delete texture;
}

Projectile::Projectile(QPoint point, int direction, int puissance)
{

    //QPoint tmp(point.x() + (puissance*cos(direction)), point.y() + (puissance*sin(direction)));
    //Ancienne version ou on pouvait tirer n'importe ou
    //On imagine un cercle de rayon puissance avec pour centre le tank et on en extrait le point à l'angle direction
    qDebug() << "Point d'origine du tir/ Position du tank : "<<point;
    QPoint tmp = point;
    int dx = 0, dy = 0;
    switch (direction) {
    case 0:
        //haut
        dx = 0; dy = -1;
        break;
    case 1:
        //gauche
        dx = -1; dy = 0;
        break;
    case 2:
        //bas
        dx = 0; dy = 1;
        break;
    case 3:
        //droite
        dx = 1; dy = 0;
        break;
    default:
        break;
    }
    QPoint dir(dx, dy);
    qDebug() << "Direction du projectile : "<<dir;
    for(int i = 0; i<puissance; i++){
           tmp += dir;
    }
    if(tmp.x()<0){
        qDebug() << "Tir en dehors x";
    }
    else{
        pointImpact = tmp;
    }
    if(tmp.y()<0){
        qDebug() << "Tir en dehors y";
    }
    else{
        pointImpact = tmp;
    }
}
