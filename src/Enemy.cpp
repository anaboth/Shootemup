//
// Created by anaboth on 11/4/17.
//

#include "Enemy.h"

bool Enemy::isAlive() const {
    return alive;
}

void Enemy::setAlive(bool alive) {
    Enemy::alive = alive;
}

void Enemy::update(std::vector<Bullet>& bulletVector) {
    if(currentShoot >= nextShoot){
        shoot(bulletVector);
        nextShoot = rand() % 4 + 2;
        currentShoot = 0;
    }
    currentShoot += 0.1f;
}

const SDL_Rect &Enemy::getRect() const {
    return rect;
}

void Enemy::setRect(const SDL_Rect &rect) {
    Enemy::rect = rect;
}

Enemy::Enemy() {
    alive = true;
    currentShoot = 0;
    nextShoot = rand() % 4;
}

void Enemy::shoot(std::vector<Bullet> &bulletVector) {
    Bullet tmp;
    SDL_Rect temp = {rect.x + rect.h / 2,
                     rect.y + rect.w + tmp.getRect().w,
                     tmp.getRect().w,
                     tmp.getRect().h};
    tmp.setRect(temp);
    tmp.setSpeedY(9);
    tmp.setTimeToDie(10);
    tmp.setDirection(-1);
    bulletVector.push_back(tmp);
}

bool Enemy::hit(SDL_Rect other) {
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
