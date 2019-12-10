//
//  Created by Nikolaj Schlüter and Sune Klem on 09/12/2019.
//

#include "sre/SDLRenderer.hpp"
#include <vector>
#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"
#include "GameObject.hpp"
#include "Player.h"

#ifndef SIMPLERENDERENGINEPROJECT_POKEMANGREEN_H
#define SIMPLERENDERENGINEPROJECT_POKEMANGREEN_H
#endif //SIMPLERENDERENGINEPROJECT_POKEMANGREEN_H


class PokemanGreen {
public:
    PokemanGreen ();
    void init ();
    void startGame ();
    std::shared_ptr<Player> player;
private:
    void keyEvent(SDL_Event &event, std::shared_ptr<Player> player);
    sre::SDLRenderer renderer;

    //Camera settings
    sre::Camera mainCam;
    glm::vec2 camRotation;




    std::shared_ptr<sre::SpriteAtlas> atlas;
    std::vector<std::shared_ptr<GameObject>> gameObjects;
    bool isDead = false;
    glm::vec2 winSize;
    void render();
    bool debugCollisionCircles = false;
    // void drawCircle(std::vector<glm::vec3> &lines, glm::vec2 position, float radius);
};