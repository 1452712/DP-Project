#ifndef __LEVEL_SCENE_CONFIG_H__
#define __LEVEL_SCENE_CONFIG_H__

#include "cocos2d.h"
#include <map>
#include <string>

USING_NS_CC;

enum SCENE_INDEX {menu_scene   ,level_1_scene,level_2_scene,level_3_scene,
		          level_4_scene,level_5_scene,level_6_scene,begin_scene  ,
				  end_scene    ,};

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

	std::map<enum SCENE_INDEX, enum SCENE_INDEX> NEXT_SCENE;
};

#endif