#ifndef __LEVEL_SCENE_FACTORY_H__
#define __LEVEL_SCENE_FACTORY_H__

#include <string>
#include "cocos2d.h"

#include "SceneFactory.h"

USING_NS_CC;

class LevelSceneFactory: public SceneFactory {
public:
    LevelScene* createScene(LevelScene*);
private:
	static SCENE_INDEX current_scene;
};

#endif