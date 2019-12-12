//
// Created by Nikolaj on 12/12/2019.
//

#include "Projectile.h"
#include "PhysicsComponent.hpp"
#include "GameObject.hpp"
#include "TrainerController.hpp"
using namespace glm;
using namespace sre;
using namespace std;

Projectile::Projectile(GameObject *gameObject) : Component(gameObject) {
    phys = gameObject->addComponent<PhysicsComponent>();
}

void Projectile::shoot(glm::vec2 pos, float rotation){
    vec2 currentDirection = playerReference->getComponent<TrainerController>()->currentDirection;
    auto body = playerReference->getComponent<PhysicsComponent>()->body;
    b2Vec2 currentPosition = body->GetPosition();
    b2Vec2 spawnPosition = {currentPosition.x + (currentDirection.x * 0.1f), currentPosition.y + (currentDirection.y * 0.1f) };
    phys->initCircle(b2_dynamicBody, 0.1, {currentPosition.x/100, currentPosition.y/100}, 1);
    phys->body->SetTransform(b2Vec2(spawnPosition.x, spawnPosition.y), 0);
    phys->addForce(currentDirection * 5.0f);
}


void Projectile::update(float deltaTime){

}

void Projectile::onCollisionStart(PhysicsComponent *comp) {
    Component::onCollisionStart(comp);
}

void Projectile::onCollisionEnd(PhysicsComponent *comp) {
    Component::onCollisionEnd(comp);
}
