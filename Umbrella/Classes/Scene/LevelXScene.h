#ifndef __LEVEL_X_SCENE_H__
#define __LEVEL_X_SCENE_H__

#include "LevelScene.h"
#include "SceneManager.h"
#include "LevelSceneConfig.h"
#include "cocos2d.h"
USING_NS_CC;

// 工厂模式的产品
class LevelXScene : public LevelScene {
public:
	//初始化
	static Scene* CreateScene();

	//雾的跑动
	//void FogUpdate(float delta);

	//改变场景
	virtual void ChangeScene(float delta,SCENE_INDEX);

	CREATE_FUNC(LevelXScene);
private:
	//继承:绑定Umbrella
	virtual void AddUmbrella(TMXTiledMap *map,SCENE_INDEX);
	//继承:具体绘制背景
	virtual void InitializeBackground(SCENE_INDEX);

	//Sprite *background_fog_1;
	//Sprite *background_fog_2;
	//bool is_fat;
	//float fat_time;
};

#endif