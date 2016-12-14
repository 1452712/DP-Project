#ifndef __UMBRELLA_H__
#define __UMBRELLA_H__

#include "cocos2d.h"
#include "..\Controller\Controller.h"
#include "..\Controller\ControllerListener.h"
USING_NS_CC;

class Umbrella:public Node,public ControllerListener {
public:
	//��ʼ��
	virtual bool init();
	//��Umbrella����
	void BindSprite(Sprite *sprite);

	//Purity
	//�趨��ʼֵ
    void SetPurity(int purity);
	//��ȡʵʱֵ
	int GetPurity();
	//����˺�
	void Hit(int dt_purity);

	//Time Remaining
	//�趨��ʼֵ
	void SetTimeLimit(float time);
	//ʵʱ����
	void UpdateTimeRemain();
	//��ȡʣ��ʱ��
	float GetTimeRemain();

	//�ж�:�Ƿ�ִ��յ�
	bool HasGotToDestination();

	//�󶨼�����
	void SetController(Controller *controller);
	
	//����Umbrella
	virtual void SetTagPosition(int x,int y);
	virtual Point GetTagPosition();

	//���ƻ���
	void SetViewPointByUmbrella();

	//�󶨵�ͼ
	void SetTiledMap(TMXTiledMap *map);
	CREATE_FUNC(Umbrella);
private:
	Sprite *m_sprite;
	int m_purity;
	float m_time;
	//���ڷ���
	bool is_bouncing;
	bool get_destination;
	Controller *m_controller;

	TMXTiledMap *m_map;
	//��ǲ�
	TMXLayer *meta;

	//cocos2d-x����תΪmap����
	Point PositionTransformTileCoordinate(Point position);
};

#endif