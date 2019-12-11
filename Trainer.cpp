//
// Created by Sune Øllgaard Klem on 11/12/2019.
//

#include "Trainer.h"
#include <iostream>

Trainer::Trainer() {



        // Todo implement
};

void Trainer::onKey(SDL_Event &event) {

    if (event.key.keysym.sym == SDLK_w) {
        int temp = event.type == SDL_KEYDOWN;
        std::cout << "w " << temp;
    }
    if (event.key.keysym.sym == SDLK_a) {
        int temp = event.type == SDL_KEYDOWN;
        std::cout << "a " <<  temp;
    }
    if (event.key.keysym.sym == SDLK_d) {
        //dir = rotateY(vec4(side,0),radians(rotation));
        int temp = event.type == SDL_KEYDOWN;
        std::cout << "d " <<  temp;
        //position += dir;
    }
    if (event.key.keysym.sym == SDLK_s) {
        int temp = event.type == SDL_KEYDOWN;
        std::cout << "s " <<  temp;

    }
}


