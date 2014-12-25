#pragma once
#include <string>
#include <irrlicht.h>
using namespace irr;
class TConfig
{
private:
	static core::vector3df TANKpos_MINUS_CAMERApos;
public:
	//坦克mesh和texture路径
	static std::string TANK_3D_MESH_DIR;
	static std::string TANK_3D_TEXTURE_DIR;

	//坦克mesh和texture路径
	static std::string MISSILE_3D_MESH_DIR;
	static std::string MISSILE_3D_TEXTURE_DIR;

	//导弹速度
	static f32 MISSILE_SPEED;

	static core::vector3df TANK_INIT_ROTATION;
	static core::vector3df getTANKpos_MINUS_CAMERApos();

	static core::vector3df st ;
	static core::vector3df ed ;
	TConfig();
~TConfig();
};

