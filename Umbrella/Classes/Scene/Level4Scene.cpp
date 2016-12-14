#include "Level4Scene.h"
#include "LevelScene.h"
#include "..\Entity\Umbrella.h"
#include "..\Controller\FloatController.h"
#include "SceneManager.h"
//////////////////////////////
////LevelXScene///////////////
////×¢ÊÍ¼ûLevel6Scene//////////
//////////////////////////////

Scene* Level4Scene::CreateScene() {
	auto scene = Scene::create();
	auto layer = Level4Scene::create();
	scene->addChild(layer);

	return scene;
}


void Level4Scene::AddUmbrella(TMXTiledMap *map) {
	Size visible_size = Director::getInstance()->getVisibleSize();

	Sprite* umbrella_sprite = Sprite::create("Umbrella4.png");      
	m_umbrella = Umbrella::create();
	m_umbrella->SetPurity(1500);                                   
	m_umbrella->SetTimeLimit(123.0f);
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

void Level4Scene::InitializeBackground() 
{
    Size visible_size = Director::getInstance()->getVisibleSize();

    m_background_1 = Sprite::create("Level246SceneBG1.png");
    m_background_1->setPosition(Point(visible_size.width / 2, visible_size.height / 2));
    this->addChild(m_background_1, 2);

    m_background_2 = Sprite::create("Level246SceneBG2.png");
    m_background_2->setPosition(Point(visible_size.width + visible_size.width / 2, visible_size.height / 2));
    this->addChild(m_background_2, 2);

	auto rain_3 = ParticleSystemQuad::create("rain_3.plist");
	rain_3->retain();
	ParticleBatchNode *batch_3 = ParticleBatchNode::createWithTexture(rain_3->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_3->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		//        sprite->setPosition(ccp(CCRANDOM_0_1()*visibleSize.width,CCRANDOM_0_1()*visibleSize.height));
		rain_drop->SetHurtPurity(/*3*/0);
		rain.pushBack(rain_drop);
	}
	batch_3->addChild(rain_3);
	this->addChild(batch_3, 10);
	rain_3->release();
	
	auto rain_5 = ParticleSystemQuad::create("rain_5.plist");
	rain_5->retain();
	ParticleBatchNode *batch_5 = ParticleBatchNode::createWithTexture(rain_5->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_5->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		//        sprite->setPosition(ccp(CCRANDOM_0_1()*visibleSize.width,CCRANDOM_0_1()*visibleSize.height));
		rain_drop->SetHurtPurity(/*5*/0);
		rain.pushBack(rain_drop);
	}
	batch_5->addChild(rain_5);
	this->addChild(batch_5, 11);
	rain_5->release();

	auto rain_0 = ParticleSystemQuad::create("rain_normal.plist");
	rain_0->retain();
	ParticleBatchNode *batch_0 = ParticleBatchNode::createWithTexture(rain_0->getTexture());
	for(int i = 0;i != 75;i++) {
		auto sprite = Sprite::createWithTexture(batch_0->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		//        sprite->setPosition(ccp(CCRANDOM_0_1()*visibleSize.width,CCRANDOM_0_1()*visibleSize.height));
		rain_drop->SetHurtPurity(0);
		rain.pushBack(rain_drop);
	}
	batch_0->addChild(rain_0);
	this->addChild(batch_0,12);
	rain_0->release();

    auto rain_small = ParticleSystemQuad::create("rain_small.plist");
	rain_small->retain();
	ParticleBatchNode *batch_small = ParticleBatchNode::createWithTexture(rain_small->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_small->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		//        sprite->setPosition(ccp(CCRANDOM_0_1()*visibleSize.width,CCRANDOM_0_1()*visibleSize.height));
		rain_drop->SetHurtPurity(/*-10*/0);
		rain.pushBack(rain_drop);
	}
	batch_small->addChild(rain_small);
	this->addChild(batch_small, 13);
	rain_small->release();
	
	auto rain_10 = ParticleSystemQuad::create("rain_10.plist");
	rain_10->retain();
	ParticleBatchNode *batch_10 = ParticleBatchNode::createWithTexture(rain_10->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_10->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		//        sprite->setPosition(ccp(CCRANDOM_0_1()*visibleSize.width,CCRANDOM_0_1()*visibleSize.height));
		rain_drop->SetHurtPurity(/*10*/0);
		rain.pushBack(rain_drop);
	}
	batch_10->addChild(rain_10);
	this->addChild(batch_10, 15);
	rain_10->release();

	auto rain_20 = ParticleSystemQuad::create("rain_20.plist");
	rain_20->retain();
	ParticleBatchNode *batch_20 = ParticleBatchNode::createWithTexture(rain_20->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_20->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		//        sprite->setPosition(ccp(CCRANDOM_0_1()*visibleSize.width,CCRANDOM_0_1()*visibleSize.height));
		rain_drop->SetHurtPurity(/*20*/0);
		rain.pushBack(rain_drop);
	}
	batch_20->addChild(rain_20);
	this->addChild(batch_20,16);
	rain_20->release();

	auto rain_30 = ParticleSystemQuad::create("rain_30.plist");
	rain_30->retain();
	ParticleBatchNode *batch_30 = ParticleBatchNode::createWithTexture(rain_30->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_30->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		//        sprite->setPosition(ccp(CCRANDOM_0_1()*visibleSize.width,CCRANDOM_0_1()*visibleSize.height));
		rain_drop->SetHurtPurity(/*30*/0);
		rain.pushBack(rain_drop);
	}
	batch_30->addChild(rain_30);
	this->addChild(batch_30,17);
	rain_30->release();

	auto rain_40 = ParticleSystemQuad::create("rain_40.plist");
	rain_40->retain();
	ParticleBatchNode *batch_40 = ParticleBatchNode::createWithTexture(rain_40->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_40->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		//        sprite->setPosition(ccp(CCRANDOM_0_1()*visibleSize.width,CCRANDOM_0_1()*visibleSize.height));
		rain_drop->SetHurtPurity(/*40*/0);
		rain.pushBack(rain_drop);
	}
	batch_40->addChild(rain_40);
	this->addChild(batch_40,18);
	rain_40->release();

	m_level_layer = Sprite::create("Level4SceneTitle.png");
	m_level_layer->setPosition(Point(visible_size.width / 2, visible_size.height / 2));
	this->addChild(m_level_layer,20);
}

void Level4Scene::ChangeScene(float delta) {
	SceneManager::GetInstance()->ChangeScene(SceneManager::level_5_scene);
}