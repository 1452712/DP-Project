#ifndef __DECORATOR_SCENE_H__
#define __DECORATOR_SCENE_H__

#include <string>
#include "cocos2d.h"
#include "LevelScene.h"
USING_NS_CC;

class DecoratorScene{
public:
	virtual void AddDecorator(std::string decorator, LevelScene*) = 0;
};

#endif