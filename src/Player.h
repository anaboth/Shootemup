//
// Created by anaboth on 11/3/17.
//

#ifndef EDIARARDO_PLAYER_H
#define EDIARARDO_PLAYER_H


#include <SDL_rect.h>

class Player {
private:
    float speedY;
    float speedX;
    SDL_Rect rect;

public:
    Player();
    void update();
    void draw();
    float getSpeedY() const;
    void setSpeedY(float speedY);
    float getSpeedX() const;
    void setSpeedX(float speedX);
    const SDL_Rect &getRect() const;
    void setRect(const SDL_Rect &rect);
};


#endif //EDIARARDO_PLAYER_H
