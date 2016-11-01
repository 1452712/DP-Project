#ifndef __CONTROLLER_LISTENER_H__
#define __CONTROLLER_LISTENER_H__

#include "cocos2d.h"
USING_NS_CC;

//抽象基类 可用于扩展
class ControllerListener {
public:
	//设置实时坐标
	virtual void SetTagPosition(int x,int y) = 0 ;
	//获取实时坐标
	virtual Point GetTagPosition() = 0 ;
};

#endif