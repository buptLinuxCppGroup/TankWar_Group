#pragma once
#include <string>
#include <ctime>
#include <irrlicht.h>
using namespace irr;
class TConfig
{
private:
	static core::vector3df TANKpos_MINUS_CAMERApos;
public:

	static bool showflag;

	//坦克mesh和texture路径
	static std::string TANK_3D_MESH_DIR;
	static std::string TANK_3D_TEXTURE_DIR;

	//枪mesh和texture路径
	static std::string GUN1_3D_MESH_DIR;
	static std::string GUN1_3D_TEXTURE_DIR;

	//导弹mesh和texture路径
	static std::string MISSILE_3D_MESH_DIR;
	static std::string MISSILE_3D_TEXTURE_DIR;

	//导弹速度
	static f32 MISSILE_SPEED;

	//导弹发射间隔时间和导弹存在时间
	static double MISSILE_INTERVAL_TIME;
	static int MISSILE_EXIST_TIME;

	//设置导弹与敌方坦克的命中距离
	const static int MISSILE_TANK_DISTANCE = 400;

	//炮弹伤害
	static int MISSILE_DAMAGE1;
	const static int MISSILE_DAMAGE_AROUND = 400;

	//炮弹载入种类
	static int MISSILE_KIND;

	//坦克血上限下限
	const static int MISSILE_HP_UP = 8000;
	const static int MISSILE_HP_DOWN = 5000;

	//坦克初始旋转角度
	static core::vector3df TANK_INIT_ROTATION;

	//坦克死亡存在时间
	static time_t TANK_DIED_EXISTTIME;
	//没用的
	static core::vector3df getTANKpos_MINUS_CAMERApos();

	//火与坦克中心距离
	const static int FIRE_TANK_CENTER_DIS_X = 150;
	const static int FIRE_TANK_CENTER_DIS_Z = 250;
	const static int FIRE_TANK_CENTER_DIS_Y = 200;
	const static core::vector3df FIRE_TANK_CENTER_DIS;


	//击杀单个坦克得分
	const static int TANK_SCORE = 100;

	//坦克面对目标时的角度修正
	const static int TANK_ATTACK_RANGLE;
	const static f32 TANK_TARGET_ROTATION_ANGLE;

	//坦克相对地图高度修正
	const static f32 TANK_INIT_HEIGHT;
	static core::vector3df st ;
	static core::vector3df ed ;

	//坦克的初始速度
	const static int TANK_INIT_SPEED = 5;

	//坦克间的距离
	const static int TANK_DISTANCE = 550;
	TConfig();
~TConfig();
};

