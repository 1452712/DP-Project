#ifndef __LEVEL_SCENE_H__
#define __LEVEL_SCENE_H__

#include "cocos2d.h"
#include "..\Entity\Umbrella.h"
#include "..\Entity\RainDrop.h"

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
	virtual void ChangeScene(float delta) = 0;
	//virtual void ChangeScene(float delta,SCENE_INDEX) = 0;

	//调整雨滴位置
	void ResetRainDropPosition(Ref *ptr_sender);
protected:
	//绑定Umbrella--Dynamic
	//virtual void AddUmbrella(TMXTiledMap* map) = 0;
	virtual void AddUmbrella(TMXTiledMap* map,SCENE_INDEX) = 0;
	//初始化背景--Dynamic
	//virtual void InitializeBackground() = 0;
	virtual void InitializeBackground(SCENE_INDEX) = 0;

	//开启菜单Callback
	void MenuButtomCallBack(Ref *ptr_sender);

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
};

#endif
