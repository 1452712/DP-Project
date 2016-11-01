#include "BeginScene.h"
#include "SimpleAudioEngine.h"
#include "SceneManager.h"

Scene* BeginScene::CreateScene() { 
	auto scene = Scene::create();
	auto layer = BeginScene::create();
	scene->addChild(layer);
	return scene;
}

bool BeginScene::init() {
	if (!Layer::init()) {
		return false;
	}

	Size visible_size = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite_bk = Sprite::create("BeginSceneBG1.png");
	sprite_bk->setPosition(Vec2(origin.x + visible_size.width /2,
		origin.y + visible_size.height/2));
	this->addChild(sprite_bk,2);

	//下雨背景
	//需要修改以提高帧率
	auto particle_system_bk = ParticleSystemQuad::create("BeginScene_BG2.plist");
	particle_system_bk->retain();
	ParticleBatchNode *batch = ParticleBatchNode::createWithTexture(particle_system_bk->getTexture());
	batch->addChild(particle_system_bk);
	addChild(batch, 4);
	particle_system_bk->release();


	//主标题
	auto title = Label::createWithTTF("Umbrella","fonts/papyrusletplain-1.0.ttf",48);
	title->setTextColor(Color4B(255,255,255,255));
	title->setPosition(Vec2(origin.x + visible_size.width * 0.3,
		origin.y + visible_size.height* 0.618));
	this->addChild(title,6);

	//开始按钮
	auto start = Label::createWithTTF("start","fonts/papyrusletplain-1.0.ttf",36);
	start->setTextColor(Color4B(255,255,255,255));
	start->setPosition(Vec2(origin.x + visible_size.width * 0.55,
		origin.y + visible_size.height* 0.485));
	this->addChild(start,6);

	auto start_bottom = MenuItemImage::create(
		"start_button_1.png",
		"start_button_2.png",
		CC_CALLBACK_1(BeginScene::StartButtomCallBack, this));
	start_bottom->setPosition(Vec2(origin.x + visible_size.width * 0.68 ,
		origin.y + visible_size.height * 0.50));

	//菜单按钮
	auto menu_1 = Menu::create(start_bottom, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1, 8);

	auto menu_bottom = MenuItemImage::create(
		"menu_button_1.png",
		"menu_button_2.png",
		CC_CALLBACK_1(BeginScene::MenuButtomCallBack, this));
	Size menu_bottom_size = menu_bottom->getContentSize();
	menu_bottom->setPosition(Vec2(origin.x + visible_size.width - menu_bottom_size.width / 2.5,
		origin.y + visible_size.height - menu_bottom_size.height / 4));

	auto menu_2 = Menu::create(menu_bottom, NULL);
	menu_2->setPosition(Vec2::ZERO);
	this->addChild(menu_2, 10);

	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Telepopmusik - Breathe.mp3",true);

	return true;
}

void BeginScene::StartButtomCallBack(cocos2d::Ref* ptr_sender) {
	SceneManager::GetInstance()->ChangeScene(SceneManager::level_1_scene);
}

void BeginScene::MenuButtomCallBack(cocos2d::Ref* ptr_sender) {
	SceneManager::GetInstance()->CoverScene(SceneManager::menu_scene);
}






