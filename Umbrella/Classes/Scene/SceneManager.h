#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include "cocos2d.h"
#include "BeginScene.h"
#include "MenuScene.h"
#include "LevelScene.h"
#include "EndScene.h"
#include "SimpleAudioEngine.h"
#include "LevelSceneConfig.h"
USING_NS_CC;

enum SCENE_INDEX {menu_scene   ,level_1_scene,level_2_scene,level_3_scene,
		          level_4_scene,level_5_scene,level_6_scene,begin_scene  ,
				  end_scene    ,};
//场景控制
class SceneManager : public Ref {
public:
	virtual bool init();

	static SceneManager* GetInstance();

	//切换（释放上一场景）
	void ChangeScene(SCENE_INDEX scene_type);

	//菜单面（可扩展）
	//暂停
	void CoverScene(const SCENE_INDEX scene_type = menu_scene);
	//回复
	void RevertScene(const SCENE_INDEX scene_type = menu_scene);
private:
	static SceneManager* m_scene_manager;
};

#endif
