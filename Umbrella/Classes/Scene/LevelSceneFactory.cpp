#include <string>
#include "LevelScene.h"
#include "LevelXScene.h"
#include "SceneManager.h"
#include "LevelSceneFactory.h"

SCENE_INDEX LevelSceneFactory::current_scene = begin_scene;

LevelScene* LevelSceneFactory::createScene(LevelScene* scene) {

	switch(current_scene) {
	case begin_scene:
		current_scene = level_1_scene;
		break;
	}

	TMXTiledMap *map = TMXTiledMap::create("map.tmx");
	scene->addChild(map,4);

	//绑定Umbrella
	scene->AddUmbrella(map, current_scene);
	//具体初始化背景
	scene->InitializeBackground(current_scene);
    return scene;
}

//Scene* LevelSceneFactory::createScene(string args) {
//    return new LevelScene(args);
//}