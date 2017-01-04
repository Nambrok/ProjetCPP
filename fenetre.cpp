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

void Fenetre::chargerTerrain(Terrain ter)
{
    int Lact = 0, Cact = 0;
    QGraphicsRectItem * rect;

    for(int i = 0; i<NMAX; i++){
        for(int j = 0; j<NMAX; j++){
            Obstacle* ob = ter.getCase(i, j);
            rect = new QGraphicsRectItem(Lact, Cact, LMaxTerrain/NMAX, CMaxTerrain/NMAX);
            rect->setBrush(ob->getCouleur());
            scene->addItem(rect);
            Lact+= LMaxTerrain/NMAX;
        }
        Lact = 0;
        Cact += CMaxTerrain/NMAX;
    }
}
