#pragma once

#include "Component.hpp"
#include "sre/Sprite.hpp"
#include "SpriteComponent.hpp"
#include "TrainerController.hpp"
#include "PhysicsComponent.hpp"
#include "sre/SpriteAtlas.hpp"

class SpriteAnimationComponent: public Component {
public:
    SpriteAnimationComponent(GameObject *gameObject);
    std::shared_ptr<TrainerController> playerController;
    void setSprites(std::vector<sre::Sprite> sprites);      // sprite sequence
    void setUpDownSprites(std::vector<sre::Sprite> sprites);
    void update(float deltaTime) override;

    float getAnimationTime() const;                         // time between animations (in seconds)
    void setAnimationTime(float animationTime);
private:
    std::shared_ptr<PhysicsComponent> characterPhysics;
    float animationTime = 0.300f;
    std::vector<sre::Sprite> sprites;
    std::vector<sre::Sprite> upDownSprites;
    float time = 0;
    int spriteIndex = 0;
};


