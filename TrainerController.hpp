#pragma once

#include "Component.hpp"

class TrainerController : public Component {
public:
    explicit TrainerController(GameObject *gameObject);

    std::shared_ptr<PhysicsComponent> phys;

    bool onKey(SDL_Event &event) override;

    void onCollisionStart(PhysicsComponent *comp) override;

    void onCollisionEnd(PhysicsComponent *comp) override;
};
