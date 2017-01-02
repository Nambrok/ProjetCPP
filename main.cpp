#include "fenetre.h"


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Fenetre fen(600, 350);
    fen.show();
    return a.exec();
}
