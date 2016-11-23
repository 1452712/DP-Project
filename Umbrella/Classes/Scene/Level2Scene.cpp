#include "Level2Scene.h"
#include "LevelScene.h"
#include "Umbrella.h"
#include "FloatController.h"
#include "SceneManager.h"
#include "RainDrop.h"

//////////////////////////////
////LevelXScene///////////////
////注释见Level6Scene//////////
//////////////////////////////

Scene* Level2Scene::CreateScene() {
	auto scene = Scene::create();
	auto layer = Level2Scene::create();
	scene->addChild(layer);

	return scene;
}


void Level2Scene::AddUmbrella(TMXTiledMap *map) {
	Size visible_size = Director::getInstance()->getVisibleSize();

	Sprite* umbrella_sprite = Sprite::create("Umbrella2.png");      
	m_umbrella = Umbrella::create();
	m_umbrella->setContentSize(Size(100,100));
	m_umbrella->SetPurity(1000);                                   
	m_umbrella->SetTimeLimit(183.0f);
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

void Level2Scene::InitializeBackground() 
{
    Size visible_size = Director::getInstance()->getVisibleSize();

    m_background_1 = Sprite::create("Level246SceneBG1.png");
    m_background_1->setPosition(Point(visible_size.width / 2, visible_size.height / 2));
    this->addChild(m_background_1, 2);

    m_background_2 = Sprite::create("Level246SceneBG2.png");
    m_background_2->setPosition(Point(visible_size.width + visible_size.width / 2, visible_size.height / 2));
    this->addChild(m_background_2, 2);
	
	auto particle_system_bk = ParticleSystemQuad::create("rain_normal.plist");
	particle_system_bk->retain();
	ParticleBatchNode *batch = ParticleBatchNode::createWithTexture(particle_system_bk->getTexture());
	batch->addChild(particle_system_bk);
	addChild(batch, 10);
	particle_system_bk->release();
	/*
	auto rain_3 = ParticleSystemQuad::create("rain_3.plist");
	rain_3->retain();
	ParticleBatchNode *batch_3 = ParticleBatchNode::createWithTexture(rain_3->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_3->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->setContentSize(Size(20,20));
		rain_drop->BindSprite(sprite);
		//sprite->setPosition(ccp(CCRANDOM_0_1()*visibleSize.width,CCRANDOM_0_1()*visibleSize.height));
		rain_drop->SetHurtPurity(3);
		rain.pushBack(rain_drop);
	}
	batch_3->addChild(rain_3);
	this->addChild(batch_3, 10);
	rain_3->release();
	*/
	/*
	auto rain_5 = ParticleSystemQuad::create("rain_5.plist");
	rain_5->retain();
	ParticleBatchNode *batch_5 = ParticleBatchNode::createWithTexture(rain_5->getTexture());
	for(int i = 0;i != 250;i++) {
		auto sprite = Sprite::createWithTexture(rain_5->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		//sprite->setPosition(ccp(CCRANDOM_0_1()*visibleSize.width,CCRANDOM_0_1()*visibleSize.height));
		rain_drop->SetHurtPurity(5);
		rain.pushBack(rain_drop);
	}
	batch_5->addChild(rain_5);
	this->addChild(batch_5, 11);
	rain_5->release();
	*/

	/*
	auto rain_0 = ParticleSystemQuad::createWithTotalParticles(1);
	//rain_0->retain();
	rain_0->setTexture(Director::getInstance()->getTextureCache()->addImage(("rain_normal.plist")->getTexture()));
	ParticleBatchNode *batch_0 = ParticleBatchNode::createWithTexture(rain_0->getTexture(),750);
	//SpriteBatchNode *batch_0 = SpriteBatchNode::createWithTexture(rain_0->getTexture());
	for(int i = 0;i != 750;i++) {
		auto sprite = Sprite::createWithTexture(rain_0->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		//sprite->setPosition(ccp(CCRANDOM_0_1()*visibleSize.width,CCRANDOM_0_1()*visibleSize.height));
		rain_drop->SetHurtPurity(/*0*//*10);
		rain.pushBack(rain_drop);
		batch_0->insertChild(rain_0,i);
		//小心内存泄露！！
		//batch_0->appendChild(sprite);
		//batch_0->addSpriteWithoutQuad(sprite,12,0);
	}
	//batch_0->addChild(rain_0);
	this->addChild(batch_0,12);
	//this->addChild(rain_0,12);
	rain_0->release();
	*/
	m_level_layer = Sprite::create("Level2SceneTitle.png");
	m_level_layer->setPosition(Point(visible_size.width / 2, visible_size.height / 2));
	this->addChild(m_level_layer,20);
}

void Level2Scene::ChangeScene(float delta) {
	SceneManager::GetInstance()->ChangeScene(SceneManager::level_3_scene);
}

