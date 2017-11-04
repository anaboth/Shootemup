//
// Created by anaboth on 11/3/17.
//

#ifndef SHOOTEMUP_BULLET_H
#define SHOOTEMUP_BULLET_H


class Bullet {
private:
    float x;
    float y;
    int w;
    int h;
    float speedY;
    float timeToDie;
    float currentTime;
    bool deadV;

public:
    Bullet();
    bool dead();
    void update();
    float getTimeToDie() const;
    void setTimeToDie(float timeToDie);
    float getX() const;
    void setX(float x);
    float getY() const;
    void setY(float y);
    int getW() const;
    void setW(int w);
    int getH() const;
    void setH(int h);
    float getSpeedY() const;
    void setSpeedY(float speedY);
};


#endif //SHOOTEMUP_BULLET_H
