#ifndef __DECORATOR_SCENE_FOG_H__
#define __DECORATOR_SCENE_FOG_H__

#include <string>
#include "cocos2d.h"
#include "LevelScene.h"
#include "DecoratorScene.h"
USING_NS_CC;

class DecoratorSceneFog: public DecoratorScene{
public:
	void AddDecorator(std::string decorator, LevelScene *scene);
	//ÎíµÄÅÜ¶¯
	void FogUpdate(float delta);

	//´æ´¢Îí
	Sprite *background_fog_1;
	Sprite *background_fog_2;
private:
	bool is_fat;
	float fat_time;
};

#endif