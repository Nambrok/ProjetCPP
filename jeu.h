#ifndef JEU_H
#define JEU_H

#define J1 0
#define J2 1

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

#include <QKeyEvent>


#include "terrain.h"
#include "obstacle.h"
#include "arbre.h"
#include "crevasse.h"
#include "eau.h"
#include "roche.h"
#include "tank.h"
#include "terrainnormal.h"
#include "joueur.h"

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

public:
    Jeu(int L, int C);
    void chargerTerrain();
    void afficherTankInit(Joueur *j1, Joueur *j2);
    void mettreAJourTank();
    int getTour();
    void setTour(int newTour);
    void choisirTankActuel();

signals:
    void changementTour(int tour);

public slots:
    void changerTour();
};

#endif // JEU_H
