#include "victoire.h"

Victoire::Victoire(int joueurGagnant) : QGraphicsScene()
{
    QLabel *j = new QLabel();
    if(joueurGagnant == J1){
        j->setText("Bravo au joueur bleu pour sa victoire !");
        j->setPalette(QPalette(Qt::blue));
        setBackgroundBrush(QBrush(Qt::blue));
    }
    else{
        j->setText("Bravo au joueur rouge pour sa victoire !");
        j->setPalette(QPalette(Qt::red));
        setBackgroundBrush(QBrush(Qt::red));
    }

    addWidget(j);

}

Victoire::~Victoire(){

}
