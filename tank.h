#ifndef TANK_H
#define TANK_H


class Tank : public Obstacle
{
private:
    int vie;
    int canonH; //Angle du canon horizontalement de 0 à 360°
    int angleDeTir; //0 à 90°
    int capacité; //capacité de déplacement restant au tank initialisé à L/10
    int nbObus2; //initialisé à 10
    int nbObus3; //initialisé à 5
    bool alive;
public:
    Tank();
    bool isAlive();
    bool useObus1();
    bool useObus2();
    bool useObus3();
    int getNbObus2();
    int getNbObus3();

};

#endif // TANK_H
