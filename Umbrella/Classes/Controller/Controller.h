#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "cocos2d.h"
#include "ControllerListener.h"
USING_NS_CC;

class Controller : public Node {
public:
	//°ó¶¨¼àÌýÕß
	void SetControllerListener(ControllerListener* controller_listener);

protected:
	ControllerListener* m_controller_listener;
};

#endif