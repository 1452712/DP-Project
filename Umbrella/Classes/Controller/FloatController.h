#ifndef __FLOAT_CONTROLLER_H__
#define __FLOAT_CONTROLLER_H__

#include "cocos2d.h"
#include "Controller.h"

USING_NS_CC;

class FloatController : public Controller {
public:
	//初始化
	bool init() ;

	//设置x轴方向速度
	void SetSpeedX(int speed_x);
	//获取x轴方向速度
	int GetSpeedX();
	//设置y轴方向速度
	void SetSpeedY(int speed_y);
	//获取y轴方向速度
	int GetSpeedY();

	//监听事件 更新速度
	void update(float delta);

	CREATE_FUNC(FloatController);
private:
	int m_speed_x;
	int m_speed_y;

	//监听鼠标事件
	void MouseTouchEvent();
	//监听键盘事件
	void KeyBoardTouchEvent();
};

#endif