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


#include "terrain.h"
#include "obstacle.h"
#include "arbre.h"
#include "crevasse.h"
#include "eau.h"
#include "roche.h"
#include "tank.h"
#include "terrainnormal.h"

class Fenetre : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene * scene;
    int LMaxTerrain, CMaxTerrain;
    int orientation;
public:
    Fenetre(int L, int C);
    void chargerTerrain(Terrain ter);

    int getOrientation() const;
    void setOrientation(int value);

signals:

public slots:
};

#endif // FENETRE_H
