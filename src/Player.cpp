//
// Created by anaboth on 11/3/17.
//

#include "Player.h"

Player::Player() {
    rect.x = 350;
    rect.y = 550;
    rect.w = 50;
    rect.h = 50;

}

void Player::update() {
    if(rect.x > 0 && rect.x < 750) rect.x += speedX; else if (rect.x >= 750) rect.x -= 1; else rect.x += 1;
    speedX = 0;
    //if(y > 0 && y < 600) y -= speedY;
}

void Player::draw() {

}

float Player::getSpeedY() const {
    return speedY;
}

void Player::setSpeedY(float speedY) {
    Player::speedY = speedY;
}

float Player::getSpeedX() const {
    return speedX;
}

void Player::setSpeedX(float speedX) {
    Player::speedX = speedX;
}

const SDL_Rect &Player::getRect() const {
    return rect;
}

void Player::setRect(const SDL_Rect &rect) {
    Player::rect = rect;
}
