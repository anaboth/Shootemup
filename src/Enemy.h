//
// Created by anaboth on 11/4/17.
//

#ifndef SHOOTEMUP_ENEMY_H
#define SHOOTEMUP_ENEMY_H


#include <SDL_rect.h>
#include <vector>
#include "Bullet.h"

class Enemy {
private:
    bool alive;
    SDL_Rect rect;
    float nextShoot;
    float currentShoot;

public:
    Enemy();
    void shoot(std::vector<Bullet>& bulletVector);
    void update(std::vector<Bullet>& bulletVector);
    bool hit(SDL_Rect other);
    bool isAlive() const;
    void setAlive(bool alive);
    const SDL_Rect &getRect() const;
    void setRect(const SDL_Rect &rect);

};


#endif //SHOOTEMUP_ENEMY_H
