#ifndef TANK_H
#define TANK_H
#define NBOBUS2 10
#define NBOBUS3 5

class Tank
{
private:
    int canonH; //Angle du canon horizontalement de 0 à 360°
    int angleDeTir; //0 à 90°
    int capacite; //capacité de déplacement restant au tank initialisé à L/10
    int nbObus2 = NBOBUS2;
    int nbObus3 = NBOBUS3;
    bool alive;
    int addL;
    int addC;
public:
    Tank();
    bool isAlive();
    bool useObus1();
    bool useObus2();
    bool useObus3();
    int getNbObus2() const;
    int getNbObus3() const;

    int getAddL() const;
    void setAddL(int value);
    int getAddC() const;
    void setAddC(int value);
};

#endif // TANK_H
