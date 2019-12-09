//
// Created by Sune Øllgaard Klem on 09/12/2019.
//

#include "sre/SDLRenderer.hpp"


#ifndef SIMPLERENDERENGINEPROJECT_POKEMANGREEN_H
#define SIMPLERENDERENGINEPROJECT_POKEMANGREEN_H
#endif //SIMPLERENDERENGINEPROJECT_POKEMANGREEN_H


class PokemanGreen {
public:
    PokemanGreen ();
    void init ();

private:
    sre::SDLRenderer renderer;
    sre::Camera mainCam;


    glm::vec2 winSize;




};