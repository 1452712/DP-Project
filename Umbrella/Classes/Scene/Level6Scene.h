#ifndef __LEVEL_6_SCENE_H__
#define __LEVEL_6_SCENE_H__

#include "LevelScene.h"
#include "cocos2d.h"
USING_NS_CC;

class Level6Scene : public LevelScene {
public:
	//��ʼ��
	static Scene* CreateScene();

	//����ܶ�
	void FogUpdate(float delta);

	//�ı䳡��
	virtual void ChangeScene(float delta);

	CREATE_FUNC(Level6Scene);
private:
	//�̳�:��Umbrella
	virtual void AddUmbrella(TMXTiledMap *map);
	//�̳�:������Ʊ���
	virtual void InitializeBackground();

	Sprite *background_fog_1;
	Sprite *background_fog_2;
	bool is_fat;
	float fat_time;
};

#endif
