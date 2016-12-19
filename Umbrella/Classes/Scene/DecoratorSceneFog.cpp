#include "DecoratorSceneFog.h"

void DecoratorSceneFog::AddDecorator(std::string decorator, LevelScene* scene){
	Size visible_size = Director::getInstance()->getVisibleSize();

	//ÎíµÄÍ¼Æ¬
	background_fog_1 = Sprite::create("Level6SceneFog1.png");
	background_fog_1->setPosition(Point(visible_size.width / 2, visible_size.height / 2));
    scene->addChild(background_fog_1, 19);

	background_fog_2 = Sprite::create("Level6SceneFog2.png");
	background_fog_2->setPosition(Point(visible_size.width + visible_size.width / 2, visible_size.height / 2));
    scene->addChild(background_fog_2, 19);

	//ÎíµÄÅÜ¶¯
	scene->schedule(schedule_selector(LevelScene::FogUpdate),1.0f/60.0f);

}

