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
        if(playerController->left || playerController->right){ // if the player moves in x directions:
            spriteIndex = (spriteIndex + 1) % sprites.size(); // Use 'sprites' which includes the player seen from the side
            spriteComponent->setSprite(sprites[spriteIndex]); // the side player sprites are later flipped according to direction
        }else if(playerController->fwd){ // if player is goind foward
            spriteIndex = (spriteIndex + 1) % sprites.size(); // Using the first 4 sprites which includes walking seen from behind
            spriteComponent->setSprite(upDownSprites[spriteIndex]);
        }else if(playerController->bwd){ // backwards
            spriteIndex = (spriteIndex + 1) % sprites.size();
            spriteComponent->setSprite(upDownSprites[spriteIndex + 4]); // + 4 frames includes player from front.
        }
    }

    bool directionX = playerController->currentDirection.x < 0; // here we see whether we should flip the player direction
    auto chosenSprite = spriteComponent->getSprite();
    chosenSprite.setFlip(glm::vec2(directionX, false)); // flipping if velocity is going in the opposite direction
    chosenSprite.setScale(glm::vec2(.8, 1.2f)); // scaling the player to fit isometric camera stretch
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
