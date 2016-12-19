#ifndef __SCENE_FACTORY_H__
#define __SCENE_FACTORY_H__

#include "cocos2d.h"
#include "LevelScene.h"
#include "SceneManager.h"
USING_NS_CC;

//abstract base class
class SceneFactory {
public:
    virtual LevelScene* createScene(LevelScene*, SCENE_INDEX, Vector<RainDrop*>*) = 0;
};

#endif