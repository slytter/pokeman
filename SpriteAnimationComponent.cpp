//
// Created by Morten Nobel-Jørgensen on 10/10/2017.
//

#include "SpriteAnimationComponent.hpp"
#include "GameObject.hpp"
#include <memory>
#include "sre/RenderPass.hpp"
#include <sre/Inspector.hpp>

using namespace sre;
using namespace std;
using namespace glm;

SpriteAnimationComponent::SpriteAnimationComponent(GameObject *gameObject) : Component(gameObject) {
    std::shared_ptr<TrainerController> playerController = gameObject->getComponent<TrainerController>();
}

void SpriteAnimationComponent::update(float deltaTime) {
    auto spriteComponent = gameObject->getComponent<SpriteComponent>();
    assert(spriteComponent != nullptr);

    if(characterPhysics == nullptr){
        characterPhysics = gameObject->getComponent<PhysicsComponent>();
    }
    if(playerController == nullptr){
        playerController = gameObject->getComponent<TrainerController>();
    }
    auto velocity = characterPhysics->getLinearVelocity();
    if((int)velocity.x != 0 || (int)velocity.y != 0){
        time += deltaTime * (abs(velocity.x) + abs(velocity.y));
    }

    if (time > animationTime) {
        time = fmod(time, animationTime);
        if(playerController->left || playerController->right){
            spriteIndex = (spriteIndex + 1) % sprites.size();
            spriteComponent->setSprite(sprites[spriteIndex]);
        }else if(playerController->fwd){
            spriteIndex = (spriteIndex + 1) % sprites.size();
            spriteComponent->setSprite(upDownSprites[spriteIndex]);
        }else if(playerController->bwd){
            spriteIndex = (spriteIndex + 1) % sprites.size();
            spriteComponent->setSprite(upDownSprites[spriteIndex + 4]);
        }
    }

    bool directionX = velocity.x < 0;
    auto chosenSprite = spriteComponent->getSprite();
    chosenSprite.setFlip(glm::vec2(directionX, false));
    chosenSprite.setScale(glm::vec2(.8, 1.2f));
    spriteComponent->setSprite(chosenSprite);
}

void SpriteAnimationComponent::setSprites(std::vector<sre::Sprite> sprites) {
    this->sprites = sprites;
}

void SpriteAnimationComponent::setUpDownSprites(std::vector<sre::Sprite> sprites) {
    this->upDownSprites = sprites;
}

float SpriteAnimationComponent::getAnimationTime() const {
    return animationTime;
}

void SpriteAnimationComponent::setAnimationTime(float animationTime) {
    SpriteAnimationComponent::animationTime = animationTime;
}
