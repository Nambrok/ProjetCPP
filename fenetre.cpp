#include "fenetre.h"

Fenetre::Fenetre(int L, int C) : QGraphicsView()
{
    setFixedSize(L, C);
    LMaxTerrain = L*0.75;
    CMaxTerrain = C-3;


    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QColor(169, 89, 30)));


    QGraphicsRectItem * rect = new QGraphicsRectItem(0, 0, 10, 10);
    //Pourquoi le carré est au milieu ? Alors que je l'initie à (0,0) et après je le bougeais même en (0,0) et il est toujours au MILIEU !!!
    scene->addItem(rect);


    sortie = new QPushButton(this);
    sortie->setText("Quitter");
    sortie->move(L - sortie->width(), C - sortie->height());

    this->setScene(scene);


    QObject::connect(sortie, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
}
