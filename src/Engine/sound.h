#ifndef SOUND_H
#define SOUND_H

#include <SDL2/SDL_mixer.h>
#include <iostream>

class Music {
public:
	Music(const char* path);

	void Play(bool is_loop);

	void Stop();

	void Pause();

	void Continue();

	~Music();

private:
	Mix_Music* music = NULL;

};

class Sound {
public:
	Sound(const char* path);

	void Play();

	~Sound();

private:
	Mix_Chunk* sound = NULL;

};

#endif
