#include "jeu.h"

#define Largeur 900
#define Longueur 600

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Jeu fen(Largeur, Longueur);
    fen.show();
    return a.exec();
}
