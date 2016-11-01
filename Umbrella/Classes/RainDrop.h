#ifndef __RAIN_DROP_H__
#define __RAIN_DROP_H__

#include "cocos2d.h"
#include "Umbrella.h"

USING_NS_CC;

class RainDrop : public Node {
public:

	//��ʼ��
	virtual bool init();

	//����ξ���
	void BindSprite(Sprite *sprite);
	Sprite* GetSprite();
	//��ײ���
	bool IsCollideWithUmbrella(Umbrella *umbrella);
	//�����˺�ֵ
	void SetHurtPurity(int hurt_purity);
	//�����˺�ֵ
	int GetHurtPurity();

	CREATE_FUNC(RainDrop);
private:
	//�˺�ֵ
	int m_hurt_purity;
	Sprite *m_sprite;
};

#endif