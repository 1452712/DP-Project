#ifndef __LEVEL_SCENE_H__
#define __LEVEL_SCENE_H__

#include "cocos2d.h"

#include "SceneManager.h"
#include "LevelSceneFactory.h"
#include "LevelSceneConfig.h"
#include "DecoratorSceneFog.h"
#include "..\Entity\Umbrella.h"
#include "..\Entity\RainDrop.h"
#include "..\Controller\FloatController.h"

USING_NS_CC;

class LevelScene : public Layer {
public:
	//初始化
	static Scene* CreateScene();
	virtual bool init();

	//实时更新
	virtual void update(float delta);
	//计时
	void TimeUpdate(float delta);
	//开始游戏
	void LevelUpdate(float delta);
	//计时结束
	void TimeUp(float delta);

	//更换场景--Dynamic
	void ChangeScene(float delta);
	//virtual void ChangeScene(float delta,SCENE_INDEX) = 0;

	//调整雨滴位置
	void ResetRainDropPosition(Ref *ptr_sender);

	//绑定Umbrella--Dynamic
	//virtual void AddUmbrella(TMXTiledMap* map) = 0;
	void AddUmbrella(TMXTiledMap* map);
	//初始化背景--Dynamic
	//virtual void InitializeBackground() = 0;
	void InitializeBackground();
		
	//雾的跑动
	void FogUpdate(float delta);
	//设置特殊的结束场景
	void SetNextLayer(Sprite* );

	CREATE_FUNC(LevelScene);
protected:

	//开启菜单Callback
	void MenuButtomCallBack(Ref *ptr_sender);

	static SCENE_INDEX m_current_scene;

	Umbrella *m_umbrella;
	Sprite *m_background_1;
	Sprite *m_background_2;
	Sprite *m_level_layer;
	
	Sprite *m_next_layer;
	Sprite *m_over_layer;
	Label *m_label_purity_1;
	Label *m_label_purity_2;
	Label *m_label_time_remaining_1;
	Label *m_label_time_remaining_2;

	//存储雨滴
	Vector<RainDrop*> rain;

	//存储雾
	Sprite *background_fog_1;
	Sprite *background_fog_2;
	bool is_fat;
	float fat_time;
};

#endif
