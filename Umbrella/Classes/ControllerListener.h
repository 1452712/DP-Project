#ifndef __CONTROLLER_LISTENER_H__
#define __CONTROLLER_LISTENER_H__

#include "cocos2d.h"
USING_NS_CC;

//������� ��������չ
class ControllerListener {
public:
	//����ʵʱ����
	virtual void SetTagPosition(int x,int y) = 0 ;
	//��ȡʵʱ����
	virtual Point GetTagPosition() = 0 ;
};

#endif