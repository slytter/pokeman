//
// Created by Morten Nobel-Jørgensen on 10/10/2017.
//

#include "SpriteAnimationComponent.hpp"
#include "GameObject.hpp"
#include <memory>

SpriteAnimationComponent::SpriteAnimationComponent(GameObject *gameObject) : Component(gameObject) {
    std::shared_ptr<TrainerController> playerController = gameObject->getComponent<TrainerController>();
    characterPhysics = gameObject->getComponent<PhysicsComponent>();
}

void SpriteAnimationComponent::update(float deltaTime) {
    auto spriteComponent = gameObject->getComponent<SpriteComponent>();
    assert(spriteComponent != nullptr);
    time += deltaTime;

    if (time > animationTime) {
        time = fmod(time, animationTime);
        spriteIndex = (spriteIndex + 1) % sprites.size();
        spriteComponent->setSprite(sprites[spriteIndex]);
    }

    // auto velocity = characterPhysics->getLinearVelocity();
    // bool direction = velocity.x < 0;
    // auto chosenSprite = spriteComponent->getSprite();
    // chosenSprite.setFlip(glm::vec2(direction, 0));
    // spriteComponent->setSprite(chosenSprite);
}

void SpriteAnimationComponent::setSprites(std::vector<sre::Sprite> sprites) {
    this->sprites = sprites;
}

float SpriteAnimationComponent::getAnimationTime() const {
    return animationTime;
}

void SpriteAnimationComponent::setAnimationTime(float animationTime) {
    SpriteAnimationComponent::animationTime = animationTime;
}
