#include "sound.h"

Music::Music(const char* path) {
	if (Mix_OpenAudio(11400, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		std::cout << "mix failed open music: " << Mix_GetError() << std::endl;
	} else {
		music = Mix_LoadMUS(path);
		if (music == NULL) {
			std::cout << "error loading music: " << Mix_GetError() << std::endl;
		}
	}
}

void Music::Play(bool is_loop) {
	if (is_loop) {
		Mix_PlayMusic(music, -1);
	}
	if (!is_loop) {
		Mix_PlayMusic(music, 0);
	}
}

void Music::Stop() {
	Mix_HaltMusic();
}

void Music::Pause() {
	Mix_PauseMusic();
}

void Music::Continue() {
	Mix_ResumeMusic();
}

Music::~Music() {
	Mix_FreeMusic(music);
	music = NULL;
}

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
