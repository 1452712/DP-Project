#ifndef __LEVEL_SCENE_CONFIG_H__
#define __LEVEL_SCENE_CONFIG_H__

#include "cocos2d.h"
#include "SceneManager.h"
#include <map>
#include <string>

USING_NS_CC;

class LevelSceneConfig {
public:
	// Constructor
	LevelSceneConfig();

	// Config Attribute
	std::map<enum SCENE_INDEX, std::string> BACKGROUND_MUSIC;
	std::map<enum SCENE_INDEX, std::string> BACKGROUND_IMG_1;
	std::map<enum SCENE_INDEX, std::string> BACKGROUND_IMG_2;
	std::map<enum SCENE_INDEX, std::string> TITLE_IMG;

	std::map<enum SCENE_INDEX, std::string> UMBRELLA_IMG;
	std::map<enum SCENE_INDEX, int> UMBRELLA_PURITY;
	std::map<enum SCENE_INDEX, float> TIME_LIMIT;
};

#endif