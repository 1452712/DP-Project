#include "MenuScene.h"
#include "SceneManager.h"
//#include "cocos-ext.h"
#include "SimpleAudioEngine.h"

Scene* MenuScene::CreateScene() { 
	auto scene = Scene::create();
	auto layer = MenuScene::create();
	scene->addChild(layer);
	return scene;
}

bool MenuScene::init() {
    if (!Layer::init()) {
	    return false;
    }
	Size visible_size = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite_bk = Sprite::create("MenuSceneBG.png");
	sprite_bk->setPosition(Vec2(origin.x + visible_size.width /2,
		                        origin.y + visible_size.height/2));
	this->addChild(sprite_bk,2);

	auto back_botton = MenuItemImage::create("back_button_1.png",
                                             "back_button_2.png",
                                             CC_CALLBACK_1(MenuScene::MenuBottomCallBack, this));
	Size botton_size_1 = back_botton->getContentSize();
	back_botton->setPosition(Vec2(origin.x + visible_size.width - botton_size_1.width/3,
                                origin.y + visible_size.height - botton_size_1.height/3));
	auto menu_1 = Menu::create(back_botton, NULL);
    menu_1->setPosition(Vec2::ZERO);
    this->addChild(menu_1, 4);
	/*
	//Ðèdebug
	ControlSlider *slider = ControlSlider::create("slider_background.png","slider_progress.png","slider_thumb.png");  
	//ÐèÏ¸µ÷
    slider->setMinimumValue(0.0f); 
    slider->setMaximumValue(5.0f); 
    slider->setPosition(Vec2(origin.x + visible_size.width * 0.382,
		                     origin.y + visible_size.height * 0.8));
    slider->setValue(300);  
    slider->addTargetWithActionForControlEvents(this,cccontrol_selector(MenuScene::SliderChange),Control::EventType::VALUE_CHANGED);  
    //this->addChild(slider,6);
	*/
	auto exit_bottom = MenuItemImage::create("CloseSelected.png",
                                             "CloseNormal.png",
                                             CC_CALLBACK_1(MenuScene::ExitBottomCallBack, this));
	Size bottom_size_2 = exit_bottom->getContentSize();

	exit_bottom->setPosition(Vec2(origin.x + visible_size.width * 0.2,
                                origin.y + visible_size.height * 0.155));
	auto menu_2 = Menu::create(exit_bottom, NULL);
    menu_2->setPosition(Vec2::ZERO);
    this->addChild(menu_2, 8);

	return true;
}
/*
void MenuScene::SliderChange(Ref* ptr_sender,Control::EventType control_event)  
{  
    ControlSlider* slider = (ControlSlider*)ptr_sender;  
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->setEffectsVolume(slider->getValue());
} 
*/
void MenuScene::MenuBottomCallBack(cocos2d::Ref *ptr_sender) {
	SceneManager::GetInstance()->RevertScene();
}

void MenuScene::ExitBottomCallBack(cocos2d::Ref *ptr_sender) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. \nWindows Store Apps do not implement a close button.\n","Alert");
    return;
#endif
    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}