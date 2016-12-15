#ifndef __SCENE_FACTORY_H__
#define __SCENE_FACTORY_H__

#include "cocos2d.h"
#include "SceneManager.h"
USING_NS_CC;

//abstract base class
class SceneFactory {
public:
    virtual Scene* createScene(enum SCENE_INDEX) = 0;
};

#endif