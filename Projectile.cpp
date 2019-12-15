#include <iostream>
#include <Box2D/Box2D.h>
#include "Projectile.h"
#include "PhysicsComponent.hpp"
#include "GameObject.hpp"
#include "TrainerController.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/vector_angle.hpp"
#include "SoundSource.h"

using namespace glm;
using namespace sre;
using namespace std;

Projectile::Projectile(GameObject *gameObject) : Component(gameObject) {
    phys = gameObject->addComponent<PhysicsComponent>();
}

void Projectile::shoot(){
    // Get players current direction:
    vec2 currentDirection = playerReference->getComponent<TrainerController>()->currentDirection;
    // And player position
    b2Vec2 currentPosition = playerReference->getComponent<PhysicsComponent>()->body->GetPosition();
    // creating an offset with the direction, such that the bullet will not spawn on top of the player.
    b2Vec2 spawnPosition = {currentPosition.x + (currentDirection.x * 0.1f), currentPosition.y + (currentDirection.y * 0.1f) };
    // Setting circle collider on projectiles physics:
    phys->initCircle(b2_dynamicBody, 0.1, {currentDirection.x/100, currentDirection.y/100}, 1);
    // calculating rotation with ~45 deg offset to make up for isometric view.
    float rotation = glm::degrees(glm::orientedAngle(vec2(1, 1), currentDirection) + 45.0f);
    //Finally placing the Projectile with box2d and addingForce in the player direction:
    phys->body->SetTransform(b2Vec2(spawnPosition.x, spawnPosition.y), rotation);
    phys->addForce(currentDirection * 10.0f);
}


void Projectile::update(float deltaTime){

}

void Projectile::onCollisionStart(PhysicsComponent *comp) {
    if(comp->getGameObject()->name != "Player"){
        gameObject->removeMe = true;
    }
    Component::onCollisionStart(comp);
}

void Projectile::onCollisionEnd(PhysicsComponent *comp) {
    Component::onCollisionEnd(comp);
}
