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

//��������
class SceneManager : public Ref {
public:
	virtual bool init();

	static SceneManager* GetInstance();

	//�л����ͷ���һ������
	void ChangeScene(SCENE_INDEX scene_type);

	//�˵��棨����չ��
	//��ͣ
	void CoverScene(const SCENE_INDEX scene_type = menu_scene);
	//�ظ�
	void RevertScene(const SCENE_INDEX scene_type = menu_scene);
private:
	static SceneManager* m_scene_manager;
	static LevelSceneConfig config;
};

#endif
