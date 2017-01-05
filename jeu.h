#ifndef JEU_H
#define JEU_H

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
    QGraphicsScene * scene;
    int LMaxTerrain, CMaxTerrain;
    Terrain ter;
    QGraphicsPixmapItem *tank1;
    QGraphicsPixmapItem *tank2;
    void keyPressEvent(QKeyEvent *event);


public:
    Jeu(int L, int C);
    void chargerTerrain();
    void afficherTankInit(Joueur *j1, Joueur *j2);
    void moveTank1();
    void moveTank2();

signals:

public slots:
    void changerTour();
};

#endif // JEU_H
