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
#include "terrain.h"
#include "obstacle.h"

#define NMAX 25

class Fenetre : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene * scene;
    int LMaxTerrain, CMaxTerrain;
public:
    Fenetre(int L, int C);
    void chargerTerrain(Terrain ter);

signals:

public slots:
};

#endif // FENETRE_H
