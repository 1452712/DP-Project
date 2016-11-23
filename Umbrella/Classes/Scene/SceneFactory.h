#ifndef __SCENE_FACTORY_H__
#define __SCENE_FACTORY_H__

#include "cocos2d.h"
USING_NS_CC;

//abstract base class
class SceneFactory {
public:
    virtual Scene* createScene() = 0;
    virtual Scene* createScene(string args) = 0;
};

#endif