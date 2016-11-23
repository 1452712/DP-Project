#ifndef __LEVEL_4_SCENE_H__
#define __LEVEL_4_SCENE_H__

#include "LevelScene.h"
#include "cocos2d.h"
USING_NS_CC;

//////////////////////////////
////LevelXScene///////////////
////×¢ÊÍ¼ûLevel6Scene//////////
//////////////////////////////
class Level4Scene : public LevelScene {
public:
	static Scene* CreateScene();
	virtual void ChangeScene(float delta);
	CREATE_FUNC(Level4Scene);
private:
	virtual void AddUmbrella(TMXTiledMap *map);
	virtual void InitializeBackground();
};

#endif
