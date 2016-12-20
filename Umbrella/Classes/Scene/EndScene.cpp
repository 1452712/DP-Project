#include "EndScene.h"
#include "SimpleAudioEngine.h"

Scene* EndScene::CreateScene() { 
	auto scene = Scene::create();
	auto layer = EndScene::create();
	scene->addChild(layer);
	return scene;
}

bool EndScene::init() {
	if (!Layer::init()) {
	    return false;
    }
	Size visible_size = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// ±³¾°
	auto sprite_bk = Sprite::create("EndSceneBG.png");
	sprite_bk->setPosition(Vec2(origin.x + visible_size.width /2,
		                        origin.y + visible_size.height/2));
	this->addChild(sprite_bk,2);

	// ×ÖÄ»
	epilogue = Label::createWithTTF("Luxuria \n"
		                                  "Gula \n"
										  "Avaritia \n"
										  "Acedia \n"
										  "Ira \n"
										  "Invidia \n"
										  "Superbia \n\n"
										  "Everyone is guilty \n"
                                          "To the world \n"
                                          "On its own\n","fonts/Avojaloin.ttf",26);
	epilogue->setTextColor(Color4B(255,255,255,0));
	epilogue->setPosition(Vec2(origin.x + visible_size.width * 0.382,
		                        origin.y + visible_size.height *0.54));
	this->addChild(epilogue,4);

	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Melissa Williamson - Room of Angel.mp3",false);

	this->scheduleUpdate();
	this->scheduleOnce(schedule_selector(EndScene::end),400.0f);

	return true;
}

void EndScene::update(float delta) {
	static int alpha = 0;
	if(alpha <256) {
	epilogue->setTextColor(Color4B(255,255,255,alpha));
	alpha += 1;
	}
}

void EndScene::end(float delta) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. \nWindows Store Apps do not implement a close button.\n","Alert");
    return;
#endif
    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
