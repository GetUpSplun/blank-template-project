#include "sound.h"

Sound::Sound(const char* path) {
	if (Mix_OpenAudio(11400, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		std::cout << "mix failed open audio: " << Mix_GetError() << std::endl;
	} else {
		sound = Mix_LoadWAV(path);
	}

	if (sound == NULL) {
		std::cout << "error loading sound: " << Mix_GetError() << std::endl;
	}
}

void Sound::Play() {
	Mix_PlayChannel(-1, sound, 0);
}

Sound::~Sound() {
	Mix_FreeChunk(sound);
}
