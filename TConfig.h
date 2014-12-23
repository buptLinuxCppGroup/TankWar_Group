#pragma once
#include <string>
#include <irrlicht.h>
using namespace irr;
class TConfig
{
private:
	static core::vector3df TANKpos_MINUS_CAMERApos;
public:
	static std::string TANK_3D_MESH_DIR;
	static std::string TANK_3D_TEXTURE_DIR;
	static core::vector3df TANK_INIT_ROTATION;
	static core::vector3df getTANKpos_MINUS_CAMERApos();
	TConfig();
~TConfig();
};

