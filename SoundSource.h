//
// Created by Nikolaj on 13/12/2019.
//

#ifndef SIMPLERENDERENGINEPROJECT_SOUNDSOURCE_H
#define SIMPLERENDERENGINEPROJECT_SOUNDSOURCE_H
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

class SoundSource {
public:
    SoundSource(char* _filePath);
    int play();
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;

    char* pathName = (char*)"snare.wav";
};
// see the implementation for more information

#define MUS_PATH "Roland-GR-1-Trumpet-C5.wav"

// prototype for our audio callback


#endif //SIMPLERENDERENGINEPROJECT_SOUNDSOURCE_H
