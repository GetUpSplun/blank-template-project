#include "scene_manager.h"

SceneManager::SceneManager() {
	
}

IScene* SceneManager::GetScene() {
	return scenes.back();
}

void SceneManager::NewScene(IScene* s) {
	for (int i = 0; i < scenes.size(); ++i) {
		scenes[i]->Unload();
		delete scenes[i];
		scenes[i] = NULL;
	}
	scenes.clear();
	scenes.push_back(s);
}

SceneManager::~SceneManager() {
	for (std::vector<IScene*>::iterator i = scenes.begin(); i < scenes.end(); ++i) {
		delete *i;
		*i = NULL;
	}
	scenes.clear();
} 
