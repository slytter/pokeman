//
// Created by Sune Øllgaard Klem on 12/12/2019.
//
#pragma once
#include "GameObject.hpp"
#include "SpriteComponent.hpp"
#include "PhysicsComponent.hpp"
#include "Creature.h"
#include "iostream"

using namespace std;

Creature::Creature(GameObject *gameObject) : Component(gameObject) {

    b2Vec2 pos = gameObject->getComponent<PhysicsComponent>()->body->GetPosition();
    gameObject->getComponent<PhysicsComponent>()->body->SetTransform(pos, 45.0f);

    creaturePhys = gameObject->getComponent<PhysicsComponent>();

}

void Creature::onCollisionStart(PhysicsComponent *comp) {
    if(comp->getGameObject()->name == "player") {
        cout<< "you dead boi!";
    }
}

void Creature::update(float deltaTime) {
    dirToPlayer = player->getPosition() - gameObject->getPosition();
    creaturePhys->addForce(glm::normalize(dirToPlayer) * (cSpeed*deltaTime));
    creaturePhys->body->SetLinearDamping((10));

}

void Creature::getPlayer(std::shared_ptr<GameObject> _player) {
    player = _player;


}
