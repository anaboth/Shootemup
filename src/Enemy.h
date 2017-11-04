//
// Created by anaboth on 11/4/17.
//

#ifndef SHOOTEMUP_ENEMY_H
#define SHOOTEMUP_ENEMY_H


#include <SDL_rect.h>

class Enemy {
private:
    bool alive;
    SDL_Rect rect;

public:
    void update();
    bool isAlive() const;
    void setAlive(bool alive);
    const SDL_Rect &getRect() const;
    void setRect(const SDL_Rect &rect);

};


#endif //SHOOTEMUP_ENEMY_H
