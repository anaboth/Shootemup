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

void Enemy::update() {

}

const SDL_Rect &Enemy::getRect() const {
    return rect;
}

void Enemy::setRect(const SDL_Rect &rect) {
    Enemy::rect = rect;
}
