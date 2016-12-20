#include "SceneManager.h"


SceneManager* SceneManager::m_scene_manager = nullptr;
LevelSceneConfig SceneManager::config;

bool SceneManager::init() {
	return true;
}

SceneManager* SceneManager::GetInstance() {
	if(m_scene_manager == nullptr) {
		if(m_scene_manager = new SceneManager()) {
			m_scene_manager->retain();
			m_scene_manager->autorelease();
		}else{
			m_scene_manager = nullptr;
		}
	}
	return m_scene_manager;
}

void SceneManager::ChangeScene(SCENE_INDEX scene_type){
	Scene* next_scene = nullptr;
	//Ô¤¼ÓÔØÒôÀÖ
	switch(scene_type) {
	case level_1_scene: case level_2_scene: case level_3_scene:
	case level_4_scene: case level_5_scene: case level_6_scene:
		CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(config.BACKGROUND_MUSIC[scene_type].c_str());
		next_scene = LevelScene::CreateScene();
		break;
	case begin_scene:
		CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(config.BACKGROUND_MUSIC[scene_type].c_str());
		next_scene = BeginScene::CreateScene();
		break;
	case end_scene:
		CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(config.BACKGROUND_MUSIC[scene_type].c_str());
		next_scene = EndScene::CreateScene();
		break;
	default:
		break;
	}

	if (next_scene != nullptr) {
		Director *director = Director::getInstance();
		Scene *current_scene = director->getRunningScene();
		if (current_scene == nullptr) {
			director->runWithScene(next_scene);
		}else{
			director->replaceScene(TransitionFade::create(0.5f,next_scene));
		}
	}
}

//parameter menu_scene for mark(no use)
void SceneManager::CoverScene(const SCENE_INDEX scene_type) {
	//can be extended
	Scene *temp_scene = MenuScene::CreateScene();
	if (temp_scene != nullptr) {
		Director *director = Director::getInstance();
		Scene *current_scene = director->getRunningScene();
		if (current_scene != nullptr) {
			director->pushScene(temp_scene);
		}
	}
}

//parameter menu_scene for mark(no use)
void SceneManager::RevertScene(const SCENE_INDEX scene_type){
	Director *director = Director::getInstance();
	Scene *current_scene = director->getRunningScene();
	if (current_scene != nullptr) {
		director->popScene();
	}
}
