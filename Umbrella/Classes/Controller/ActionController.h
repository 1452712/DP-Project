#ifndef __ACTION_CONTROLLER_H__
#define __ACTION_CONTROLLER_H__

#include "cocos2d.h"
USING_NS_CC;

//������� ��������չ
class ActionController {
public:
	//ˢ��
	virtual void actionUpdate(Sprite *sprite) = 0 ;
};

#endif