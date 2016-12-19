#ifndef __LEVEL_X_SCENE_H__
#define __LEVEL_X_SCENE_H__

#include "LevelScene.h"
#include "SceneManager.h"
#include "LevelSceneConfig.h"
#include "cocos2d.h"
USING_NS_CC;

// ����ģʽ�Ĳ�Ʒ
class LevelXScene : public LevelScene {
public:
	//��ʼ��
	static Scene* CreateScene();

	//����ܶ�
	//void FogUpdate(float delta);

	//�ı䳡��
	virtual void ChangeScene(float delta,SCENE_INDEX);

	CREATE_FUNC(LevelXScene);
private:
	//�̳�:��Umbrella
	virtual void AddUmbrella(TMXTiledMap *map,SCENE_INDEX);
	//�̳�:������Ʊ���
	virtual void InitializeBackground(SCENE_INDEX);

	//Sprite *background_fog_1;
	//Sprite *background_fog_2;
	//bool is_fat;
	//float fat_time;
};

#endif