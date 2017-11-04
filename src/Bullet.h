//
// Created by anaboth on 11/3/17.
//

#ifndef SHOOTEMUP_BULLET_H
#define SHOOTEMUP_BULLET_H


#include <SDL_rect.h>

class Bullet {
private:
    SDL_Rect rect;
    int direction;
    float speedY;
    float timeToDie;
    bool deadV;
    float currentTime;

public:
    Bullet();
    bool hit(SDL_Rect other);
    bool dead();
    void update();
    float getTimeToDie() const;
    void setTimeToDie(float timeToDie);
    float getSpeedY() const;
    void setSpeedY(float speedY);
    const SDL_Rect &getRect() const;
    void setRect(const SDL_Rect &rect);
    void setDirection(int direction);
};


#endif //SHOOTEMUP_BULLET_H
