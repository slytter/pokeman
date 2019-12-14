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
#include "imgui.h"
#include "CameraController.hpp"

using namespace glm;
using namespace sre;
using namespace std;

TrainerController::TrainerController(GameObject *gameObject) : Component(gameObject) {
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
    if (comp->getGameObject()->name == "creature") {
        std::cout << "bang";
        PokemanGame::instance->damageSound.play();
        trainerPhys = gameObject->getComponent<PhysicsComponent>(); // (vec3(gameObject->getPosition(),0) + dir);
        trainerPhys->addImpulse(glm::normalize(-currentDirection) /5.f);
    }
}

void TrainerController::update(float deltaTime) {
    vec2 collectedDirection = {0, 0};
    if (fwd) {
        collectedDirection += vec2(-1, 1);
    }
    if (bwd) {
        collectedDirection += (vec2(1,-1));
    }
    if (left) {
        collectedDirection += (vec2(-1,-1));
    }
    if (right) {
        collectedDirection += (vec2(1,1));
    }
    if(fwd || bwd || left || right){
        updatePos(collectedDirection);
    }

    if (health <= 0) {
        gameObject->removeMe = true;
        PokemanGame::instance->setGameState(GameState::GameOver);
    }



}

void TrainerController::onCollisionEnd(PhysicsComponent *comp) {

}

void TrainerController::updatePos(glm::vec2 dir) {
    currentDirection = glm::vec2(dir.x, dir.y);
    trainerPhys = gameObject->getComponent<PhysicsComponent>(); // (vec3(gameObject->getPosition(),0) + dir);
    trainerPhys->addForce(vec2(dir.x, dir.y) * playerSpeed);
    trainerPhys->body->SetLinearDamping((10));
    //savedPos = glm::vec2(trainerPhys->gameObject->getPosition());

    //std::cout << gameObject->getPosition().x << " "  << gameObject->getPosition().y << "\n";
    // trainerPhysx->
}

void TrainerController::onGui() {
    trainerPhys = gameObject->getComponent<PhysicsComponent>();
    ImGui::SetNextWindowPos(ImVec2(cam->getCameraPos().x, cam->getCameraPos().y), ImGuiSetCond_Always);
    ImGui::SetNextWindowSize(ImVec2(100, 30), ImGuiSetCond_Always);
    ImGui::Begin("", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
    ImGui::ProgressBar(0.5f, {-1, 0});
    ImGui::End();
}

void TrainerController::setCamera(std::shared_ptr<CameraController> _cam) {
    this->cam = _cam;
}


