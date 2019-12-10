//
// Created by Nikolaj on 10/12/2019.
//

#ifndef SIMPLERENDERENGINEPROJECT_PLAYER_H
#define SIMPLERENDERENGINEPROJECT_PLAYER_H

#include "GameObject.hpp"


class Player : public GameObject  {
public:
    Player(const sre::Sprite &sprite, bool *_isDead);
    void update(float deltaTime) override;
    void onKey(SDL_Event &keyEvent) override;
    bool *isDead;

private:
    glm::vec2 winSize;

};


#endif //SIMPLERENDERENGINEPROJECT_PLAYER_H
