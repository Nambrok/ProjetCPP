#ifndef VICTOIRE_H
#define VICTOIRE_H


#define J1 0
#define J2 1

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QLabel>
#include <QPalette>
#include <QBrush>
#include <QColor>
#include <QGraphicsProxyWidget>
#include <QPushButton>

class Victoire : public QGraphicsScene
{
public:
    Victoire(int joueurGagnant);
    ~Victoire();
};

#endif // VICTOIRE_H
