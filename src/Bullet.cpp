//
// Created by anaboth on 11/3/17.
//

#include "Bullet.h"

float Bullet::getX() const {
    return x;
}

void Bullet::setX(float x) {
    Bullet::x = x;
}

float Bullet::getY() const {
    return y;
}

void Bullet::setY(float y) {
    Bullet::y = y;
}

int Bullet::getW() const {
    return w;
}

void Bullet::setW(int w) {
    Bullet::w = w;
}

int Bullet::getH() const {
    return h;
}

void Bullet::setH(int h) {
    Bullet::h = h;
}

float Bullet::getSpeedY() const {
    return speedY;
}

void Bullet::setSpeedY(float speedY) {
    Bullet::speedY = speedY;
}

void Bullet::update() {
    y -= speedY;
    if(currentTime >= timeToDie) deadV = true;
    currentTime += 0.1f;
}

Bullet::Bullet() {
    w = 5;
    h = 5;
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
