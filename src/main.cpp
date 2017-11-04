#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

// TODO Finish this
bool hit(int x1, int y1, int x2, int y2){
    if(x1 > x2) return true;
    return false;
}

void shoot(std::vector<Bullet>& bulletVector, SDL_Rect father, int direction){
    Bullet tmp;
    SDL_Rect temp = {father.x + father.h / 2, father.y - tmp.getRect().w, tmp.getRect().w, tmp.getRect().h};
    tmp.setRect(temp);
    tmp.setSpeedY(9);
    tmp.setTimeToDie(10);
    tmp.setDirection(direction);
    bulletVector.push_back(tmp);
}

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* w;
    SDL_Renderer* r;
    bool running = true;
    srand(time(NULL));

    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    Player p;

    int speed = 5;

    for (int i = 0; i < 2; i++){
        Enemy temp;
        temp.setAlive(true);
        SDL_Rect tmp = {rand() % 600, rand() % 100, 50, 50};
        temp.setRect(tmp);
        enemies.push_back(temp);
    }

    w = SDL_CreateWindow("Shootemup", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, NULL);
    r = SDL_CreateRenderer(w, 0, SDL_RENDERER_PRESENTVSYNC);
    const Uint8* keys = SDL_GetKeyboardState(NULL);
    float timeSinceLastShot;

    while(running){

        SDL_PumpEvents();

        timeSinceLastShot += 0.1f;

        if(keys[SDL_SCANCODE_Q]) running = false;

        //if(keys[SDL_SCANCODE_W]) p.setSpeedY(speed);      NO, YOU CAN'T GO UP
        //if(keys[SDL_SCANCODE_S]) p.setSpeedY(-speed);
        if(keys[SDL_SCANCODE_A]) p.setSpeedX(-speed);
        if(keys[SDL_SCANCODE_D]) p.setSpeedX(speed);
        p.update();

        if(keys[SDL_SCANCODE_SPACE] && timeSinceLastShot >= 1) {
            shoot(bullets, p.getRect(), 1);
            timeSinceLastShot = 0;
        }

        SDL_RenderClear(r);

        if(bullets.size() > 0) if(bullets[0].dead()) bullets.erase(bullets.begin());

        SDL_SetRenderDrawColor(r, 0xFF, 0xFF, 0xFF, 0xFF);
        for(int i = 0; i < bullets.size(); i++){
            bullets[i].update();
            SDL_RenderDrawRect(r, &bullets[i].getRect());
        }

        SDL_SetRenderDrawColor(r, 0xFF, 0x00, 0x00, 0xFF);
        for(int i = 0; i < enemies.size(); i++){
            enemies[i].update();
            SDL_RenderDrawRect(r, &enemies[i].getRect());
        }


        SDL_SetRenderDrawColor(r, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderDrawRect(r, &p.getRect());

        SDL_SetRenderDrawColor(r, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderPresent(r);
    }

    SDL_DestroyWindow(w);
    SDL_DestroyRenderer(r);
    SDL_Quit();
    return 0;
}