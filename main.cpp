#include "fenetre.h"
#include "arbre.h"


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Arbre arbre();
    Fenetre fen(600, 350);
    fen.show();
    return a.exec();
}
