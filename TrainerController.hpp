#pragma once

#include "Component.hpp"

class TrainerController : public Component {
public:
    explicit TrainerController(GameObject *gameObject);

    std::shared_ptr<PhysicsComponent> phys;

    bool onKey(SDL_Event &event) override;

    void update(float deltaTime) override;



    void onCollisionStart(PhysicsComponent *comp) override;

    void onCollisionEnd(PhysicsComponent *comp) override;

private:
    bool fwd = false;
    bool bwd  = false;
    bool left  = false;
    bool right  = false;

    void updatePos(glm::vec3);
};
