//
// Created by Sune Øllgaard Klem on 12/12/2019.
//
#pragma once
#include "WorldGenerator.h"
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"

#include <fstream>
#include <iostream>

using namespace std;
using namespace glm;
using namespace rapidjson;

WorldGenerator::WorldGenerator(){


}


void WorldGenerator::loadPokemanMap (string filename) {
    ifstream fis(filename);
    IStreamWrapper isw(fis);
    Document d;
    d.ParseStream(isw);

    startingPosition = vec2(0,0);
    worldOffset = vec2(1000,1000);

    enemySpawnPoints.push_back(vec2(948.205, 509.023));
    enemySpawnPoints.push_back(vec2(-806.035, -160.443));
    enemySpawnPoints.push_back(vec2(-828.446,446.275));
    enemySpawnPoints.push_back(vec2(869.736, -319.354));

    const Value &a = d["tileMap"];
    assert(a.IsArray());



    for (SizeType i = 0; i < a.Size(); i++) {
        auto col = a[i].GetArray();
        std::vector<int> singleRow;
        for (int j = 0; j <col.Size() ; ++j) {
            singleRow.push_back(col[j].GetInt());
        }
        tiles.push_back({singleRow});
    }

}

int WorldGenerator::getTile(int x, int y) {

    return tiles.at(y).at(x);
}

int WorldGenerator::getWidth() {
    return tiles[0].size();
}

int WorldGenerator::getHeight() {
    return tiles.size();
}

vec2 WorldGenerator::getStartingPosition() {
    return startingPosition;
}

float WorldGenerator::getStartingRotation() {
    return startingRotation;
}

