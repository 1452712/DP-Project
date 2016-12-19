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
	//virtual void ChangeScene(float delta,SCENE_INDEX) = 0;

	//�������λ��
	void ResetRainDropPosition(Ref *ptr_sender);

	//��Umbrella--Dynamic
	//virtual void AddUmbrella(TMXTiledMap* map) = 0;
	void AddUmbrella(TMXTiledMap* map);
	//��ʼ������--Dynamic
	//virtual void InitializeBackground() = 0;
	void InitializeBackground();
		
	//����ܶ�
	void FogUpdate(float delta);
	//��������Ľ�������
	void SetNextLayer(Sprite* );

	CREATE_FUNC(LevelScene);
protected:

	//�����˵�Callback
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

	//�洢���
	Vector<RainDrop*> rain;

	//�洢��
	Sprite *background_fog_1;
	Sprite *background_fog_2;
	bool is_fat;
	float fat_time;
};

#endif
