//
// Created by Nikolaj on 10/12/2019.
//

#include "Player.h"
#include "sre/Renderer.hpp"
using namespace std;
Player::Player(const sre::Sprite &sprite, bool *_isDead) : GameObject(sprite) {
    scale = glm::vec2(0.5f,0.5f);
    winSize = sre::Renderer::instance->getWindowSize();
    position = winSize * 0.5f;
    type = SPACESHIP;
    isDead = _isDead;
}

void Player::update(float deltaTime) {

}

void Player::onKey(SDL_Event &keyEvent) {
    if (keyEvent.key.keysym.sym == SDLK_UP){
        cout << "test";
        position.y ++;
    }
    if (keyEvent.key.keysym.sym == SDLK_DOWN) {
        position.y --;
    }
    if (keyEvent.key.keysym.sym == SDLK_RIGHT) {
        position.x ++;
    }
    if (keyEvent.key.keysym.sym == SDLK_LEFT){
        position.x --;
    }
}
