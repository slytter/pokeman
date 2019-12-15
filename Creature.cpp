#pragma once
#include "GameObject.hpp"
#include "SpriteComponent.hpp"
#include "PhysicsComponent.hpp"
#include "Creature.h"
#include "iostream"
#include "PokemanGame.hpp"
#include "TrainerController.hpp"
#include <string>
#include <stdio.h>


using namespace std;
using namespace glm;


Creature::Creature(GameObject *gameObject) : Component(gameObject) {

    b2Vec2 pos = gameObject->getComponent<PhysicsComponent>()->body->GetPosition();
    gameObject->getComponent<PhysicsComponent>()->body->SetTransform(pos, 45.0f);

    creaturePhys = gameObject->getComponent<PhysicsComponent>();
    GUISize = glm::vec2(100,50);

    idPointer = &enemyId;
}

void Creature::onCollisionStart(PhysicsComponent *comp) {
    if(comp->getGameObject()->name == "Player") {
        player->getComponent<TrainerController>()->health -= cDmg;
    } else if (comp->getGameObject()->name == "Projectile") {
        cHealth -= player->getComponent<TrainerController>()->pDmg;
    }
}

void Creature::update(float deltaTime) {
    if (cHealth <= 0) {
        gameObject->removeMe = true;
    }
    dirToPlayer = player->getPosition() - gameObject->getPosition();
    creaturePhys->addForce(glm::normalize(dirToPlayer) * (cSpeed*deltaTime));
    creaturePhys->body->SetLinearDamping((10));
}

void Creature::onGui() {
    if (PokemanGame::instance->getGameState() == GameState::Running) {
        vec2 isoCamView = cam->getCameraPos(vec3(gameObject->getPosition(), 1));
        ImGui::SetNextWindowBgAlpha(0.0f);
        ImGui::SetNextWindowPos(ImVec2(isoCamView.x - GUISize.x/2, isoCamView.y - GUISize.y ),
                                ImGuiSetCond_Always);
        ImGui::Begin(idPointer, nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
        ImGui::ProgressBar(cHealth / 100, {100, 3});
        ImGui::End();
    }
}

void Creature::setCamera(std::shared_ptr<CameraController> _cam) {
    this->cam = _cam;
}

void Creature::getEnemyCount (int _count) {
    enemyId = _count;

}

void Creature::getPlayer(std::shared_ptr<GameObject> _player) {
    player = _player;
}

