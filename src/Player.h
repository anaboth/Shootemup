//
// Created by anaboth on 11/3/17.
//

#ifndef EDIARARDO_PLAYER_H
#define EDIARARDO_PLAYER_H


class Player {
private:
    float x;
    float y;
    int w;
    int h;
    float speedY;
    float speedX;

public:
    Player();
    void update();
    void draw();
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
    float getSpeedX() const;
    void setSpeedX(float speedX);
};


#endif //EDIARARDO_PLAYER_H
