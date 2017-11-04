#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <cstdlib>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

void createEnemy(std::vector<Enemy>& enemies){
    bool ready;
    int x;
    int y;
    SDL_Rect tmp;
    do {
        ready = true;
        x = rand() % 600;
        y = rand() % 100;
        tmp = {x, y, 50, 50};
        for(int i = 0; i < enemies.size(); i++){
            if(enemies[i].hit(tmp)){
                ready = false;
            }
        }
    } while (!ready);
    Enemy temp;
    temp.setAlive(true);
    temp.setRect(tmp);
    enemies.push_back(temp);
}

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    srand(time(NULL));

    TTF_Init();

    SDL_Window* w;
    SDL_Renderer* r;
    SDL_Surface* scoreSurface;
    SDL_Texture* scoreTexture;
    SDL_Rect scoreRect = {600, 550, 200, 50};
    TTF_Font* font = TTF_OpenFont("Hack.ttf", 14);
    if(!font) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        exit(2);
    }
    bool running = true;
    const Uint8* keys = SDL_GetKeyboardState(NULL);
    float timeSinceLastShot = 0;
    float enemyShoot = 0;
    int score = 0;
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    Player player;

    int speed = 5;

    Enemy temp;
    temp.setAlive(true);
    SDL_Rect tmp = {rand() % 750, rand() % 100, 50, 50};
    temp.setRect(tmp);
    enemies.push_back(temp);

    w = SDL_CreateWindow("Shootemup", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, NULL);
    r = SDL_CreateRenderer(w, 0, SDL_RENDERER_PRESENTVSYNC);


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

        for(int i = 0; i < bullets.size(); i++) {
            bullets[i].update();
            if(bullets[i].hit(player.getRect())){
                std::cout << "Died\n";
                running = false;
                bullets.erase(bullets.begin() + i);
                continue;
            }
            for(int j = 0; j < enemies.size(); j++){
                if(bullets[i].hit(enemies[j].getRect())){
                    enemies[j].setAlive(false);
                    bullets.erase(bullets.begin() + i);
                    score += 10;
                }
            }
        }

        if(enemies.size() < 2) createEnemy(enemies);

        for(int i = 0; i < enemies.size(); i++){
            if(!enemies[i].isAlive()) {
                enemies.erase(enemies.begin() + i);
                continue;
            }
            enemies[i].update(bullets);
        }

        SDL_RenderClear(r);

        if(bullets.size() > 0) if(bullets[0].dead()) bullets.erase(bullets.begin());

        SDL_SetRenderDrawColor(r, 0xFF, 0xFF, 0xFF, 0xFF);
        for(int i = 0; i < bullets.size(); i++) SDL_RenderDrawRect(r, &bullets[i].getRect());

        SDL_SetRenderDrawColor(r, 0xFF, 0x00, 0x00, 0xFF);
        for(int i = 0; i < enemies.size(); i++) SDL_RenderDrawRect(r, &enemies[i].getRect());

        SDL_SetRenderDrawColor(r, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderDrawRect(r, &player.getRect());

        std::string a = "Score: " + std::to_string(score);
        scoreSurface = TTF_RenderText_Solid(font, a.c_str(), {0xFF, 0xFF, 0xFF, 0xFF});
        scoreTexture = SDL_CreateTextureFromSurface(r, scoreSurface);
        SDL_FreeSurface(scoreSurface);
        SDL_RenderCopy(r, scoreTexture, NULL, &scoreRect);

        SDL_SetRenderDrawColor(r, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderPresent(r);
    }

    std::cout << "Score: " << score << std::endl;

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyWindow(w);
    SDL_DestroyRenderer(r);
    SDL_Quit();
    return 0;
}