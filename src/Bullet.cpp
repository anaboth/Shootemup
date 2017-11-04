//
// Created by anaboth on 11/3/17.
//

#include "Bullet.h"

float Bullet::getSpeedY() const {
    return speedY;
}

void Bullet::setSpeedY(float speedY) {
    Bullet::speedY = speedY;
}

void Bullet::update() {
    rect.y -= speedY * direction;
    if(currentTime >= timeToDie) deadV = true;
    currentTime += 0.1f;
}

Bullet::Bullet() {
    rect.w = 5;
    rect.h = 5;
    deadV = false;
}

bool Bullet::dead(){
    return deadV;
}

float Bullet::getTimeToDie() const {
    return timeToDie;
}

void Bullet::setTimeToDie(float timeToDie) {
    Bullet::timeToDie = timeToDie;
}

void Bullet::setDirection(int direction) {
    Bullet::direction = direction;
}

const SDL_Rect &Bullet::getRect() const {
    return rect;
}

void Bullet::setRect(const SDL_Rect &rect) {
    Bullet::rect = rect;
}
