#ifndef __LEVEL_6_SCENE_H__
#define __LEVEL_6_SCENE_H__

#include "LevelScene.h"
#include "cocos2d.h"
USING_NS_CC;

class Level6Scene : public LevelScene {
public:
	//初始化
	static Scene* CreateScene();

	//雾的跑动
	void FogUpdate(float delta);

	//改变场景
	virtual void ChangeScene(float delta);

	CREATE_FUNC(Level6Scene);
private:
	//继承:绑定Umbrella
	virtual void AddUmbrella(TMXTiledMap *map);
	//继承:具体绘制背景
	virtual void InitializeBackground();

	Sprite *background_fog_1;
	Sprite *background_fog_2;
	bool is_fat;
	float fat_time;
};

#endif
