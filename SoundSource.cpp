//
// Created by Nikolaj on 13/12/2019.
//

#include "SoundSource.h"
#include <iostream>
#include "SDL_mixer.h"

using namespace std;

SoundSource::SoundSource(char* _pathName, bool _shouldLoop, int _channel, float _volume) {
    pathName = _pathName;
    shouldLoop = _shouldLoop;
    channel = _channel;
    volume = _volume;

    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) {
        cout << "Cannot initialize audio output"<< endl;
        return;
    }
    sound = Mix_LoadWAV( pathName );
    Mix_Volume(channel, (int)(volume * 128));
};

int SoundSource::play(){
    Mix_PlayChannelTimed(channel, sound, shouldLoop ? -1 : 0, 0);
    return 1;
}
