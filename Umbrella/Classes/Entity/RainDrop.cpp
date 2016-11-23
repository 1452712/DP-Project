#include "RainDrop.h"

bool RainDrop::init() {
	m_hurt_purity = 0;
	return true;
}

Sprite* RainDrop::GetSprite() {
	return m_sprite;
}

void RainDrop::BindSprite(Sprite *sprite) {
	m_sprite = sprite;
	this->addChild(m_sprite);
}

bool RainDrop::IsCollideWithUmbrella(Umbrella *umbrella) {
	Rect umbrella_rect = umbrella->getBoundingBox();
	Point pos_umbrella = umbrella->getPosition ();
	Size visible_size = Director::getInstance()->getVisibleSize();

    Point rain_drop_pos = m_sprite->getPosition();
	//计算雨滴实际位置
	if(pos_umbrella.x >  visible_size.width) {
		rain_drop_pos.x = rain_drop_pos.x + pos_umbrella.x - visible_size.width;
	}

	//判断雨滴与Umbrella是否相交
    return umbrella_rect.containsPoint(rain_drop_pos);
}

void RainDrop::SetHurtPurity(int hurt_purity) {
	m_hurt_purity = hurt_purity;
}

int RainDrop::GetHurtPurity() {
	return m_hurt_purity;
}