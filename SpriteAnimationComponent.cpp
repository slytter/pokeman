//
// Created by Morten Nobel-Jørgensen on 10/10/2017.
//

#include "SpriteAnimationComponent.hpp"
#include "GameObject.hpp"
#include <memory>


SpriteAnimationComponent::SpriteAnimationComponent(GameObject *gameObject) : Component(gameObject) {
    std::shared_ptr<TrainerController> playerController = gameObject->getComponent<TrainerController>();
}

void SpriteAnimationComponent::update(float deltaTime) {
    auto spriteComponent = gameObject->getComponent<SpriteComponent>();
    assert(spriteComponent != nullptr);

    if(characterPhysics == nullptr){
        characterPhysics = gameObject->getComponent<PhysicsComponent>();
    }
    auto velocity = characterPhysics->getLinearVelocity();
    if((int)velocity.x != 0 || (int)velocity.y != 0){
        time += deltaTime * (glm::abs(velocity.x) + glm::abs(velocity.y));
    }

    if (time > animationTime) {
        time = fmod(time, animationTime);
        spriteIndex = (spriteIndex + 1) % sprites.size();
        spriteComponent->setSprite(sprites[spriteIndex]);
    }



    bool directionX = velocity.x < 0 || velocity.y < 0;
    auto chosenSprite = spriteComponent->getSprite();
    chosenSprite.setRotation(-45.0f);
    chosenSprite.setFlip(glm::vec2(directionX, false));
    chosenSprite.setScale(glm::vec2(.8, 1.2f));
    spriteComponent->setSprite(chosenSprite);
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
