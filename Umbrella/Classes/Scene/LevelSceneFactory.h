#ifndef __LEVEL_SCENE_FACTORY_H__
#define __LEVEL_SCENE_FACTORY_H__

#include <string>
#include "cocos2d.h"

#include "SceneFactory.h"
#include "SceneManager.h"
#include "LevelScene.h"

USING_NS_CC;

class LevelSceneFactory: public SceneFactory {
public:
    LevelScene* createScene(LevelScene*, SCENE_INDEX, Vector<RainDrop*>*);
private:
	LevelScene* AddRainDrops(LevelScene*, SCENE_INDEX,Vector<RainDrop*>*);

	//�������������
	LevelScene* AddRainDropsS2(LevelScene*, Vector<RainDrop*>*);
	LevelScene* AddRainDropsS3(LevelScene*, Vector<RainDrop*>*);
	LevelScene* AddRainDropsS4(LevelScene*, Vector<RainDrop*>*);
	LevelScene* AddRainDropsS5(LevelScene*, Vector<RainDrop*>*);
	LevelScene* AddRainDropsS6(LevelScene*, Vector<RainDrop*>*);

	//����Ľ�������
	LevelScene* AddEndScene(LevelScene*);
};

#endif