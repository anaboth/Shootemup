#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* w;
    SDL_Renderer* r;
    bool running = true;
    srand(time(NULL));

    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    Player player;

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
    float timeSinceLastShot = 0;
    float enemyShoot = 0;

    while(running){

        SDL_PumpEvents();

        timeSinceLastShot += 0.1f;
        enemyShoot += 0.1f;

        if(keys[SDL_SCANCODE_Q]) running = false;

        //if(keys[SDL_SCANCODE_W]) player.setSpeedY(speed);      NO, YOU CAN'T GO UP
        //if(keys[SDL_SCANCODE_S]) player.setSpeedY(-speed);
        if(keys[SDL_SCANCODE_A]) player.setSpeedX(-speed);
        if(keys[SDL_SCANCODE_D]) player.setSpeedX(speed);
        player.update();

        if(keys[SDL_SCANCODE_SPACE] && timeSinceLastShot >= 1) {
            player.shoot(bullets);
            timeSinceLastShot = 0;
        }

        for(int i = 0; i < bullets.size(); i++) bullets[i].update();
        for(int i = 0; i < enemies.size(); i++) enemies[i].update(bullets);

        SDL_RenderClear(r);

        if(bullets.size() > 0) if(bullets[0].dead()) bullets.erase(bullets.begin());

        SDL_SetRenderDrawColor(r, 0xFF, 0xFF, 0xFF, 0xFF);
        for(int i = 0; i < bullets.size(); i++) SDL_RenderDrawRect(r, &bullets[i].getRect());

        SDL_SetRenderDrawColor(r, 0xFF, 0x00, 0x00, 0xFF);
        for(int i = 0; i < enemies.size(); i++) SDL_RenderDrawRect(r, &enemies[i].getRect());

        SDL_SetRenderDrawColor(r, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderDrawRect(r, &player.getRect());

        SDL_SetRenderDrawColor(r, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderPresent(r);
    }

    SDL_DestroyWindow(w);
    SDL_DestroyRenderer(r);
    SDL_Quit();
    return 0;
}