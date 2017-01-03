#ifndef OBSTACLE_H
#define OBSTACLE_H


class Obstacle{
private:
    int resistance;
    int resistanceOriginal;
    void setResistanceOriginal(int resOri);
public:
    Obstacle();
    Obstacle(int resOri);
    void setResistance(int newRes);
    int getResistance();
    int getResistanceOriginal();
};

#endif // OBSTACLE_H
