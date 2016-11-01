#ifndef __RAIN_DROP_H__
#define __RAIN_DROP_H__

#include "cocos2d.h"
#include "Umbrella.h"

USING_NS_CC;

class RainDrop : public Node {
public:

	//初始化
	virtual bool init();

	//绑定雨滴精灵
	void BindSprite(Sprite *sprite);
	Sprite* GetSprite();
	//碰撞检测
	bool IsCollideWithUmbrella(Umbrella *umbrella);
	//设置伤害值
	void SetHurtPurity(int hurt_purity);
	//返回伤害值
	int GetHurtPurity();

	CREATE_FUNC(RainDrop);
private:
	//伤害值
	int m_hurt_purity;
	Sprite *m_sprite;
};

#endif