#ifndef __END_SCENE_H__
#define __END_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class EndScene : public  Layer {
public:
	static Scene *CreateScene();
	virtual bool init();
	//�𽥳�������Ч��
	virtual void update(float delta);
	//�Զ��˳�
	void end(float delta);

	CREATE_FUNC(EndScene);
private:
	Label *epilogue;
};

#endif