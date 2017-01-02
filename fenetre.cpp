#include "fenetre.h"

Fenetre::Fenetre(int L, int C) : QWidget()
{
    setFixedSize(L, C);
    LMaxTerrain = L * 0.75;
    CMaxTerrain = C;

    sortie = new QPushButton(this);
    sortie->setText("Quitter");
    sortie->move(L - sortie->width(), C - sortie->height());

    QObject::connect(sortie, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
}
