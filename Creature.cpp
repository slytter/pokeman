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
    gameObject->getComponent<PhysicsComponent>()->body->SetTransform(pos, 45.0f); // Sets the initial state of the creature, in regards the position and rotation.

    creaturePhys = gameObject->getComponent<PhysicsComponent>();
    GUISize = glm::vec2(100,50);
    idPointer = &enemyId;
}

void Creature::onCollisionStart(PhysicsComponent *comp) { // Handles the response to a detected collision.
    if(comp->getGameObject()->name == "Player") {
        player->getComponent<TrainerController>()->health -= cDmg; // Player takes dmg.
    } else if (comp->getGameObject()->name == "Projectile") {
        cHealth -= player->getComponent<TrainerController>()->pDmg; // Creature takes dmg.
    }
}

void Creature::update(float deltaTime) {
    if (cHealth <= 0) {
        // This tag tells update (in Pokeman.cpp) that the given Gameobject should be destroyed.
        // By handling the clean up in one place (main), the system is safe from accidently calling destroyed objects.
        gameObject->removeMe = true;
    }
    dirToPlayer = player->getPosition() - gameObject->getPosition(); // Gets the direction to the player.
    creaturePhys->addForce(glm::normalize(dirToPlayer) * (cSpeed*deltaTime)); // Apply movement to the object via. its PhysicsComponent.
    creaturePhys->body->SetLinearDamping((10)); // Dampens the current velocity of the creature.
}

void Creature::onGui() {
    if (PokemanGame::instance->getGameState() == GameState::Running) { // insures that the game is running
        vec2 isoCamView = cam->getCameraPos(vec3(gameObject->getPosition(), 1)); // Gets the view coordinates of the camera, in order to correctly "track" and map the GUI health bar.

        ImGui::SetNextWindowBgAlpha(0.0f); // Initialize GUI element
        ImGui::SetNextWindowPos(ImVec2(isoCamView.x - GUISize.x/2, isoCamView.y - GUISize.y ),ImGuiSetCond_Always);
        ImGui::Begin(idPointer, nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize); // The idPointer insures that the spawned GUI element is unique to the given creature.
        ImGui::ProgressBar(cHealth / 100, {100, 3});
        ImGui::End();
    }
}

void Creature::setCamera(std::shared_ptr<CameraController> _cam) {
    this->cam = _cam; // Gets the camera reference.
}

void Creature::getEnemyCount (int _count) {
    enemyId = _count; // Assigns the enemyId in respect to the number og enemies that has been spawned.

}

void Creature::getPlayer(std::shared_ptr<GameObject> _player) {
    player = _player;
}

