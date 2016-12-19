#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class MenuScene : public Layer {
public:
	static Scene *CreateScene();
	virtual bool init();
	
	CREATE_FUNC(MenuScene);
private:
	//退出菜单按钮Callback
	void MenuBottomCallBack(Ref *ptr_sender);
	//退出游戏按钮Callback
	void ExitBottomCallBack(Ref *ptr_sender);
};

#endif