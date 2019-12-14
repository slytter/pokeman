//
// Created by Nikolaj on 13/12/2019.
//

#ifndef SIMPLERENDERENGINEPROJECT_SOUNDSOURCE_H
#define SIMPLERENDERENGINEPROJECT_SOUNDSOURCE_H
#include <iostream>
#include <SDL2/SDL.h>
#include "SDL_mixer.h"

using namespace std;

class SoundSource {
public:
    SoundSource(char* _pathName, bool _shouldLoop = false, int _channel = 0, float _volume = 1);
    int play();
    Mix_Chunk *sound;
    bool shouldLoop = false;
    float volume;
    int channel = 0;
    char* pathName = (char*)"snare.wav";
};
// see the implementation for more information

#define MUS_PATH "Roland-GR-1-Trumpet-C5.wav"

// prototype for our audio callback


#endif //SIMPLERENDERENGINEPROJECT_SOUNDSOURCE_H
