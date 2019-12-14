#pragma once

#include "Component.hpp"
#include "CameraController.hpp"
#include "sre/SpriteAtlas.hpp"

class TrainerController : public Component {
public:
    explicit TrainerController(GameObject *gameObject);
    std::shared_ptr<PhysicsComponent> phys;
    bool onKey(SDL_Event &event) override;
    void update(float deltaTime) override;
    void onCollisionStart(PhysicsComponent *comp) override;
    void onCollisionEnd(PhysicsComponent *comp) override;
    void onGui() override;
    void setCamera(std::shared_ptr<CameraController> _cam);
    glm::vec2 currentDirection = glm::vec2(1, 0);
    bool fwd = false;
    bool bwd = false;
    bool left = false;
    bool right = false;
    glm::vec2 collectedDirection = {0, 0};
    float pDmg = 20;
    float health = 100;


private:
    float playerSpeed = 0.75f;
    void updatePos(glm::vec2);
    glm::vec2 savedPos;
    std::shared_ptr<PhysicsComponent> trainerPhys;
    std::shared_ptr<CameraController> cam;

    glm::vec2 GUIOffset;
    glm::vec2 GUISize;

};
