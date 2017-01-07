#ifndef OBUS_H
#define OBUS_H
#include <QPixmap>
#include <QPoint>
#include <random>
#include <QColor>

class Tank
{
private:
    int degats;
    int radius; //point central + rayon de radius
    QColor couleur;
    QPixmap *texture;
    QPoint impact;
public:
    Obus();
    Obus(int type);//degat

#endif // OBUS_H
