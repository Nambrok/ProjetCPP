#include "jeu.h"

void Jeu::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){

    }
}

Jeu::Jeu(int L, int C) : QGraphicsView()
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
    QPalette fondblanc(Qt::black, Qt::white);



    QGraphicsRectItem * rect = scene->addRect(0, 0, LMaxTerrain, CMaxTerrain);
    rect->setBrush(background);

    QPushButton * sortie = new QPushButton;
    sortie->setText("Quitter");
    QObject::connect(sortie, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
    QGraphicsProxyWidget *proxy = scene->addWidget(sortie);
    proxy->setPos(LMaxTerrain + ((L - LMaxTerrain)/2) - (sortie->width()/2), C*0.60);

    QPushButton * change = new QPushButton;
    change->setText("Changer de tour");
    QObject::connect(change, SIGNAL(clicked(bool)), this, SLOT(changerTour()));
    proxy = scene->addWidget(change);
    proxy->setPos(LMaxTerrain + ((L - LMaxTerrain)/2) - (change->width()/2), C*0.60-sortie->height());

    QLabel * tour = new QLabel;
    tour->setText("Tour :");
    tour->setPalette(fondblanc);
    proxy = scene->addWidget(tour);
    proxy->setPos(LMaxTerrain + ((L - LMaxTerrain)/2) - (sortie->width()), C*0.50);

    this->setScene(scene);
    chargerTerrain();
}

void Jeu::chargerTerrain()
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

void Jeu::afficherTankInit(Joueur *j1, Joueur *j2)
{
     tank1 = scene->addPixmap(j1->getTank()->getTexture().scaled(LMaxTerrain/NMAX, CMaxTerrain/NMAX));
     tank1->setPos((LMaxTerrain/NMAX)*j1->getTank()->getAdd().x(), (CMaxTerrain/NMAX)*j1->getTank()->getAdd().y());

     tank2 = scene->addPixmap(j2->getTank()->getTexture().scaled(LMaxTerrain/NMAX, CMaxTerrain/NMAX));
     tank2->setPos((LMaxTerrain/NMAX)*j2->getTank()->getAdd().x(), (CMaxTerrain/NMAX)*j2->getTank()->getAdd().y());
}

void Jeu::moveTank1()
{
    tank1->setPos((LMaxTerrain/NMAX)*ter.getJ1()->getTank()->getAdd().x(), (CMaxTerrain/NMAX)*ter.getJ1()->getTank()->getAdd().y());
}

void Jeu::moveTank2()
{
    tank2->setPos((LMaxTerrain/NMAX)*ter.getJ2()->getTank()->getAdd().x(), (CMaxTerrain/NMAX)*ter.getJ2()->getTank()->getAdd().y());
}

void Jeu::changerTour()
{

}
