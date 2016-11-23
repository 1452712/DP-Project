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
	//��ʼ��ϷCallback
    void StartButtomCallBack(Ref *ptr_sender);
	//�򿪲˵�Callback
	void MenuButtomCallBack(Ref *ptr_sender);
};

#endif