#include"Umbrella.h"

bool Umbrella::init() {
	is_bouncing = false;
	get_destination = false;
	return true;
}

void Umbrella::BindSprite(Sprite *sprite) {
	m_sprite = sprite;
	this->addChild(m_sprite);
}

void Umbrella::SetPurity(int purity) {
	m_purity = purity;
}

int Umbrella::GetPurity() {
	return m_purity;
}

void Umbrella::Hit(int dt_purity) {
	m_purity -= dt_purity;
}

void Umbrella::SetTimeLimit(float time) {
	m_time = time;
}

void Umbrella::UpdateTimeRemain() {
	m_time -= 1.0f;
}

float Umbrella::GetTimeRemain() {
	return m_time;
}

bool Umbrella::HasGotToDestination() {
	return get_destination;
}

void Umbrella::SetController(Controller *controller) {
	m_controller = controller; 
	m_controller->SetControllerListener(this);
}

void Umbrella::SetTagPosition(int x,int y) {
	Size sprite_size = m_sprite->getContentSize();

	//地图大小
	Size map_tile_num = m_map->getMapSize();
	Size tile_size = m_map->getTileSize();
	Size map_size = Size(map_tile_num.width * tile_size.width,
		                 map_tile_num.height * tile_size.height);

	int x_temp = x , y_temp = y;
	x_temp = (x_temp > 0) ?x_temp : 0;
	y_temp = (y_temp > 0) ?y_temp : 0;
	x_temp = (x_temp < map_size.width) ? x_temp : map_size.width;
	y_temp = (y_temp < map_size.height) ? y_temp : map_size.height;

	//伞面位置
	int x_temp_temp = (x_temp + sprite_size.width < map_size.width ) ? x_temp + sprite_size.width : map_size.width;
	int y_temp_temp = (y_temp - 32.0f > 0 )? y_temp - 32.0f : 0; 
	//前方位置
	Point destination_pos = Point(x_temp_temp ,y_temp_temp);
	Point tiled_map_pos = PositionTransformTileCoordinate(Point(destination_pos.x,destination_pos.y) );
	
	//判断前方情况
	int tile_gid = meta->getTileGIDAt(tiled_map_pos);
	if(tile_gid != 0) {
		Value tile_property = m_map->getPropertiesForGID(tile_gid);
		ValueMap map_property = tile_property.asValueMap();

		//抵达终点
		if(map_property.find("destination_tile") != map_property.end() ) {
			Value property_temp = map_property.at("destination_tile");
			if(property_temp.asString() == "true" && m_time >= 0.0f && m_purity >=0) {
				get_destination = true;
			}	
		}

		//撞击障碍物
		if(map_property.find("obstacle_tile") != map_property.end() ) {
            Value property_temp = map_property.at("obstacle_tile");
            if (property_temp.asString() == "true"&& is_bouncing == false) {
                is_bouncing = true;
				//减速反弹
                auto move_by = MoveBy::create(0.1f, Point(-64, 0));
				auto move_ease = EaseExponentialIn::create(move_by->clone());
                CallFunc *call_function = CallFunc::create([&]() {
                    is_bouncing = false;
					x_temp = 0;y_temp = 0;
                });
                auto bouncing = Sequence::create(move_ease, call_function, NULL);
                this->runAction(bouncing);
            }
        }
    }

	this->setPosition(Point(x_temp,y_temp));
	//主角视角
    SetViewPointByUmbrella();
}

Point Umbrella::GetTagPosition() {
	return getPosition();
}

void Umbrella::SetViewPointByUmbrella() {
	if (m_sprite == NULL) {
		return;
	}
	Layer *parent = (Layer*)getParent();

	//地图大小
	Size map_tile_num = m_map->getMapSize();
	Size tile_size = m_map->getTileSize();
	Size map_size = Size(map_tile_num.width * tile_size.width,
		                 map_tile_num.height * tile_size.height);
	
	Size visible_size = Director::getInstance()->getVisibleSize();

	Point sprite_pos = getPosition();
   
	//保证地图位置不越界
	float x = (sprite_pos.x > visible_size.width / 2 ) ? sprite_pos.x : visible_size.width / 2;
	float y = (sprite_pos.y > visible_size.height / 2 ) ? sprite_pos.y : visible_size.height / 2;
	x = ( x > map_size.width - visible_size.width / 2) ? 
		map_size.width - visible_size.width / 2 : x;
	y = ( y > map_size.height - visible_size.height / 2) ? 
		map_size.height - visible_size.height / 2 : y;
    Point destination_pos = Point( x , y );
    Point center_pos = Point(visible_size.width / 2, visible_size.height / 2);
    Point view_pos = center_pos - destination_pos;

	//调整地图位置
    parent->setPosition(view_pos);
}

void Umbrella::SetTiledMap(TMXTiledMap *map) {
	m_map = map;
	this->meta = m_map->getLayer("meta");
	this->meta->setVisible(false);
}
	
Point Umbrella::PositionTransformTileCoordinate(Point position) {
    Size map_tile_num = m_map->getMapSize();
	Size tile_size = m_map->getTileSize();

    int x = position.x / tile_size.width;
	//450px:画面高度
    int y = (450 - position.y) / tile_size.height;

    x = x ? x - 1 : x;
	y = y ? y - 1 : y;

    return Point(x, y);
}