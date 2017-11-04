//
// Created by anaboth on 11/3/17.
//

#include "Player.h"

float Player::getX() const {
    return x;
}

void Player::setX(float x) {
    Player::x = x;
}

float Player::getY() const {
    return y;
}

void Player::setY(float y) {
    Player::y = y;
}

int Player::getW() const {
    return w;
}

void Player::setW(int w) {
    Player::w = w;
}

int Player::getH() const {
    return h;
}

void Player::setH(int h) {
    Player::h = h;
}

Player::Player() {
    x = 350;
    y = 550;
    w = 50;
    h = 50;

}

void Player::update() {
    if(x > 0 && x < 750) x += speedX; else if (x >= 750) x -= 1; else x += 1;
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
