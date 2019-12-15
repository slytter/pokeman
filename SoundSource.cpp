#include "SoundSource.h"
#include <iostream>
#include "SDL_mixer.h"

using namespace std;

SoundSource::SoundSource(char* _pathName, bool _shouldLoop, int _channel, float _volume) {
    pathName = _pathName;
    shouldLoop = _shouldLoop;
    channel = _channel;
    volume = _volume;

    // Opening audio
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) {
        cout << "Cannot initialize audio output"<< endl;
        return;
    }
    // Loading sound from path:
    sound = Mix_LoadWAV( pathName );
    // We converted volume from being an int ranging 0-128 to a 0-1 float.
    Mix_Volume(channel, (int)(volume * 128));
};

int SoundSource::play(){
    // Playing on specific channel with the sound, an inline if statement setting loop to -1 or 0 and
    Mix_PlayChannelTimed(channel, sound, shouldLoop ? -1 : 0, 0);
    return 1;
}
