#ifndef __LEVEL_SCENE_H__
#define __LEVEL_SCENE_H__

#include "cocos2d.h"
#include "..\Entity\Umbrella.h"
#include "..\Entity\RainDrop.h"

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
	virtual void ChangeScene(float delta) = 0;
	//virtual void ChangeScene(float delta,SCENE_INDEX) = 0;

	//�������λ��
	void ResetRainDropPosition(Ref *ptr_sender);
protected:
	//��Umbrella--Dynamic
	//virtual void AddUmbrella(TMXTiledMap* map) = 0;
	virtual void AddUmbrella(TMXTiledMap* map,SCENE_INDEX) = 0;
	//��ʼ������--Dynamic
	//virtual void InitializeBackground() = 0;
	virtual void InitializeBackground(SCENE_INDEX) = 0;

	//�����˵�Callback
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

	//�洢���
	Vector<RainDrop*> rain;
};

#endif
