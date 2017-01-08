#include "jeu.h"


void Jeu::keyPressEvent(QKeyEvent *event)
{
    int dx, dy, ori;
    bool deplacement = false;
    if(event->key() == Qt::Key_Left){
        dx = -1; dy = 0;
        ori = 1;
        deplacement = true;
    }
    else if(event->key() == Qt::Key_Right){
        dx = 1; dy = 0;
        ori = 3;
        deplacement = true;
    }
    else if(event->key() == Qt::Key_Up){
        dx = 0; dy = -1;
        ori = 0;
        deplacement = true;
    }
    else if(event->key() == Qt::Key_Down){
        dx = 0; dy = 1;
        ori = 2;
        deplacement = true;
    }
    if(deplacement){
    if(tankActuel->capaciteRestante()){
        switch(ter.getCase(tankActuel->getAdd().x()+dx, tankActuel->getAdd().y()+dy)->getIdentifiant()){
        case 0:
            tankActuel->setOrientation(ori);
            qDebug() << "Arbre";
            qDebug() << getTour();
            break;
        case 1:
            tankActuel->moveBy(dx, dy);
            tankActuel->enleverCapacite(2);
            tankActuel->setOrientation(ori);
            qDebug() << "Crevasse";
            qDebug() << getTour();
            break;
        case 2:
            tankActuel->moveBy(dx, dy);
            tankActuel->makeZeroCapacite();
            tankActuel->setOrientation(ori);
            qDebug() << "Eau";
            qDebug() << getTour();
            break;
        case 3:
            tankActuel->setOrientation(ori);
            qDebug() << "Roche";
            qDebug() << getTour();
            break;
        case 4:
            tankActuel->moveBy(dx, dy);
            tankActuel->setOrientation(ori);
            tankActuel->enleverCapacite();
            qDebug() << "TerrainNormal";
            qDebug() << getTour();
            break;
        }
        mettreAJourTank();
    }
    deplacement = false;
    }

}

int Jeu::getTypeProjectileSelected() const
{
    return typeProjectileSelected;
}

void Jeu::setTypeProjectileSelected(int value)
{
    typeProjectileSelected = value;
}

QPoint Jeu::identifierCase(QPoint p)
{
    QPoint o(0, 0);
    //On vérifie que le point p ne soit pas en dehors du terrain pour éviter de sortir du tableau et les coups non autorisés.
    if(p.x()<0 || p.x()>LMaxTerrain){
        qDebug() << "Point en dehors du terrain "<< p.x();

    }
    else{
        o.setX(p.x()/(LMaxTerrain/NMAX));
    }

    if(p.y()<0 || p.y()>CMaxTerrain){
        qDebug() << "Point en dehors du terrain " << p.y();
    }
    else{
        o.setY(p.y()/(CMaxTerrain/NMAX));
    }

    return o;
}

Jeu::Jeu(int L, int C) : QGraphicsView()
{
    setFixedSize(L, C);
    //showFullScreen(); Permet le fullscreen de l'application


    LMaxTerrain = L*0.80;
    CMaxTerrain = C;
    setTour(0);
    setTypeProjectileSelected(T_OBUS); // Les obus sont séléctionnés à la création du terrain.

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    setAlignment(Qt::AlignLeft | Qt::AlignTop);
    scene = new QGraphicsScene();
    QBrush background(QColor(169, 89, 30));
    QPalette fondblanc(Qt::black, Qt::white);

    QBrush colJ1(Qt::blue);
    QBrush colJ2(Qt::red);


    QGraphicsRectItem * rect = scene->addRect(0, 0, LMaxTerrain, CMaxTerrain);
    rect->setBrush(background);
    //QUITTER
    QPushButton * sortie = new QPushButton;
    sortie->setText("Quitter");
    QObject::connect(sortie, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
    QGraphicsProxyWidget *proxy = scene->addWidget(sortie);
    proxy->setPos(L-sortie->width() - 2, C-sortie->height()-2);
    //Changer de tour
    QPushButton * change = new QPushButton;
    change->setText("Changer de tour");
    QObject::connect(change, SIGNAL(clicked(bool)), this, SLOT(changerTour()));
    proxy = scene->addWidget(change);
    proxy->setPos(LMaxTerrain + ((L - LMaxTerrain)/2) - (change->width()/2), C*0.60-sortie->height());

    //Afficher Tour
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
    proxy->setPos(LMaxTerrain + ((L - LMaxTerrain)/2) - (nbTour->width()/2), C*0.50);

    //Gestion du facteur horizontal du tank
    QSlider * slideHorizon = new QSlider(Qt::Horizontal);
    slideHorizon->setPalette(fondblanc);
    slideHorizon->setRange(-3, 4);
    slideHorizon->setPageStep(1);
    QObject::connect(slideHorizon, SIGNAL(sliderMoved(int)), this, SLOT(changerHorizonTankActuel(int)));
    proxy = scene->addWidget(slideHorizon);
    proxy->setPos(LMaxTerrain + ((L - LMaxTerrain)/2) - (slideHorizon->width()/2), C*0.50+nbTour->height());
    proxy->setGeometry(QRect(LMaxTerrain, C*0.50+nbTour->height(), L - LMaxTerrain, 10));
    //affichage Puissance

    //Gestion de l'angle de tir du tank
    const int angleMax = NMAX/3; //angleMax définit le maximum que peut atteindre les tirs des chars
    QSlider * slideAngle = new QSlider(Qt::Vertical);
    slideAngle->setPalette(fondblanc);
    slideAngle->setRange(1, angleMax);
    slideAngle->setPageStep(1);
    QObject::connect(slideAngle, SIGNAL(valueChanged(int)), this, SLOT(changerAngleTirActuel(int)));
    proxy = scene->addWidget(slideAngle);
    proxy->setPos(LMaxTerrain + slideAngle->width(), C*0.60);

    //Choix projectile
    /*QRadioButton *radio1 = new QRadioButton(tr("Obus"));
    QRadioButton *radio2 = new QRadioButton(tr("Missile"));
    QRadioButton *radio3 = new QRadioButton(tr("Nuke"));
    radio1->setChecked(true);
    radio1->setPalette(fondblanc);
    radio2->setPalette(fondblanc);
    radio3->setPalette(fondblanc);

    proxy = scene->addWidget(radio1);
    proxy->setPos(LMaxTerrain, 0);
    proxy = scene->addWidget(radio2);
    proxy->setPos(LMaxTerrain + radio1->width(), 0);
    proxy = scene->addWidget(radio3);
    proxy->setPos(LMaxTerrain + radio1->width() + radio2->width(), 0);
    *///QGroupButton marche pas dans ce cas là

    QPushButton * selectObus = new QPushButton(tr("Obus"));
    QPushButton * selectMissile = new QPushButton(tr("Missile"));
    QPushButton * selectNuke = new QPushButton(tr("Nuke"));
    selectObus->setPalette(fondblanc);
    selectMissile->setPalette(fondblanc);
    selectNuke->setPalette(fondblanc);
    QObject::connect(selectObus, SIGNAL(clicked(bool)), this, SLOT(selectObusType()));
    QObject::connect(selectMissile, SIGNAL(clicked(bool)), this, SLOT(selectMissileType()));
    QObject::connect(selectNuke, SIGNAL(clicked(bool)), this, SLOT(selectNukeType()));
    proxy = scene->addWidget(selectObus);
    proxy->setPos(LMaxTerrain, 0);
    proxy = scene->addWidget(selectMissile);
    proxy->setPos(LMaxTerrain, selectObus->height());
    proxy = scene->addWidget(selectNuke);
    proxy->setPos(LMaxTerrain, selectMissile->height() + selectObus->height());

    affTourCoul = scene->addRect(0, 0, 20, 10);
    affTourCoul->setPos(LMaxTerrain + ((L - LMaxTerrain)/2) - 10, C*0.30);
    affTourCoul->setBrush(colJ1);

    QPushButton * tirer = new QPushButton("Tirer");
    proxy = scene->addWidget(tirer);
    proxy->setPos(LMaxTerrain + ((L - LMaxTerrain)/2) - (tirer->width()/2), C*0.60);
    QObject::connect(tirer, SIGNAL(clicked(bool)), this, SLOT(tirer()));

    QLCDNumber * nbMissile = new QLCDNumber;
    nbMissile->setSegmentStyle(QLCDNumber::Flat);
    nbMissile->setPalette(fondblanc);
    QObject::connect(this, SIGNAL(changementNbMissile(int)), nbMissile, SLOT(display(int)));
    proxy = scene->addWidget(nbMissile);
    proxy->setPos(LMaxTerrain + selectMissile->width(), selectObus->height());

    QLCDNumber * nbNuke = new QLCDNumber;
    nbNuke->setSegmentStyle(QLCDNumber::Flat);
    nbNuke->setPalette(fondblanc);
    QObject::connect(this, SIGNAL(changementNbNuke(int)), nbNuke, SLOT(display(int)));
    proxy = scene->addWidget(nbNuke);
    proxy->setPos(LMaxTerrain + selectNuke->width(), selectMissile->height() + selectObus->height());

    this->setScene(scene);
    chargerTerrain();
}

void Jeu::chargerTerrain()
{
    int Lact = 0, Cact = 0;
    //QGraphicsRectItem * rect;

    for(int j = 0; j<NMAX; j++){
        for(int i = 0; i<NMAX; i++){
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

void Jeu::mettreAJourTerrain(){
    int Lact = 0, Cact = 0;
    //QGraphicsRectItem * rect;

    for(int j = 0; j<NMAX; j++){
        for(int i = 0; i<NMAX; i++){
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
}

void Jeu::afficherTankInit(Joueur *j1, Joueur *j2)
{
     j1->getTank()->setCapacite(NMAX/10);
     j2->getTank()->setCapacite(NMAX/10);
     tank1 = scene->addPixmap(j1->getTank()->getTexture().scaled(LMaxTerrain/NMAX, CMaxTerrain/NMAX));
     tank1->setPos((LMaxTerrain/NMAX)*j1->getTank()->getAdd().x(), (CMaxTerrain/NMAX)*j1->getTank()->getAdd().y());
     tank1->setZValue(1);

     tank2 = scene->addPixmap(j2->getTank()->getTexture().scaled(LMaxTerrain/NMAX, CMaxTerrain/NMAX));
     tank2->setPos((LMaxTerrain/NMAX)*j2->getTank()->getAdd().x(), (CMaxTerrain/NMAX)*j2->getTank()->getAdd().y());
     tank2->setZValue(1);
     tankActuel = j1->getTank();
     imgTankActuel = tank1;

     emit changementNbMissile(tankActuel->getNbObus2());
     emit changementNbNuke(tankActuel->getNbObus3());
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
    QBrush colJ1(Qt::blue);
    QBrush colJ2(Qt::red);
    if(getTour() == J1){
        tankActuel = ter.getJ1()->getTank();
        tankActuel->setAngleDeTir(ter.getJ2()->getTank()->getAngleDeTir());
        //On met à jour angleDeTir et l'Horizon du tank qui prend le tour car sinon il sont à l'ancienne donné si on ne touche pas aux sliders.
        tankActuel->setHorizon(ter.getJ2()->getTank()->getHorizon());
        imgTankActuel = tank1;
        affTourCoul->setBrush(colJ1);
    }
    else if(getTour() == J2){
        tankActuel = ter.getJ2()->getTank();
        imgTankActuel = tank2;
        tankActuel->setAngleDeTir(ter.getJ1()->getTank()->getAngleDeTir());
        tankActuel->setHorizon(ter.getJ1()->getTank()->getHorizon());
        affTourCoul->setBrush(colJ2);
    }
    tankActuel->setCapacite(NMAX/10);
    emit changementNbMissile(tankActuel->getNbObus2());
    emit changementNbNuke(tankActuel->getNbObus3());
    emit changementTour(tour);
    if(!ter.getJ1()->getTank()->isAlive()){
        qDebug() << "Victoire Joueur 2";
        victoire(J2);
    }
    else if(!ter.getJ2()->getTank()->isAlive()){
        qDebug() << "Victore Joueur 1";
        victoire(J1);
    }
}

void Jeu::changerHorizonTankActuel(int newH)
{
    tankActuel->setHorizon(newH);
}

void Jeu::changerAngleTirActuel(int newA){
    tankActuel->setAngleDeTir(newA);
}

void Jeu::selectObusType()
{
    setTypeProjectileSelected(T_OBUS);
    //On donne l'identifiant d'un obus
}

void Jeu::selectMissileType(){
    setTypeProjectileSelected(T_MISSILE);
    //Identifiant du missile
}

void Jeu::selectNukeType(){
    //Identifiant bombe nucléaire
    setTypeProjectileSelected(T_NUKE);
}

void Jeu::tirer()
{
    Projectile* tir = tankActuel->useProjectile(tankActuel->getAdd(), tankActuel->getHorizon(), tankActuel->getAngleDeTir(), getTypeProjectileSelected());
    if(tir != NULL){
        if(getTypeProjectileSelected() == T_MISSILE){
            emit changementNbMissile(tankActuel->getNbObus2());
        }
        else if(getTypeProjectileSelected() == T_NUKE){
            emit changementNbNuke(tankActuel->getNbObus3());
        }
        if(tir->getPointImpact() != QPoint(100, 100)){

            QGraphicsPixmapItem *t = scene->addPixmap(tir->getTexture()->scaled(LMaxTerrain/NMAX/5, CMaxTerrain/NMAX/5));
            t->setZValue(1);
            QPoint pos((tir->getPointImpact().x() * LMaxTerrain/NMAX)+LMaxTerrain/NMAX/2, (tir->getPointImpact().y() * CMaxTerrain/NMAX)+CMaxTerrain/NMAX/2);
            t->setPos(pos);
            qDebug()<<"Jeu::tirer : tankActuel : Horizon :" << tankActuel->getHorizon() << " Angle : " << tankActuel->getAngleDeTir();
            qDebug()<< "Jeu::tirer : Point d'impact de tir : " << tir->getPointImpact();
            qDebug() << "Jeu::tirer : tailleImpact : " << tir->getTailleImpact();
            destructionTerrain(tir);
            mettreAJourTerrain();
            changerTour();
        }
        delete tir;
    }
}

void Jeu::destructionTerrain(Projectile *tir){
    QPoint pointImpact = tir->getPointImpact();
    int tailleImpact = tir->getTailleImpact();
    int valeurAEnlever = 1;

    if(tailleImpact == 1){
        verifierImpact(tir->getPointImpact(), valeurAEnlever);
        qDebug()<< "Jeu::destructionTerrain : Point d'Impact de tir :" << pointImpact;
        qDebug()<< "Jeu::destructionTerrain : Case a endommager " << pointImpact.x() << " " << pointImpact.y();
    }
    else if(tailleImpact == 3){
        valeurAEnlever = 3;
        verifierImpact(pointImpact, valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()+1, pointImpact.y()), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x(), pointImpact.y()-1), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()-1, pointImpact.y()), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x(), pointImpact.y()+1), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x(), pointImpact.y()-2), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x(), pointImpact.y()), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()+1, pointImpact.y()-1), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()+2, pointImpact.y()), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()+1, pointImpact.y()+1), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x(), pointImpact.y()+2), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()-1, pointImpact.y()+1), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()-2, pointImpact.y()), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()-1, pointImpact.y()-1), valeurAEnlever);
    }
    else if(tailleImpact == 5){
        valeurAEnlever = 10;
        verifierImpact(pointImpact, valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()+1, pointImpact.y()), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x(), pointImpact.y()-1), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()-1, pointImpact.y()), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x(), pointImpact.y()+1), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x(), pointImpact.y()-2), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x(), pointImpact.y()), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()+1, pointImpact.y()-1), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()+2, pointImpact.y()), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()+1, pointImpact.y()+1), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x(), pointImpact.y()+2), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()-1, pointImpact.y()+1), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()-2, pointImpact.y()), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()-1, pointImpact.y()-1), valeurAEnlever);

        verifierImpact(QPoint(pointImpact.x()+3, pointImpact.y()), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()-3, pointImpact.y()), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x(), pointImpact.y()-3), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x(), pointImpact.y()+3), valeurAEnlever);

        verifierImpact(QPoint(pointImpact.x()-2, pointImpact.y()+1), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()-1, pointImpact.y()+2), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()+1, pointImpact.y()+2), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()+2, pointImpact.y()+1), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()-2, pointImpact.y()-1), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()-1, pointImpact.y()-2), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()+1, pointImpact.y()-2), valeurAEnlever);
        verifierImpact(QPoint(pointImpact.x()+2, pointImpact.y()-1), valeurAEnlever);

    }

}


void Jeu::verifierImpact(QPoint p, int valeurAEnlever){
    ter.setResistanceCase(p, valeurAEnlever);
    ter.tankPresent(p);
}

void Jeu::victoire(int joueurGagnant)
{
    this->setScene(new Victoire(joueurGagnant));
    setAlignment(Qt::AlignCenter);
}
