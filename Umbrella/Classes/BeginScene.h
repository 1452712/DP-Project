#ifndef __BEGIN_SCENE_H__
#define __BEGIN_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;


class BeginScene : public Layer {
public:
	static Scene* CreateScene();
	virtual bool init();

	CREATE_FUNC(BeginScene);
private:
	//开始游戏Callback
    void StartButtomCallBack(Ref *ptr_sender);
	//打开菜单Callback
	void MenuButtomCallBack(Ref *ptr_sender);
};

#endif