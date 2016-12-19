#include "LevelXScene.h"
#include "LevelScene.h"
#include "..\Entity\Umbrella.h"
#include "..\Controller\FloatController.h"
#include "SceneManager.h"
#include "LevelSceneConfig.h"

LevelSceneConfig config;

Scene* LevelXScene::CreateScene() {
	auto scene = Scene::create();
	auto layer = LevelXScene::create();
	scene->addChild(layer);

	return scene;
}

void LevelXScene::AddUmbrella(TMXTiledMap *map, SCENE_INDEX scene_type) {
	Size visible_size = Director::getInstance()->getVisibleSize();

	//具体Umbrella设置
	//图片
	Sprite* umbrella_sprite = Sprite::create(config.UMBRELLA_IMG[scene_type].c_str());     
	m_umbrella = Umbrella::create();
	//Purity
	m_umbrella->SetPurity(config.UMBRELLA_PURITY[scene_type]);
	//时间限制
	m_umbrella->SetTimeLimit(config.TIME_LIMIT[scene_type]);
	//绑定精灵
	m_umbrella->BindSprite(umbrella_sprite);
	m_umbrella->SetTiledMap(map);

	//加载地图,将Umbrella绑定到object层
    TMXObjectGroup* object_group = map->getObjectGroup("object");
    ValueMap player_point = object_group->getObject("player_point");
    float player_x = player_point.at("x").asFloat();
    float player_y = player_point.at("y").asFloat();
    m_umbrella->setPosition(Point(player_x , player_y) );

    map->addChild(m_umbrella);

	//绑定监听器
	FloatController *float_controller = FloatController::create();

	this->addChild(float_controller);
	m_umbrella->SetController(float_controller);
}

void LevelXScene::InitializeBackground(SCENE_INDEX scene_type) 
{
    Size visible_size = Director::getInstance()->getVisibleSize();

	//具体背景设置
    m_background_1 = Sprite::create(config.BACKGROUND_IMG_1[scene_type].c_str());
    m_background_1->setPosition(Point(visible_size.width / 2, visible_size.height / 2));
    this->addChild(m_background_1, 2);

    m_background_2 = Sprite::create(config.BACKGROUND_IMG_2[scene_type].c_str());
    m_background_2->setPosition(Point(visible_size.width + visible_size.width / 2, visible_size.height / 2));
    this->addChild(m_background_2, 2);

	//Level条
	m_level_layer = Sprite::create(config.TITLE_IMG[scene_type].c_str());
	m_level_layer->setPosition(Point(visible_size.width / 2, visible_size.height / 2));
	this->addChild(m_level_layer,20);

}

void LevelXScene::ChangeScene(float delta, SCENE_INDEX scene_type) {
	SceneManager::GetInstance()->ChangeScene(config.NEXT_SCENE[scene_type]);
}