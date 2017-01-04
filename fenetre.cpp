#include "fenetre.h"

Fenetre::Fenetre(int L, int C) : QGraphicsView()
{
    setFixedSize(L, C);
    LMaxTerrain = L*0.75;
    CMaxTerrain = C-3;

    setAlignment(Qt::AlignLeft | Qt::AlignTop);
    scene = new QGraphicsScene();
    QBrush background(QColor(169, 89, 30));



    QGraphicsRectItem * rect = scene->addRect(0, 0, LMaxTerrain, CMaxTerrain);
    rect->setBrush(background);

    QPushButton * sortie = new QPushButton;
    sortie->setText("Quitter");
    QObject::connect(sortie, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
    QGraphicsProxyWidget *proxy = scene->addWidget(sortie);
    proxy->setPos(LMaxTerrain + ((L - LMaxTerrain)/2) - (sortie->width()/2), C*0.75);

    this->setScene(scene);

}
