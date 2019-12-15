
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
    void shoot();
};


#endif //SIMPLERENDERENGINEPROJECT_PROJECTILE_H
