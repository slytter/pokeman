//
// Created by Nikolaj on 10/12/2019.
//

#ifndef SIMPLERENDERENGINEPROJECT_NPC_H
#define SIMPLERENDERENGINEPROJECT_NPC_H

#include "GameObject.hpp"
#include "Collidable.hpp"

class NPC : public GameObject, public Collidable  {
public:
    NPC(const sre::Sprite &sprite, bool *_isDead);
    void update(float deltaTime) override;
    void onCollision(std::shared_ptr<GameObject> other) override;

private:
    glm::vec2 winSize;

};


#endif //SIMPLERENDERENGINEPROJECT_NPC_H
