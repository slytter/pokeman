//
// Created by Sune Øllgaard Klem on 12/12/2019.
//

#ifndef SIMPLERENDERENGINEPROJECT_CREATURE_H
#define SIMPLERENDERENGINEPROJECT_CREATURE_H

#endif //SIMPLERENDERENGINEPROJECT_CREATURE_H

#include "Component.hpp"
#include "sre/SpriteAtlas.hpp"
#include "TrainerController.hpp"

class Creature : public Component {
public:
    explicit Creature(GameObject *gameObject);
    std::shared_ptr<PhysicsComponent> phys;
    void update(float deltaTime) override;
    void onCollisionStart(PhysicsComponent *comp) override;

    void getPlayer(std::shared_ptr<GameObject> _player);
    std::shared_ptr<GameObject> player;

private:
    float cSpeed = 100;
    float cHealth = 100;
    float cDmg = 50;

    glm::vec2 dirToPlayer;
    std::shared_ptr<PhysicsComponent> creaturePhys;
    //void updatePos(glm::vec3);
};