#include "SceneManager.h"
#include "BeginScene.h"
#include "MenuScene.h"
#include "LevelScene.h"
#include "Level1Scene.h"
#include "Level2Scene.h"
#include "Level3Scene.h"
#include "Level4Scene.h"
#include "Level5Scene.h"
#include "Level6Scene.h"
#include "LevelXScene.h"
#include "EndScene.h"
#include "SimpleAudioEngine.h"
#include "LevelSceneConfig.h"

SceneManager* SceneManager::m_scene_manager = nullptr;
LevelSceneConfig config;

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
	case level_1_scene:
		//CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(config.BACKGROUND_MUSIC[scene_type].c_str());
		//next_scene = LevelXScene::CreateScene();
		//break;
	case level_2_scene:
		//CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(config.BACKGROUND_MUSIC[scene_type].c_str());
		//next_scene = Level2Scene::CreateScene();
		//break;
	case level_3_scene:
		//CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(config.BACKGROUND_MUSIC[scene_type].c_str());
		//next_scene = Level3Scene::CreateScene();
		//break;
	case level_4_scene:
		//CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(config.BACKGROUND_MUSIC[scene_type].c_str());
		//next_scene = Level4Scene::CreateScene();
		//break;
	case level_5_scene:
		//CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(config.BACKGROUND_MUSIC[scene_type].c_str());
		//next_scene = Level5Scene::CreateScene();
		//break;
	case level_6_scene:
		CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(config.BACKGROUND_MUSIC[scene_type].c_str());
		next_scene = LevelXScene::CreateScene();
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
