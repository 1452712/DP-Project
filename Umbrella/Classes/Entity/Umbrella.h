#ifndef __UMBRELLA_H__
#define __UMBRELLA_H__

#include "cocos2d.h"
#include "..\Controller\Controller.h"
#include "..\Controller\ControllerListener.h"
USING_NS_CC;

class Umbrella:public Node,public ControllerListener {
public:
	//初始化
	virtual bool init();
	//绑定Umbrella精灵
	void BindSprite(Sprite *sprite);

	//Purity
	//设定初始值
    void SetPurity(int purity);
	//获取实时值
	int GetPurity();
	//雨滴伤害
	void Hit(int dt_purity);

	//Time Remaining
	//设定初始值
	void SetTimeLimit(float time);
	//实时更新
	void UpdateTimeRemain();
	//获取剩余时间
	float GetTimeRemain();

	//判断:是否抵达终点
	bool HasGotToDestination();

	//绑定监听者
	void SetController(Controller *controller);
	
	//控制Umbrella
	virtual void SetTagPosition(int x,int y);
	virtual Point GetTagPosition();

	//控制画面
	void SetViewPointByUmbrella();

	//绑定地图
	void SetTiledMap(TMXTiledMap *map);
	CREATE_FUNC(Umbrella);
private:
	Sprite *m_sprite;
	int m_purity;
	float m_time;
	//正在反弹
	bool is_bouncing;
	bool get_destination;
	Controller *m_controller;

	TMXTiledMap *m_map;
	//标记层
	TMXLayer *meta;

	//cocos2d-x坐标转为map坐标
	Point PositionTransformTileCoordinate(Point position);
};

#endif