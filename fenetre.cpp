#include "fenetre.h"

Fenetre::Fenetre(int L, int C) : QGraphicsView()
{
    setFixedSize(L, C);
    //showFullScreen(); Permet le fullscreen de l'application


    LMaxTerrain = L*0.80;
    CMaxTerrain = C;

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


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
    //QGraphicsRectItem * rect;

    for(int i = 0; i<NMAX; i++){
        for(int j = 0; j<NMAX; j++){
            Obstacle* ob = ter.getCase(i, j);

           // rect = new QGraphicsRectItem(Lact, Cact, LMaxTerrain/NMAX, CMaxTerrain/NMAX);
           // rect->setBrush(ob->getCouleur());

            QGraphicsPixmapItem * pix = scene->addPixmap(ob->getTexture().scaled(LMaxTerrain/NMAX, CMaxTerrain/NMAX));
            pix->setPos(Lact, Cact);

            //scene->addItem(rect);
            Lact+= LMaxTerrain/NMAX;
        }
        Lact = 0;
        Cact += (CMaxTerrain)/NMAX;
    }

    afficherTankInit(ter.getJ1(), ter.getJ2());
}

void Fenetre::afficherTankInit(Joueur *j1, Joueur *j2)
{
     tank1 = scene->addPixmap(j1->getTank()->getTexture().scaled(LMaxTerrain/NMAX, CMaxTerrain/NMAX));
     tank1->setPos((LMaxTerrain/NMAX)*j1->getTank()->getAdd().x(), (CMaxTerrain/NMAX)*j1->getTank()->getAdd().y());

     tank2 = scene->addPixmap(j2->getTank()->getTexture().scaled(LMaxTerrain/NMAX, CMaxTerrain/NMAX));
     tank2->setPos((LMaxTerrain/NMAX)*j2->getTank()->getAdd().x(), (CMaxTerrain/NMAX)*j2->getTank()->getAdd().y());
}

void Fenetre::moveTank1(int i, int j)
{
    tank1->setPos((LMaxTerrain/NMAX)*i, (CMaxTerrain/NMAX)*j);
}

void Fenetre::moveTank2(int i, int j)
{
    tank2->setPos((LMaxTerrain/NMAX)*i, (CMaxTerrain/NMAX)*j);
}
