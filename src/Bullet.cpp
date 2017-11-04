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

bool Bullet::hit(SDL_Rect other) {
    if(rect.x + rect.w > other.x && rect.x + rect.w < other.x + other.h &&
            rect.y + rect.h > other.y && rect.y + rect.h < other.y + other.h)
        return true;

    if(rect.x + rect.w > other.x && rect.x + rect.w < other.x + other.h &&
            rect.y > other.y && rect.y < other.y + other.h)
        return true;

    if(rect.x > other.x && rect.x < other.x + other.h &&
            rect.y + rect.h > other.y && rect.y + rect.h < other.y + other.h)
        return true;

    if(rect.x > other.x && rect.x < other.x + other.w &&
            rect.y > other.y && rect.y < other.y + other.h)
        return true;

    return false;
}
