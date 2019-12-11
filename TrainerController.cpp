//
// Created by Morten Nobel-Jørgensen on 19/10/2017.
//

#include <SDL_events.h>
#include <iostream>
#include "TrainerController.hpp"
#include "GameObject.hpp"
#include "SpriteComponent.hpp"
#include "PhysicsComponent.hpp"
#include "PokemanGame.hpp"
#include "SpriteComponent.hpp"

using namespace glm;

TrainerController::TrainerController(GameObject *gameObject) : Component(gameObject) {
    // initiate bird physics
    phys = this->gameObject->getComponent<PhysicsComponent>();
    phys->setLinearVelocity(vec2(1.2, 0));
}

bool TrainerController::onKey(SDL_Event &event) {

    if (event.key.keysym.sym == SDLK_w) {
        fwd = event.type == SDL_KEYDOWN;
    }
    if  (event.key.keysym.sym == SDLK_a) {
        left = event.type == SDL_KEYDOWN;
    }
    if  (event.key.keysym.sym == SDLK_d) {
        right = event.type == SDL_KEYDOWN;
    }
    if  (event.key.keysym.sym == SDLK_s) {
        bwd = event.type == SDL_KEYDOWN;
    }

    return false;
}

void TrainerController::onCollisionStart(PhysicsComponent *comp) {

    if(comp->getGameObject()->name == "Coin"){
        comp->getGameObject()->removeMe = true;
    } else {
        PokemanGame::instance->setGameState(GameState::GameOver);
    }
    std::cout << "bird collided with something: " << comp->getGameObject()->name << std::endl;
}

void TrainerController::onCollisionEnd(PhysicsComponent *comp) {

}


