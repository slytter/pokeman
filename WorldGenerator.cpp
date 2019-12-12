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
using namespace rapidjson;

WorldGenerator::WorldGenerator(){


}


void WorldGenerator::loadPokemanMap (string filename) {
    ifstream fis(filename);
    IStreamWrapper isw(fis);
    Document d;
    d.ParseStream(isw);

    const Value &a = d["tileMap"];
    assert(a.IsArray());

    for (SizeType i = 0; i < a.Size(); i++) {
        auto row = a[i].GetArray();
        tiles.push_back({row[0].GetInt(), row[1].GetInt(), row[2].GetInt(),
                          row[3].GetInt(), row[4].GetInt(), row[5].GetInt(),
                          row[6].GetInt(), row[7].GetInt(), row[8].GetInt()});
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

glm::vec2 WorldGenerator::getStartingPosition() {
    return startingPosition;
}

float WorldGenerator::getStartingRotation() {
    return startingRotation;
}

