#include "fenetre.h"

#define Largeur 900
#define Longueur 600

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Fenetre fen(Largeur, Longueur);
    fen.show();
    Terrain ter;
    fen.chargerTerrain(ter);
    return a.exec();
}
