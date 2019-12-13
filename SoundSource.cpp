//
// Created by Nikolaj on 13/12/2019.
//

#include "SoundSource.h"
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

SoundSource::SoundSource(char* _pathName) {
    pathName = _pathName;
    SDL_LoadWAV(pathName, &wavSpec, &wavBuffer, &wavLength);
};

int SoundSource::play(){
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);
    // cout << success << endl;
    return success;
}
