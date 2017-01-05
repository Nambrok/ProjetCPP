#ifndef FENETRE_H
#define FENETRE_H

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


#include "terrain.h"
#include "obstacle.h"
#include "arbre.h"
#include "crevasse.h"
#include "eau.h"
#include "roche.h"
#include "tank.h"
#include "terrainnormal.h"
#include "joueur.h"

class Fenetre : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene * scene;
    int LMaxTerrain, CMaxTerrain;
    QGraphicsPixmapItem *tank1;
    QGraphicsPixmapItem *tank2;

public:
    Fenetre(int L, int C);
    void chargerTerrain(Terrain ter);
    void afficherTankInit(Joueur *j1, Joueur *j2);
    void moveTank1(int i, int j);
    void moveTank2(int i, int j);

signals:

public slots:
};

#endif // FENETRE_H
