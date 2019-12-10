//
// Created by Nikolaj on 10/12/2019.
//

#include "Player.h"
#include "sre/Renderer.hpp"

Player::Player(const sre::Sprite &sprite, bool *_isDead) : GameObject(sprite) {
    scale = glm::vec2(0.5f,0.5f);
    winSize = sre::Renderer::instance->getWindowSize();
    radius = 23;
    position = winSize * 0.5f;
    type = SPACESHIP;
    isDead = _isDead;
}

void Player::update(float deltaTime) {

}

void Player::onCollision(std::shared_ptr<GameObject> other) {

}

void Player::onKey(SDL_Event &keyEvent) {

}
