#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"
//#include "cocos-ext.h"
//#include "GUI\CCControlExtension\CCControl.h"

///////////////////////
//修改
//slider
///////////////////////
USING_NS_CC;
//USING_NS_CC_EXT;

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
//	void SliderChange(Ref* ptr_sender,Control::EventType control_event);
};

#endif