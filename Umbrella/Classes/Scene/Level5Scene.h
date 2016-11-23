#ifndef __LEVEL_5_SCENE_H__
#define __LEVEL_5_SCENE_H__

#include "LevelScene.h"
#include "cocos2d.h"
USING_NS_CC;

//////////////////////////////
////LevelXScene///////////////
////×¢ÊÍ¼ûLevel6Scene//////////
//////////////////////////////
class Level5Scene : public LevelScene {
public:
	static Scene* CreateScene();
	virtual void ChangeScene(float delta);
	CREATE_FUNC(Level5Scene);
private:
	virtual void AddUmbrella(TMXTiledMap *map);
	virtual void InitializeBackground();
};

#endif
