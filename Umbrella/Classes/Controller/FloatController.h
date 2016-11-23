#ifndef __FLOAT_CONTROLLER_H__
#define __FLOAT_CONTROLLER_H__

#include "cocos2d.h"
#include "Controller.h"

USING_NS_CC;

class FloatController : public Controller {
public:
	//��ʼ��
	bool init() ;

	//����x�᷽���ٶ�
	void SetSpeedX(int speed_x);
	//��ȡx�᷽���ٶ�
	int GetSpeedX();
	//����y�᷽���ٶ�
	void SetSpeedY(int speed_y);
	//��ȡy�᷽���ٶ�
	int GetSpeedY();

	//�����¼� �����ٶ�
	void update(float delta);

	CREATE_FUNC(FloatController);
private:
	int m_speed_x;
	int m_speed_y;

	//��������¼�
	void MouseTouchEvent();
	//���������¼�
	void KeyBoardTouchEvent();
};

#endif