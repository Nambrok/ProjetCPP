#include "fenetre.h"

Fenetre::Fenetre(int L, int C) : QGraphicsView()
{
    setFixedSize(L, C);
    LMaxTerrain = L*0.75;
    CMaxTerrain = C-3;

    setAlignment(Qt::AlignLeft | Qt::AlignTop);
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QColor(169, 89, 30)));


    QGraphicsRectItem * rect = scene->addRect(0, 0, 100, 100);
    rect->setPos(0, 0);


    qDebug() << rect->scenePos();
    qDebug() << rect->pos();
    //Pourquoi le carré est au milieu ? Alors que je l'initie à (0,0) et après je le bougeais même en (0,0) et il est toujours au MILIEU !!!

    this->setScene(scene);

}
