#ifndef __LEVEL_SCENE_FACTORY_H__
#define __LEVEL_SCENE_FACTORY_H__

#include "cocos2d.h"
#include "SceneFactory.h"
USING_NS_CC;

class LevelSceneFactory: public SceneFactory {
public:
    Scene* createScene();
    Scene* createScene(string args);
};