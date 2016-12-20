#ifndef __LEVEL_SCENE_FACTORY_H__
#define __LEVEL_SCENE_FACTORY_H__

#include <string>
#include "cocos2d.h"

#include "SceneFactory.h"
#include "LevelSceneConfig.h"
#include "..\Entity\RainDrop.h"

USING_NS_CC;

class LevelSceneFactory: public SceneFactory {
public:
    LevelScene* createScene(LevelScene *scene, SCENE_INDEX scene_type, Vector<RainDrop*> *rain);
private:
	void AddRainDrops(LevelScene *scene, SCENE_INDEX scene_type,Vector<RainDrop*> *rain);

	//单个场景的雨滴
	void AddRainDropsS2(LevelScene *scene, Vector<RainDrop*> *rain);
	void AddRainDropsS3(LevelScene *scene, Vector<RainDrop*> *rain);
	void AddRainDropsS4(LevelScene *scene, Vector<RainDrop*> *rain);
	void AddRainDropsS5(LevelScene *scene, Vector<RainDrop*> *rain);
	void AddRainDropsS6(LevelScene *scene, Vector<RainDrop*> *rain);

	//特殊的结束场景
	void AddEndScene(LevelScene *scene);

};

#endif