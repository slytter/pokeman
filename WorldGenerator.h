//
// Created by Sune Øllgaard Klem on 12/12/2019.
//

#ifndef SIMPLERENDERENGINEPROJECT_WORLDGENERATOR_H
#define SIMPLERENDERENGINEPROJECT_WORLDGENERATOR_H

#endif //SIMPLERENDERENGINEPROJECT_WORLDGENERATOR_H
#include "sre/SpriteAtlas.hpp"
#include "GameObject.hpp"
#include "SpriteComponent.hpp"
#include "Box2D/Dynamics/b2World.h"



class WorldGenerator {
public:
    WorldGenerator ();
    void loadPokemanMap (std::string filename);

    int getTile(int x, int y);
    int getWidth();
    int getHeight();

    glm::vec2 worldOffset;

    glm::vec2 getStartingPosition();
    float getStartingRotation();


private:
    std::vector<std::vector<int>> tiles;
    glm::vec2 startingPosition;
    float startingRotation;

};