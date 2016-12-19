#include <string>

#include "LevelSceneFactory.h"

LevelScene* LevelSceneFactory::createScene(LevelScene* scene, SCENE_INDEX scene_type,Vector<RainDrop*>* rain) {

	//加载地图
	TMXTiledMap *map = TMXTiledMap::create("map.tmx");
	scene->addChild(map,4);

	//绑定Umbrella
	scene->AddUmbrella(map);
	//具体初始化背景
	scene->InitializeBackground();

	//添加雨滴
	AddRainDrops(scene, scene_type, rain);
	if(scene_type == level_6_scene){
		AddEndScene(scene);
	}

	return scene;
}

LevelScene* LevelSceneFactory::AddRainDrops(LevelScene* scene, SCENE_INDEX scene_type, Vector<RainDrop*>* rain) {
	if(scene_type == level_2_scene) {
		//场景2雨滴
		AddRainDropsS2(scene, rain);

	}else if(scene_type == level_3_scene){
		//场景3雨滴
		AddRainDropsS3(scene, rain);

	}else if(scene_type == level_4_scene){
		//场景4雨滴
		AddRainDropsS4(scene, rain);

	}else if(scene_type == level_5_scene){
		//场景5雨滴
		AddRainDropsS5(scene, rain);

	}else if(scene_type == level_6_scene){
		//场景6雨滴
		AddRainDropsS6(scene, rain);
	}

	return scene;
}

LevelScene* LevelSceneFactory::AddRainDropsS2(LevelScene* scene,Vector<RainDrop*>* rain){
	auto particle_system_bk = ParticleSystemQuad::create("rain_normal.plist");
	particle_system_bk->retain();
	ParticleBatchNode *batch = ParticleBatchNode::createWithTexture(particle_system_bk->getTexture());
	batch->addChild(particle_system_bk);
	scene->addChild(batch, 10);
	particle_system_bk->release();
}

LevelScene* LevelSceneFactory::AddRainDropsS3(LevelScene* scene,Vector<RainDrop*>* rain){
	auto rain_3 = ParticleSystemQuad::create("rain_3.plist");
	rain_3->retain();
	ParticleBatchNode *batch_3 = ParticleBatchNode::createWithTexture(rain_3->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_3->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(/*3*/0);
		rain->pushBack(rain_drop);
	}
	batch_3->addChild(rain_3);
	scene->addChild(batch_3, 10);
	rain_3->release();

	auto rain_5 = ParticleSystemQuad::create("rain_5.plist");
	rain_5->retain();
	ParticleBatchNode *batch_5 = ParticleBatchNode::createWithTexture(rain_5->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_5->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(/*5*/0);
		rain->pushBack(rain_drop);
	}
	batch_5->addChild(rain_5);
	scene->addChild(batch_5, 11);
	rain_5->release();

	auto rain_0 = ParticleSystemQuad::create("rain_normal.plist");
	rain_0->retain();
	ParticleBatchNode *batch_0 = ParticleBatchNode::createWithTexture(rain_0->getTexture());
	for(int i = 0;i != 75;i++) {
		auto sprite = Sprite::createWithTexture(batch_0->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(0);
		rain->pushBack(rain_drop);
	}
	batch_0->addChild(rain_0);
	scene->addChild(batch_0,12);
	rain_0->release();
}

LevelScene* LevelSceneFactory::AddRainDropsS4(LevelScene* scene,Vector<RainDrop*>* rain){
	auto rain_3 = ParticleSystemQuad::create("rain_3.plist");
	rain_3->retain();
	ParticleBatchNode *batch_3 = ParticleBatchNode::createWithTexture(rain_3->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_3->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(/*3*/0);
		rain->pushBack(rain_drop);
	}
	batch_3->addChild(rain_3);
	scene->addChild(batch_3, 10);
	rain_3->release();

	auto rain_5 = ParticleSystemQuad::create("rain_5.plist");
	rain_5->retain();
	ParticleBatchNode *batch_5 = ParticleBatchNode::createWithTexture(rain_5->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_5->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(/*5*/0);
		rain->pushBack(rain_drop);
	}
	batch_5->addChild(rain_5);
	scene->addChild(batch_5, 11);
	rain_5->release();

	auto rain_0 = ParticleSystemQuad::create("rain_normal.plist");
	rain_0->retain();
	ParticleBatchNode *batch_0 = ParticleBatchNode::createWithTexture(rain_0->getTexture());
	for(int i = 0;i != 75;i++) {
		auto sprite = Sprite::createWithTexture(batch_0->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(0);
		rain->pushBack(rain_drop);
	}
	batch_0->addChild(rain_0);
	scene->addChild(batch_0,12);
	rain_0->release();

	auto rain_small = ParticleSystemQuad::create("rain_small.plist");
	rain_small->retain();
	ParticleBatchNode *batch_small = ParticleBatchNode::createWithTexture(rain_small->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_small->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(/*-10*/0);
		rain->pushBack(rain_drop);
	}
	batch_small->addChild(rain_small);
	scene->addChild(batch_small, 13);
	rain_small->release();

	auto rain_10 = ParticleSystemQuad::create("rain_10.plist");
	rain_10->retain();
	ParticleBatchNode *batch_10 = ParticleBatchNode::createWithTexture(rain_10->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_10->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(/*10*/0);
		rain->pushBack(rain_drop);
	}
	batch_10->addChild(rain_10);
	scene->addChild(batch_10, 15);
	rain_10->release();

	auto rain_20 = ParticleSystemQuad::create("rain_20.plist");
	rain_20->retain();
	ParticleBatchNode *batch_20 = ParticleBatchNode::createWithTexture(rain_20->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_20->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(/*20*/0);
		rain->pushBack(rain_drop);
	}
	batch_20->addChild(rain_20);
	scene->addChild(batch_20,16);
	rain_20->release();

	auto rain_30 = ParticleSystemQuad::create("rain_30.plist");
	rain_30->retain();
	ParticleBatchNode *batch_30 = ParticleBatchNode::createWithTexture(rain_30->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_30->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(/*30*/0);
		rain->pushBack(rain_drop);
	}
	batch_30->addChild(rain_30);
	scene->addChild(batch_30,17);
	rain_30->release();

	auto rain_40 = ParticleSystemQuad::create("rain_40.plist");
	rain_40->retain();
	ParticleBatchNode *batch_40 = ParticleBatchNode::createWithTexture(rain_40->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_40->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(/*40*/0);
		rain->pushBack(rain_drop);
	}
	batch_40->addChild(rain_40);
	scene->addChild(batch_40,18);
	rain_40->release();
}

LevelScene* LevelSceneFactory::AddRainDropsS5(LevelScene* scene,Vector<RainDrop*>* rain){
	Size visible_size = Director::getInstance()->getVisibleSize();

	auto rain_3 = ParticleSystemQuad::create("rain_3.plist");
	rain_3->retain();
	ParticleBatchNode *batch_3 = ParticleBatchNode::createWithTexture(rain_3->getTexture(),25);
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(rain_3->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(0);
		rain->pushBack(rain_drop);
		sprite->setAnchorPoint(Point(CCRANDOM_0_1()*visible_size.width,CCRANDOM_0_1() *visible_size.height));
	}
	batch_3->addChild(rain_3);
	scene->addChild(batch_3, 10);
	rain_3->release();
	
	auto rain_5 = ParticleSystemQuad::create("rain_5.plist");
	rain_5->retain();
	ParticleBatchNode *batch_5 = ParticleBatchNode::createWithTexture(rain_5->getTexture(),25);
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(rain_5->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(0);
		rain->pushBack(rain_drop);
	}
	batch_5->addChild(rain_5);
	scene->addChild(batch_5, 11);
	rain_5->release();

	auto rain_0 = ParticleSystemQuad::create("rain_normal.plist");
	rain_0->retain();
	ParticleBatchNode *batch_0 = ParticleBatchNode::createWithTexture(rain_0->getTexture());
	for(int i = 0;i != 500;i++) {
		auto sprite = Sprite::createWithTexture(rain_0->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(0);
		rain->pushBack(rain_drop);
	}
	batch_0->addChild(rain_0);
	scene->addChild(batch_0,12);
	rain_0->release();

    auto rain_small = ParticleSystemQuad::create("rain_small.plist");
	rain_small->retain();
	ParticleBatchNode *batch_small = ParticleBatchNode::createWithTexture(rain_small->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_small->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(0);
		rain->pushBack(rain_drop);
	}
	batch_small->addChild(rain_small);
	scene->addChild(batch_small, 13);
	rain_small->release();
	
	auto rain_10 = ParticleSystemQuad::create("rain_10.plist");
	rain_10->retain();
	ParticleBatchNode *batch_10 = ParticleBatchNode::createWithTexture(rain_10->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_10->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(0);
		rain->pushBack(rain_drop);
	}
	batch_10->addChild(rain_10);
	scene->addChild(batch_10, 15);
	rain_10->release();

	auto rain_20 = ParticleSystemQuad::create("rain_20.plist");
	rain_20->retain();
	ParticleBatchNode *batch_20 = ParticleBatchNode::createWithTexture(rain_20->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_20->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(0);
		rain->pushBack(rain_drop);
	}
	batch_20->addChild(rain_20);
	scene->addChild(batch_20,16);
	rain_20->release();

	auto rain_30 = ParticleSystemQuad::create("rain_30.plist");
	rain_30->retain();
	ParticleBatchNode *batch_30 = ParticleBatchNode::createWithTexture(rain_30->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_30->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(0);
		rain->pushBack(rain_drop);
	}
	batch_30->addChild(rain_30);
	scene->addChild(batch_30,17);
	rain_30->release();
	
	auto rain_40 = ParticleSystemQuad::create("rain_40.plist");
	rain_40->retain();
	ParticleBatchNode *batch_40 = ParticleBatchNode::createWithTexture(rain_40->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_40->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(0);
		rain->pushBack(rain_drop);
	}
	batch_40->addChild(rain_40);
	scene->addChild(batch_40,18);
	rain_40->release();
}

LevelScene* LevelSceneFactory::AddRainDropsS6(LevelScene* scene,Vector<RainDrop*>* rain){

	auto rain_3 = ParticleSystemQuad::create("rain_3.plist");
	rain_3->retain();
	ParticleBatchNode *batch_3 = ParticleBatchNode::createWithTexture(rain_3->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_3->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(0);
		rain->pushBack(rain_drop);
	}
	batch_3->addChild(rain_3);
	scene->addChild(batch_3, 10);
	rain_3->release();
	
	auto rain_5 = ParticleSystemQuad::create("rain_5.plist");
	rain_5->retain();
	ParticleBatchNode *batch_5 = ParticleBatchNode::createWithTexture(rain_5->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_5->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(0);
		rain->pushBack(rain_drop);
	}
	batch_5->addChild(rain_5);
	scene->addChild(batch_5, 11);
	rain_5->release();

	auto rain_0 = ParticleSystemQuad::create("rain_normal.plist");
	rain_0->retain();
	ParticleBatchNode *batch_0 = ParticleBatchNode::createWithTexture(rain_0->getTexture());
	for(int i = 0;i != 75;i++) {
		auto sprite = Sprite::createWithTexture(batch_0->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(0);
		rain->pushBack(rain_drop);
	}
	batch_0->addChild(rain_0);
	scene->addChild(batch_0,12);
	rain_0->release();

    auto rain_small = ParticleSystemQuad::create("rain_small.plist");
	rain_small->retain();
	ParticleBatchNode *batch_small = ParticleBatchNode::createWithTexture(rain_small->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_small->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(0);
		rain->pushBack(rain_drop);
	}
	batch_small->addChild(rain_small);
	scene->addChild(batch_small, 13);
	rain_small->release();

	auto rain_10 = ParticleSystemQuad::create("rain_10.plist");
	rain_10->retain();
	ParticleBatchNode *batch_10 = ParticleBatchNode::createWithTexture(rain_10->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_10->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(0);
		rain->pushBack(rain_drop);
	}
	batch_10->addChild(rain_10);
	scene->addChild(batch_10, 15);
	rain_10->release();

	auto rain_20 = ParticleSystemQuad::create("rain_20.plist");
	rain_20->retain();
	ParticleBatchNode *batch_20 = ParticleBatchNode::createWithTexture(rain_20->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_20->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(0);
		rain->pushBack(rain_drop);
	}
	batch_20->addChild(rain_20);
	scene->addChild(batch_20,16);
	rain_20->release();

	auto rain_30 = ParticleSystemQuad::create("rain_30.plist");
	rain_30->retain();
	ParticleBatchNode *batch_30 = ParticleBatchNode::createWithTexture(rain_30->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_30->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(0);
		rain->pushBack(rain_drop);
	}
	batch_30->addChild(rain_30);
	scene->addChild(batch_30,17);
	rain_30->release();

	auto rain_40 = ParticleSystemQuad::create("rain_40.plist");
	rain_40->retain();
	ParticleBatchNode *batch_40 = ParticleBatchNode::createWithTexture(rain_40->getTexture());
	for(int i = 0;i != 25;i++) {
		auto sprite = Sprite::createWithTexture(batch_40->getTexture());
		RainDrop *rain_drop = RainDrop::create();
		rain_drop->BindSprite(sprite);
		rain_drop->SetHurtPurity(0);
		rain->pushBack(rain_drop);
	}
	batch_40->addChild(rain_40);
	scene->addChild(batch_40,18);
	rain_40->release();
}

LevelScene* LevelSceneFactory::AddEndScene(LevelScene* scene){

	Size visible_size = Director::getInstance()->getVisibleSize();

	//特殊的结束场面
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Sprite* next_layer = Sprite::create("LevelSceneFinal.png");
	next_layer->setPosition(Vec2(origin.x + visible_size.width /2,
		                           origin.y + visible_size.height/2));
	next_layer->setVisible(false);
	scene->SetNextLayer(next_layer);
	scene->addChild(next_layer,24);
}