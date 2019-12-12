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
#include "SpriteAnimationComponent.hpp"

using namespace glm;
using namespace sre;
using namespace std;

TrainerController::TrainerController(GameObject *gameObject) : Component(gameObject) {
    // initiate bird physics
    b2Vec2 pos = gameObject->getComponent<PhysicsComponent>()->body->GetPosition();
    gameObject->getComponent<PhysicsComponent>()->body->SetTransform(pos, 45.0f);
    gameObject->getComponent<PhysicsComponent>()->body->SetFixedRotation(true);
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

    if(comp->getGameObject()->name == "Coin") {
        comp->getGameObject()->removeMe = true;
    } else {
        //PokemanGame::instance->setGameState(GameState::GameOver);
    }
    std::cout << "bird collided with something: " << comp->getGameObject()->name << std::endl;
}

void TrainerController::update(float deltaTime) {
    //std::cout<< "yas";
    if (fwd) {
        updatePos (vec3(-1,1,0));
    }
    if (bwd) {
        updatePos (vec3(1,-1,0));
    }
    if (left) {
        updatePos (vec3(-1,-1,0));
    }
    if (right) {
        updatePos (vec3(1,1,0));
    }
    std::cout << gameObject->getRotation()<< std::endl;

}

void TrainerController::onCollisionEnd(PhysicsComponent *comp) {

}

void TrainerController::updatePos(glm::vec3 dir) {
    trainerPhys = gameObject->getComponent<PhysicsComponent>(); // (vec3(gameObject->getPosition(),0) + dir);
    trainerPhys->addForce(vec2(dir.x, dir.y) * playerSpeed);
    trainerPhys->body->SetLinearDamping((10));
    std::cout << gameObject->getPosition().x << " "  << gameObject->getPosition().y;
    // trainerPhysx->
}


