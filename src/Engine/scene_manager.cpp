#include "scene_manager.h"

SceneManager::SceneManager() {
	
}

IScene* SceneManager::GetScene() {
	return scenes.back();
}

void SceneManager::NewScene(IScene* scene) {
	Clear();
	scenes.push_back(scene);
}

void SceneManager::PushScene(IScene* scene) {
	scenes.push_back(scene);
}

void SceneManager::PopScene() {
	scenes.erase(scenes.end());
}

void SceneManager::Clear() {
	for (std::vector<IScene*>::iterator i = scenes.begin(); i < scenes.end(); ++i) {
		(*i)->Unload();
		delete *i;
		*i = NULL;
	}
	scenes.clear();
}

SceneManager::~SceneManager() {
	Clear();
} 
