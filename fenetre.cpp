#include "fenetre.h"

Fenetre::Fenetre(int L, int C) : QGraphicsView()
{
    setFixedSize(L, C);
    LMaxTerrain = L*0.75;
    CMaxTerrain = C-3;

    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QColor(169, 89, 30)));

    QRect rect(0, 0, LMaxTerrain, CMaxTerrain);
    scene->addRect(rect);
    scene->addEllipse(rect);

    sortie = new QPushButton(this);
    sortie->setText("Quitter");
    sortie->move(L - sortie->width(), C - sortie->height());

    this->setScene(scene);


    QObject::connect(sortie, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
}
