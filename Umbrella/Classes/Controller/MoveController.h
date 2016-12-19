#ifndef __MOVE_CONTROLLER_H__
#define __MOVE_CONTROLLER_H__

#include "cocos2d.h"
#include "ActionController.h"
USING_NS_CC;


class MoveController: public ActionController {
public:
	//Ë¢ÐÂ
	void actionUpdate(Sprite *sprite);
};

#endif