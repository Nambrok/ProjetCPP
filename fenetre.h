#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>

class Fenetre : public QWidget
{
    Q_OBJECT
private:
    QPushButton * sortie;
    int LMaxTerrain, CMaxTerrain;
public:
    Fenetre(int L, int C);

signals:

public slots:
};

#endif // FENETRE_H
