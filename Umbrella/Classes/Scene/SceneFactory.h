#ifndef __SCENE_FACTORY_H__
#define __SCENE_FACTORY_H__

#include "cocos2d.h"
#include "LevelScene.h"
#include "LevelSceneConfig.h"
#include "../Entity/RainDrop.h"

USING_NS_CC;

//abstract base class
class SceneFactory {
public:
    virtual LevelScene* createScene(LevelScene *scene,enum SCENE_INDEX scene_type, Vector<RainDrop*> *rain) = 0;
};

#endif