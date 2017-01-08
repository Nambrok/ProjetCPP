#include "joueuria.h"

JoueurIA::JoueurIA(Tank *newTank) : Joueur(newTank)
{

}

void JoueurIA::setTir(Tank *tankEnnemi)
{
    int dx = 0;
    int dy = 0;
    int posL = getTank()->getAdd().x()-tankEnnemi->getAdd().x();
    if(posL > 0){
        //Le tank ennemi est à droite
        dx = 1;
    }
    else if(posL < 0){
        //Le tank ennemi est à gauche
        dx = -1;
    }
    else{
        //Le tank ennemi est sur le même x
    }

    int posC = getTank()->getAdd().y() - tankEnnemi->getAdd().y();
    if(posC>0){
        //Le tank est en dessous
        dy = 1;
    }
    else if(posC<0){
        //Le tank est au dessus
        dy = -1;
    }
    else{
        //Le tank est sur le même y
    }

    if(dx==1){
        if(dy==-1){
            //Hautdroite
            getTank()->setHorizon(1);
        }
        else if(dy == 0){
            //Droite
            getTank()->setHorizon(2);
        }
        else if(dy == 1){
            //basDroite
            getTank()->setHorizon(3);
        }
    }
    else if(dx == 0){
        if(dy==-1){
            //Haut
            getTank()->setHorizon(0);
        }
        else if(dy == 0){
            //milieu, devrait pas arriver
            getTank()->setHorizon(0);
        }
        else if(dy == 1){
            //bas
            getTank()->setHorizon(4);
        }
    }
    else if(dx == -1){
        if(dy==-1){
            //HautGauche
            getTank()->setHorizon(-1);
        }
        else if(dy == 0){
            //gauche
            getTank()->setHorizon(-2);
        }
        else if(dy == 1){
            //BasGauche
            getTank()->setHorizon(-3);
        }
    }

    getTank()->setAngleDeTir(sqrt(((tankEnnemi->getAdd().x() - getTank()->getAdd().x())*2)+((tankEnnemi->getAdd().y() - getTank()->getAdd().y())*2)));
}
