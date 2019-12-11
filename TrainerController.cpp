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
}

bool TrainerController::onKey(SDL_Event &event) {

    if (event.key.keysym.sym == SDLK_UP) {
        fwd = event.type == SDL_KEYDOWN;
    }
    if  (event.key.keysym.sym == SDLK_LEFT) {
        left = event.type == SDL_KEYDOWN;
    }
    if  (event.key.keysym.sym == SDLK_RIGHT) {
        right = event.type == SDL_KEYDOWN;
    }
    if  (event.key.keysym.sym == SDLK_DOWN) {
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

void TrainerController::update(float deltaTime) {
    //std::cout<< "yas";

    if (fwd) {
        updatePos (vec3(0,1,0));
    }

    if (bwd) {
        updatePos (vec3(0,-1,0));
    }

    if (left) {
        updatePos (vec3(-1,0,0));
    }

    if (right) {
        updatePos (vec3(1,0,0));
    }


}

void TrainerController::onCollisionEnd(PhysicsComponent *comp) {

}

void TrainerController::updatePos(glm::vec3 dir) {
    std::shared_ptr<PhysicsComponent> trainerPhysx = gameObject->getComponent<PhysicsComponent>(); // (vec3(gameObject->getPosition(),0) + dir);
    trainerPhysx->addForce(vec2(dir.x, dir.y) * playerSpeed);
    trainerPhysx->body->SetLinearDamping((10));
    // trainerPhysx->
}


