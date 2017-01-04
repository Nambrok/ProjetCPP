#include "fenetre.h"
#include "arbre.h"


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Arbre arbre();
    Fenetre fen(900, 600);
    fen.show();
    Terrain ter;
    fen.chargerTerrain(ter);
    return a.exec();
}
