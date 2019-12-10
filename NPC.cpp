//
// Created by Nikolaj on 10/12/2019.
//

#include "NPC.h"
#include "sre/Renderer.hpp"

NPC::NPC(const sre::Sprite &sprite, bool *_isDead) : GameObject(sprite) {
    scale = glm::vec2(0.5f,0.5f);
    winSize = sre::Renderer::instance->getWindowSize();
    position = winSize * 0.3f;
    type = SPACESHIP;
}


void NPC::update(float deltaTime) {
    GameObject::update(deltaTime);
}
