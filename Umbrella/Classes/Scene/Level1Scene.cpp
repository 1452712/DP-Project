#include "Level1Scene.h"
#include "LevelScene.h"
#include "..\Entity\Umbrella.h"
#include "..\Controller\FloatController.h"
#include "SceneManager.h"
//////////////////////////////
////LevelXScene///////////////
////×¢ÊÍ¼ûLevel6Scene//////////
//////////////////////////////

Scene* Level1Scene::CreateScene() {
	auto scene = Scene::create();
	auto layer = Level1Scene::create();
	scene->addChild(layer);

	return scene;
}


void Level1Scene::AddUmbrella(TMXTiledMap *map) {
	Size visible_size = Director::getInstance()->getVisibleSize();

	Sprite* umbrella_sprite = Sprite::create("Umbrella1.png");     
	m_umbrella = Umbrella::create();
	//m_umbrella->setContentSize(Size(100,100));
	m_umbrella->SetPurity(1000);                                  
	m_umbrella->SetTimeLimit(303.0f);
	m_umbrella->BindSprite(umbrella_sprite);
	m_umbrella->SetTiledMap(map);

    TMXObjectGroup* object_group = map->getObjectGroup("object");
    ValueMap player_point = object_group->getObject("player_point");
    float player_x = player_point.at("x").asFloat();
    float player_y = player_point.at("y").asFloat();
    m_umbrella->setPosition(Point(player_x , player_y) );

    map->addChild(m_umbrella);
	
	FloatController *float_controller = FloatController::create();

	this->addChild(float_controller);
	m_umbrella->SetController(float_controller);
	
}

void Level1Scene::InitializeBackground() 
{
    Size visible_size = Director::getInstance()->getVisibleSize();

    m_background_1 = Sprite::create("Level1SceneBG1.png");
    m_background_1->setPosition(Point(visible_size.width / 2, visible_size.height / 2));
    this->addChild(m_background_1, 2);

    m_background_2 = Sprite::create("Level1SceneBG2.png");
    m_background_2->setPosition(Point(visible_size.width + visible_size.width / 2, visible_size.height / 2));
    this->addChild(m_background_2, 2);

	m_level_layer = Sprite::create("Level1SceneTitle.png");
	m_level_layer->setPosition(Point(visible_size.width / 2, visible_size.height / 2));
	this->addChild(m_level_layer,20);
}

void Level1Scene::ChangeScene(float delta) {
	SceneManager::GetInstance()->ChangeScene(level_2_scene);
}
