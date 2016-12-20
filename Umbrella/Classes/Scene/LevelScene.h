#ifndef __LEVEL_SCENE_H__
#define __LEVEL_SCENE_H__

#include "cocos2d.h"

#include "LevelSceneConfig.h"
#include "..\Entity\Umbrella.h"
#include "..\Entity\RainDrop.h"
#include "..\Controller\FloatController.h"

USING_NS_CC;

class LevelScene : public Layer {
public:
	//��ʼ��
	static Scene* CreateScene();
	virtual bool init();

	//ʵʱ����
	virtual void update(float delta);
	//��ʱ
	void TimeUpdate(float delta);
	//��ʼ��Ϸ
	void LevelUpdate(float delta);
	//��ʱ����
	void TimeUp(float delta);

	//��������--Dynamic
	void ChangeScene(float delta);

	//�������λ��
	void ResetRainDropPosition(Ref *ptr_sender);

	//��Umbrella--Dynamic
	void AddUmbrella(TMXTiledMap* map);
	//��ʼ������--Dynamic
	void InitializeBackground();
		
	//����ܶ�
	void FogUpdate(float delta);
	//��������Ľ�������
	void SetNextLayer(Sprite* next_layer);

	CREATE_FUNC(LevelScene);
private:

	//�����˵�Callback
	void MenuButtomCallBack(Ref *ptr_sender);

	static enum SCENE_INDEX m_current_scene;

	static LevelSceneConfig config;

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

	//�洢���
	Vector<RainDrop*> rain;

	//Ũ��/����
	bool is_fat;
	float fat_time;
};

#endif
