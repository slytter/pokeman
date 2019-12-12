//
// Created by Nikolaj on 12/12/2019.
//

#include "Projectile.h"
#include "PhysicsComponent.hpp"
#include "GameObject.hpp"

using namespace glm;
using namespace sre;
using namespace std;

Projectile::Projectile(GameObject *gameObject) : Component(gameObject) {
    phys = gameObject->addComponent<PhysicsComponent>();
}

void Projectile::shoot(glm::vec2 pos, float rotation){
    phys->initCircle(b2_dynamicBody, 0.1, {gameObject->getPosition().x/100, gameObject->getPosition().y/100}, 1);
    phys->body->SetTransform(b2Vec2(pos.x, pos.y), rotation);
    phys->addForce(vec2(10, 0));

}


void Projectile::update(float deltaTime){

}

void Projectile::onCollisionStart(PhysicsComponent *comp) {
    Component::onCollisionStart(comp);
}

void Projectile::onCollisionEnd(PhysicsComponent *comp) {
    Component::onCollisionEnd(comp);
}
