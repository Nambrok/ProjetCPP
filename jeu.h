#ifndef JEU_H
#define JEU_H

#define J1 0
#define J2 1
#define T_OBUS 0
#define T_MISSILE 1
#define T_NUKE 2

#include <QApplication>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBrush>
#include <QColor>
#include <QLine>
#include <QPushButton>
#include <QGraphicsRectItem>
#include <QGraphicsProxyWidget>
#include <QGraphicsPixmapItem>
#include <QPoint>
#include <QLabel>
#include <QPalette>
#include <QLCDNumber>
#include <QSlider>
#include <QRadioButton>

#include <QKeyEvent>
#include <time.h>


#include "terrain.h"
#include "obstacle.h"
#include "arbre.h"
#include "crevasse.h"
#include "eau.h"
#include "roche.h"
#include "tank.h"
#include "terrainnormal.h"
#include "joueur.h"
#include "victoire.h"
#include "joueuria.h"

#include <QDebug>

class Jeu : public QGraphicsView
{
    Q_OBJECT
private:
    int tour;
    QGraphicsScene * scene;
    int LMaxTerrain, CMaxTerrain;
    Terrain ter;
    QGraphicsPixmapItem *tank1;
    QGraphicsPixmapItem *tank2;
    Tank *tankActuel;
    QGraphicsPixmapItem *imgTankActuel;
    void keyPressEvent(QKeyEvent *event);
    int typeProjectileSelected;//0 obus, 1 missile, 2 nuke
    QGraphicsRectItem * affTourCoul;
    bool IA;


public:
    Jeu(int L, int C);
    void chargerTerrain();
    void mettreAJourTerrain();
    void afficherTankInit(Joueur *j1, Joueur *j2);
    void mettreAJourTank();
    int getTour();
    void setTour(int newTour);

    void destructionTerrain(Projectile* tir);

    int getTypeProjectileSelected() const;
    void setTypeProjectileSelected(int value);

    QPoint identifierCase(QPoint p);
    void verifierImpact(QPoint p, int valeurAEnlever);

    void victoire(int joueurGagnant);

    bool isIAActive();
    void setIAActive(bool b);

signals:
    void changementTour(int tour);
    void fermeture();
    void changementNbMissile(int newNbMissile);
    void changementNbNuke(int newNbNuke);

public slots:
    void changerTour();
    void changerHorizonTankActuel(int newH);
    void tirer();
    void changerAngleTirActuel(int newA);
    void selectObusType();
    void selectMissileType();
    void selectNukeType();
};

#endif // JEU_H
