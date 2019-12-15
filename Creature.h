
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
    void onGui() override;
    void getPlayer(std::shared_ptr<GameObject> _player);
    void setCamera(std::shared_ptr<CameraController> _cam);
    void getEnemyCount (int _count);
    char enemyId;
    char *idPointer;
    std::shared_ptr<GameObject> player;

private:
    float cSpeed = 100;
    float cHealth = 100;
    float cDmg = 10;
    std::shared_ptr<char> guiRef;
    glm::vec2 dirToPlayer;
    std::shared_ptr<PhysicsComponent> creaturePhys;
    std::shared_ptr<CameraController> cam;
    glm::vec2 GUISize;
    //void updatePos(glm::vec3);
};