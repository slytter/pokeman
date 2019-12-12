//
// Created by Nikolaj on 12/12/2019.
//

#ifndef SIMPLERENDERENGINEPROJECT_PROJECTILE_H
#define SIMPLERENDERENGINEPROJECT_PROJECTILE_H

#include "Component.hpp"
#include "PhysicsComponent.hpp"

class Projectile : public Component {
public:
    explicit Projectile(GameObject *gameObject);
    void update(float deltaTime) override;
    void onCollisionStart(PhysicsComponent *comp) override;
    void onCollisionEnd(PhysicsComponent *comp) override;
    std::shared_ptr<PhysicsComponent> phys;
    std::shared_ptr<GameObject> playerReference;
    void shoot(glm::vec2 pos, float rotation);
};


#endif //SIMPLERENDERENGINEPROJECT_PROJECTILE_H
