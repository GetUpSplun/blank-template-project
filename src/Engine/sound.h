#ifndef SOUND_H
#define SOUND_H

#include <SDL2/SDL_mixer.h>
#include <iostream>

class Sound {
public:
	Sound(const char* path);

	void Play();

	~Sound();

private:
	Mix_Chunk* sound = NULL;

};

#endif
