#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"
//#include "cocos-ext.h"
//#include "GUI\CCControlExtension\CCControl.h"

///////////////////////
//�޸�
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
	//�˳��˵���ťCallback
	void MenuBottomCallBack(Ref *ptr_sender);
	//�˳���Ϸ��ťCallback
	void ExitBottomCallBack(Ref *ptr_sender);
//	void SliderChange(Ref* ptr_sender,Control::EventType control_event);
};

#endif