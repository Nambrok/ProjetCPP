#include "jeu.h"


void Jeu::keyPressEvent(QKeyEvent *event)
{
    int dx, dy, ori;
    if(event->key() == Qt::Key_Left){
        dx = -1; dy = 0;
        ori = 1;
    }
    else if(event->key() == Qt::Key_Right){
        dx = 1; dy = 0;
        ori = 3;
    }
    else if(event->key() == Qt::Key_Up){
        dx = 0; dy = -1;
        ori = 0;
    }
    else if(event->key() == Qt::Key_Down){
        tankActuel->moveBy(0, 1);
        dx = 0; dy = 1;
        ori = 2;
    }

    if(tankActuel->capaciteRestante()){
        switch(ter.getCase(tankActuel->getAdd().x()+dx, tankActuel->getAdd().y()+dy)->getIdentifiant()){
        case 0:
            tankActuel->setOrientation(ori);
            break;
        case 1:
            tankActuel->moveBy(dx, dy);
            tankActuel->enleverCapacite(2);
            tankActuel->setOrientation(ori);
            break;
        case 2:
            tankActuel->moveBy(dx, dy);
            tankActuel->makeZeroCapacite();
            tankActuel->setOrientation(ori);
            break;
        case 3:
            tankActuel->setOrientation(ori);
            break;
        case 4:
            tankActuel->moveBy(dx, dy);
            tankActuel->setOrientation(ori);
            tankActuel->enleverCapacite();
            break;
        }
        mettreAJourTank();
    }

}

Jeu::Jeu(int L, int C) : QGraphicsView()
{
    setFixedSize(L, C);
    //showFullScreen(); Permet le fullscreen de l'application


    LMaxTerrain = L*0.80;
    CMaxTerrain = C;
    setTour(0);

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

    QLCDNumber * nbTour = new QLCDNumber;
    nbTour->setSegmentStyle(QLCDNumber::Flat);
    nbTour->setPalette(fondblanc);
    QObject::connect(this, SIGNAL(changementTour(int)), nbTour, SLOT(display(int)));
    proxy = scene->addWidget(nbTour);
    proxy->setPos(LMaxTerrain + ((L - LMaxTerrain)/2) - (nbTour->width()/2), C*0.50);;



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

     tankActuel = j1->getTank();
     imgTankActuel = tank1;
}

void Jeu::mettreAJourTank()
{
    tank1->setPixmap(ter.getJ1()->getTank()->getTexture().scaled(LMaxTerrain/NMAX, CMaxTerrain/NMAX));
    tank2->setPixmap(ter.getJ2()->getTank()->getTexture().scaled(LMaxTerrain/NMAX, CMaxTerrain/NMAX));
    tank1->setPos((LMaxTerrain/NMAX)*ter.getJ1()->getTank()->getAdd().x(), (CMaxTerrain/NMAX)*ter.getJ1()->getTank()->getAdd().y());
    tank2->setPos((LMaxTerrain/NMAX)*ter.getJ2()->getTank()->getAdd().x(), (CMaxTerrain/NMAX)*ter.getJ2()->getTank()->getAdd().y());
}

int Jeu::getTour()
{
    return tour%2;
}

void Jeu::setTour(int newTour)
{
    this->tour = newTour;
}

void Jeu::changerTour()
{
    tour += 1;
    if(getTour() == J1){
        tankActuel = ter.getJ1()->getTank();
        imgTankActuel = tank1;
    }
    else if(getTour() == J2){
        tankActuel = ter.getJ2()->getTank();
        imgTankActuel = tank2;
    }
    emit changementTour(tour);
}
