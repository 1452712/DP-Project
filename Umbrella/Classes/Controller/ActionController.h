#ifndef __ACTION_CONTROLLER_H__
#define __ACTION_CONTROLLER_H__

#include "cocos2d.h"
USING_NS_CC;

//抽象基类 可用于扩展
class ActionController {
public:
	//刷新
	virtual void actionUpdate(Sprite *sprite) = 0 ;
};

#endif