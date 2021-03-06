#include "LevelScene.h"

#include "SimpleAudioEngine.h"
#include "DecoratorSceneFog.h"
#include "LevelSceneFactory.h"
#include "SceneManager.h"


LevelSceneConfig LevelScene::config;
SCENE_INDEX LevelScene::m_current_scene = begin_scene;
DecoratorSceneFog decorator_fog;

Scene* LevelScene::CreateScene(){

	switch(m_current_scene) {
	case begin_scene:
		m_current_scene = level_1_scene;
		break;
	case level_1_scene:
		m_current_scene = level_2_scene;
		break;
	case level_2_scene:
		m_current_scene = level_3_scene;
		break;
	case level_3_scene:
		m_current_scene = level_4_scene;
		break;
	case level_4_scene:
		m_current_scene = level_5_scene;
		break;
	case level_5_scene:
		m_current_scene = level_6_scene;
		break;
	case level_6_scene:
		m_current_scene = end_scene;
		break;
	default:
		break;
	}

	auto scene = Scene::create();
	auto layer = LevelScene::create();
	scene->addChild(layer);

	return scene;
}

bool LevelScene::init() {
	if (!Layer::init()) {
		return false;
	}
	Size visible_size = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	m_next_layer = nullptr;

	LevelSceneFactory level_scene_factory;
	level_scene_factory.createScene(this, m_current_scene, &rain);
	if(m_current_scene == level_6_scene) {
		decorator_fog.AddDecorator("Fog", this);
	}

	//菜单按钮
	auto menu_botton = MenuItemImage::create(
                                           "menu_button_1.png",
                                           "menu_botton_2.png",
                                           CC_CALLBACK_1(LevelScene::MenuButtomCallBack, this));
	Size menu_botton_size = menu_botton->getContentSize();
	menu_botton->setPosition(Vec2(origin.x + visible_size.width - menu_botton_size.width / 3,
                                  origin.y + visible_size.height - menu_botton_size.height / 5.5));

    auto menu = Menu::create(menu_botton, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 21);

	//显示时间
	m_label_time_remaining_1 = Label::createWithTTF("Time Remaining : ","fonts/Avojaloin.ttf",18);
	m_label_time_remaining_1->setTextColor(Color4B(255,255,255,255));
	Size m_label_time_remaining_1_size = m_label_time_remaining_1->getContentSize();
	m_label_time_remaining_1->setPosition(Vec2(origin.x +  m_label_time_remaining_1_size.width / 2,
		                                       origin.y + visible_size.height - m_label_time_remaining_1_size.height / 2));
	m_label_time_remaining_1->setVisible(false);
	this->addChild(m_label_time_remaining_1,22);

	int time_remaining = (int)m_umbrella->GetTimeRemain();
	m_label_time_remaining_2 = Label::createWithTTF(Value(time_remaining ).asString() + "s" ,
		                                            "fonts/Avojaloin.ttf",18);
	m_label_time_remaining_2->setTextColor(Color4B(255,255,255,255));
	Size m_label_time_remaining_2_size = m_label_time_remaining_2->getContentSize();
	m_label_time_remaining_2->setPosition(Vec2(origin.x + m_label_time_remaining_1_size.width + m_label_time_remaining_2_size.width / 2,
		                                       origin.y +  visible_size.height - m_label_time_remaining_1_size.height / 2));
	m_label_time_remaining_2->setVisible(false);
	this->addChild(m_label_time_remaining_2,22);

	//显示Purity
	m_label_purity_1 = Label::createWithTTF("Purity : ","fonts/Avojaloin.ttf",18);
	m_label_purity_1->setTextColor(Color4B(255,255,255,255));
	Size m_label_purity_1_size = m_label_purity_1->getContentSize();
	m_label_purity_1->setPosition(Vec2(origin.x + m_label_time_remaining_1_size.width / 2,
		                               origin.y +  visible_size.height - m_label_time_remaining_1_size.height - m_label_purity_1_size.height / 2));
	m_label_purity_1->setVisible(false);
	this->addChild(m_label_purity_1,22);

	m_label_purity_2 = Label::createWithTTF(Value(m_umbrella->GetPurity()).asString(),"fonts/Avojaloin.ttf",18);
	m_label_purity_2->setTextColor(Color4B(255,255,255,255));
	Size m_label_purity_2_size = m_label_purity_2->getContentSize();
	m_label_purity_2->setPosition(Vec2(origin.x + m_label_time_remaining_1_size.width + m_label_time_remaining_2_size.width / 2,
		                               origin.y +  visible_size.height - m_label_time_remaining_1_size.height - m_label_purity_1_size.height / 2));
	m_label_purity_2->setVisible(false);
	this->addChild(m_label_purity_2,22);

	//胜利场面
	if(m_next_layer == nullptr) {
		m_next_layer = Sprite::create("LevelSceneNext.png");
		m_next_layer->setPosition(Vec2(origin.x + visible_size.width /2,
			                           origin.y + visible_size.height/2));
		m_next_layer->setVisible(false);
		this->addChild(m_next_layer,24);
	}

	//失败场面
	m_over_layer = Sprite::create("LevelSceneOver.png");
	m_over_layer->setPosition(Vec2(origin.x + visible_size.width /2,
		                           origin.y + visible_size.height/2));
	m_over_layer->setVisible(false);
	this->addChild(m_over_layer,26);

	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Blue Six - Music And Wine.mp3",true);

	//关闭操作
	setKeyboardEnabled(false);
	setTouchEnabled(false);

	this->scheduleOnce(schedule_selector(LevelScene::LevelUpdate),3.0f);
	this->schedule(schedule_selector(LevelScene::TimeUpdate),1.0f);
	this->scheduleUpdate();

	return true;
}

//背景跑动 更新时间\Purity
void LevelScene::update(float delta)
{
	Size background_size = m_background_1->getContentSize();
    int pos_x1 = m_background_1->getPositionX();
    int pos_x2 = m_background_2->getPositionX();
    static int speed = 1;

    pos_x1 -= speed;
    pos_x2 -= speed;

    if (pos_x1 <= -background_size.width / 2) {
        pos_x1 = background_size.width + background_size.width / 2;
    }
    if (pos_x2 <= -background_size.width / 2) {
        pos_x2 = background_size.width + background_size.width / 2;
    }

    m_background_1->setPositionX(pos_x1);
    m_background_2->setPositionX(pos_x2);

	if(!rain.empty()) {
		for(auto node:rain) {
			if(node->IsCollideWithUmbrella(m_umbrella)){
				m_umbrella->Hit(node->GetHurtPurity());
			}
		}
	}

	int time_remaining = (int)m_umbrella->GetTimeRemain();
	int purity = m_umbrella->GetPurity();
	if(time_remaining >= 0 && purity >= 0) {
		m_label_time_remaining_2->setString(Value(time_remaining ).asString() + "s" );
		m_label_purity_2->setString(Value(purity).asString());
	}else{
		m_over_layer->setVisible(true);
		scheduleOnce(schedule_selector(LevelScene::TimeUp),5.0f);
	}
	if(m_umbrella->HasGotToDestination()) {
		m_next_layer->setVisible(true);
		scheduleOnce(schedule_selector(LevelScene::ChangeScene),5.0f);
	}
}


void LevelScene::TimeUpdate(float delta) {
	m_umbrella->UpdateTimeRemain();
}

//Level标志消失 游戏开始
void LevelScene::LevelUpdate(float delta) {
	m_level_layer->setVisible(false);
	m_label_time_remaining_1->setVisible(true);
	m_label_time_remaining_2->setVisible(true);
	m_label_purity_1->setVisible(true);
	m_label_purity_2->setVisible(true);

	setKeyboardEnabled(true);
	setTouchEnabled(true);
}

void LevelScene::TimeUp(float delta) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. \nWindows Store Apps do not implement a close button.\n","Alert");
    return;
#endif
    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void LevelScene::MenuButtomCallBack(cocos2d::Ref* ptr_sender) {
	SceneManager::GetInstance()->CoverScene(menu_scene);
}

//雨滴位置调整
void LevelScene::ResetRainDropPosition(cocos2d::Ref* ptr_sender) {
	Size visible_size = Director::getInstance()->getVisibleSize();
	static_cast<Sprite*>(ptr_sender)->setPosition(Point(CCRANDOM_0_1() * visible_size.width,visible_size.height * (1 + CCRANDOM_0_1() )));
}

void LevelScene::AddUmbrella(TMXTiledMap *map) {
	Size visible_size = Director::getInstance()->getVisibleSize();

	//具体Umbrella设置
	//图片
	Sprite* umbrella_sprite = Sprite::create(config.UMBRELLA_IMG[m_current_scene].c_str());     
	m_umbrella = Umbrella::create();
	//Purity
	m_umbrella->SetPurity(config.UMBRELLA_PURITY[m_current_scene]);
	//时间限制
	m_umbrella->SetTimeLimit(config.TIME_LIMIT[m_current_scene]);
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

void LevelScene::InitializeBackground() 
{
    Size visible_size = Director::getInstance()->getVisibleSize();

	//具体背景设置
    m_background_1 = Sprite::create(config.BACKGROUND_IMG_1[m_current_scene].c_str());
    m_background_1->setPosition(Point(visible_size.width / 2, visible_size.height / 2));
    this->addChild(m_background_1, 2);

    m_background_2 = Sprite::create(config.BACKGROUND_IMG_2[m_current_scene].c_str());
    m_background_2->setPosition(Point(visible_size.width + visible_size.width / 2, visible_size.height / 2));
    this->addChild(m_background_2, 2);

	//Level条
	m_level_layer = Sprite::create(config.TITLE_IMG[m_current_scene].c_str());
	m_level_layer->setPosition(Point(visible_size.width / 2, visible_size.height / 2));
	this->addChild(m_level_layer,20);

}

void LevelScene::ChangeScene(float delta) {
	SceneManager::GetInstance()->ChangeScene(config.NEXT_SCENE[m_current_scene]);
}

void LevelScene::FogUpdate(float delta) {
	// 获取current position
	Size fog_size = decorator_fog.background_fog_1->getContentSize();
    int pos_x1 = decorator_fog.background_fog_1->getPositionX();
    int pos_x2 = decorator_fog.background_fog_2->getPositionX();

	// 刷新fog position
    static int speed = 2;
    pos_x1 -= speed;
    pos_x2 -= speed;

    if (pos_x1 <= -fog_size.width / 2) {
        pos_x1 = fog_size.width + fog_size.width / 2;
    }
    if (pos_x2 <= -fog_size.width / 2) {
        pos_x2 = fog_size.width + fog_size.width / 2;
    }

    decorator_fog.background_fog_1->setPositionX(pos_x1);
    decorator_fog.background_fog_2->setPositionX(pos_x2);
}

void LevelScene::SetNextLayer(Sprite* next_layer) {
	m_next_layer = next_layer;
}