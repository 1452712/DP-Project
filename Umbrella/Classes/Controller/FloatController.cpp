#include "FloatController.h"

bool FloatController::init() {
	m_speed_x = 0 ;
	m_speed_y = 0 ;

	MouseTouchEvent();
	KeyBoardTouchEvent();
	this->scheduleUpdate();

	return true;
}

void FloatController::SetSpeedX(int speed_x) {
	m_speed_x = speed_x;
}

int FloatController::GetSpeedX() {
	return m_speed_x;
}

void FloatController::SetSpeedY(int speed_y) {
	m_speed_y = speed_y;
}

int FloatController::GetSpeedY() {
	return m_speed_y;
}

void FloatController::update(float delta) {
	if(m_controller_listener == nullptr) {
		return ;
	}

	//����λ��
	Point current_pos = m_controller_listener->GetTagPosition();
	//�ƶ����
	current_pos += Point(m_speed_x,m_speed_y);
	m_controller_listener->SetTagPosition(current_pos.x,current_pos.y);
}

void FloatController::MouseTouchEvent() {
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [this](Touch *touch, Event *event) {
		return true; 
	};

	listener->onTouchMoved = [this](Touch *touch, Event *event) {
		//��Ļ��С
		Size visible_size = Director::getInstance()->getVisibleSize();

		//�����λ��
		//convertToGL��bug ����
		//Point touch_pos = Director::getInstance()->convertToGL(touch->getLocationInView());
		Point touch_pos = touch->getLocation();
		//Userλ��
		Point pos = m_controller_listener->GetTagPosition();

		//����touch_pos
		if(pos.x > visible_size.width / 2) {
			touch_pos.x = touch_pos.x + pos.x - visible_size.width / 2;
		}

		int speed_x_temp = GetSpeedX() , speed_y_temp = GetSpeedY();
		//��ȡ�����������ٶ�
		speed_x_temp += (touch_pos.x >= pos.x) ? 10 : -10;
		speed_y_temp += (touch_pos.y >= pos.y) ? 1 : (-1);
		speed_x_temp = (speed_x_temp > 10) ? 10 : speed_x_temp;
		speed_y_temp = (speed_y_temp > 5) ? 5 : speed_y_temp;
		speed_x_temp = (speed_x_temp < -10) ? -10 : speed_x_temp;
		speed_y_temp = (speed_y_temp < -5) ? -5 : speed_y_temp;

		//�趨�ٶ�
		SetSpeedX(speed_x_temp);
		SetSpeedY(speed_y_temp);
	};

	listener->onTouchEnded = [this](Touch *touch, Event *event) {
		//(��ѡ)����Ч��
		//if(m_speed_x != 0) m_speed_x += (m_speed_x > 0) ? -1 : 1 ;
		//if(m_speed_y != 0) m_speed_y += (m_speed_y > 0) ? -1 : 1 ;
		SetSpeedX(0);
		SetSpeedY(0);
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void FloatController::KeyBoardTouchEvent() {
	auto listener = EventListenerKeyboard::create();

	//�������Ҽ��жϼ��ٷ���
	listener->onKeyPressed = [this](EventKeyboard::KeyCode key_code, Event *event) {
		int speed_x_temp = GetSpeedX() , speed_y_temp = GetSpeedY();
		if (key_code == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
			speed_x_temp -= 10;
			speed_x_temp = (speed_x_temp < -10) ? -10 : speed_x_temp;
		}
		if (key_code == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
			speed_x_temp += 10;
			speed_x_temp = (speed_x_temp > 10) ? 10 : speed_x_temp;
		}
		if (key_code == EventKeyboard::KeyCode::KEY_UP_ARROW) {
			speed_y_temp += 5;
			speed_y_temp = (speed_y_temp > 5) ? 5 : speed_y_temp;		
		}
		if (key_code == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
			speed_y_temp -= 5;
			speed_y_temp = (speed_y_temp < -5) ? -5 : speed_y_temp;
		}
		SetSpeedX(speed_x_temp);
		SetSpeedY(speed_y_temp);
	};

	listener->onKeyReleased = [this](EventKeyboard::KeyCode key_code, Event *event) {
		//(��ѡ)����Ч��
		//���� �����һ��Ϊ���� �ڶ���Ϊ����
		/*		
		int speed_x_temp = GetSpeedX() , speed_y_temp = GetSpeedY();
		if (key_code == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
		speed_x_temp += 1;
		speed_x_temp = (speed_x_temp <= 0) ? 0 : speed_x_temp;
		}
		if (key_code == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
		speed_x_temp -= 1;
		speed_x_temp = (speed_x_temp >= 0) ? 0 : speed_x_temp;
		}
		if (key_code == EventKeyboard::KeyCode::KEY_UP_ARROW) {
		speed_y_temp -= 1;
		speed_y_temp = (speed_y_temp <= 0) ? 0 : speed_y_temp;		
		}
		if (key_code == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
		speed_y_temp += 1;
		speed_y_temp = (speed_y_temp >= 0) ? 0 : speed_y_temp;
		}
		SetSpeedX(speed_x_temp);
		SetSpeedY(speed_y_temp);
		*/
		SetSpeedX(0);
		SetSpeedY(0);
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}