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

#endif //SIMPLERENDERENGINEPROJECT_SOUNDSOURCE_H
