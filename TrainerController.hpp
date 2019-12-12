#pragma once

#include "Component.hpp"
#include "sre/SpriteAtlas.hpp"

class TrainerController : public Component {
public:
    explicit TrainerController(GameObject *gameObject);
    std::shared_ptr<PhysicsComponent> phys;
    bool onKey(SDL_Event &event) override;
    void update(float deltaTime) override;
    void onCollisionStart(PhysicsComponent *comp) override;
    void onCollisionEnd(PhysicsComponent *comp) override;
    glm::vec2 currentDirection;
    bool fwd = false;
    bool bwd = false;
    bool left = false;
    bool right = false;
private:
    float playerSpeed = 0.75f;
    void updatePos(glm::vec3);
    std::shared_ptr<PhysicsComponent> trainerPhys;
};
