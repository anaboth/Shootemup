#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "Player.h"
#include "Bullet.h"


int main() {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* w;
    SDL_Renderer* r;
    bool running = true;

    std::vector<Bullet> a;
    Player p;

    a.size();

    int speed = 5;

    w = SDL_CreateWindow("Ediarardo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, NULL);
    r = SDL_CreateRenderer(w, 0, SDL_RENDERER_PRESENTVSYNC);
    const Uint8* keys = SDL_GetKeyboardState(NULL);
    float timeSinceLastShot;

    while(running){

        SDL_PumpEvents();

        timeSinceLastShot += 0.1f;

        if(keys[SDL_SCANCODE_Q]) running = false;

        //if(keys[SDL_SCANCODE_W]) p.setSpeedY(speed);
        //if(keys[SDL_SCANCODE_S]) p.setSpeedY(-speed);
        if(keys[SDL_SCANCODE_A]) p.setSpeedX(-speed);
        if(keys[SDL_SCANCODE_D]) p.setSpeedX(speed);
        p.update();

        if(keys[SDL_SCANCODE_SPACE] && timeSinceLastShot > 1) {
            Bullet tmp;
            tmp.setX(p.getX() + p.getH() / 2);
            tmp.setY(p.getY() - tmp.getW());
            tmp.setSpeedY(9);
            tmp.setTimeToDie(10);
            a.push_back(tmp);
            timeSinceLastShot = 0;
        }

        SDL_RenderClear(r);

        if(a.size() > 0) if(a[0].dead()) a.erase(a.begin());

        SDL_SetRenderDrawColor(r, 0xFF, 0xFF, 0xFF, 0xFF);

        for(int i = 0; i < a.size(); i++){
            std::cout << i << std::endl;
            a[i].update();
            SDL_Rect temp;
            temp.h = a[i].getH();
            temp.w = a[i].getW();
            temp.x = a[i].getX();
            temp.y = a[i].getY();
            SDL_RenderDrawRect(r, &temp);
        }

        SDL_SetRenderDrawColor(r, 0x00, 0x00, 0xFF, 0xFF);

        SDL_Rect temp;
        temp.h = p.getH();
        temp.w = p.getW();
        temp.x = p.getX();
        temp.y = p.getY();

        SDL_RenderDrawRect(r, &temp);
        SDL_SetRenderDrawColor(r, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderPresent(r);
    }

    SDL_DestroyWindow(w);
    SDL_DestroyRenderer(r);
    SDL_Quit();
    return 0;
}