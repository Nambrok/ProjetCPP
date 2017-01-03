#include "fenetre.h"

Fenetre::Fenetre(int L, int C) : QGraphicsView()
{
    setFixedSize(L, C);
    LMaxTerrain = L*0.75;
    CMaxTerrain = C-3;

    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QColor(169, 89, 30)));

    QGraphicsRectItem *rect[NMAX];
    for(int i = 0; i<NMAX; i++){
        rect[i] = new QGraphicsRectItem(i * (LMaxTerrain/NMAX), CMaxTerrain/NMAX, LMaxTerrain/NMAX, CMaxTerrain/NMAX);
        rect[i]->setPos(i * (LMaxTerrain/NMAX), CMaxTerrain/NMAX);
        scene->addItem(rect[i]);
    }

    sortie = new QPushButton(this);
    sortie->setText("Quitter");
    sortie->move(L - sortie->width(), C - sortie->height());

    this->setScene(scene);


    QObject::connect(sortie, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
}
