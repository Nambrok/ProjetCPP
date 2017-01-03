#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBrush>
#include <QColor>
#include <QLine>
#include <QRect>

class Fenetre : public QGraphicsView
{
    Q_OBJECT
private:
    QPushButton * sortie;
    QGraphicsScene * scene;
    int LMaxTerrain, CMaxTerrain;
public:
    Fenetre(int L, int C);

signals:

public slots:
};

#endif // FENETRE_H
