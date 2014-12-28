#include "TConfig.h"

std::string TConfig::TANK_3D_MESH_DIR = "./data/坦克模型/churchill.obj";
std::string TConfig::TANK_3D_TEXTURE_DIR = "./data/坦克模型2/churchill/churchill/Churchill.tga";
//std::string TConfig::TANK_3D_MESH_DIR = "./data/坦克模型2/FLACKP 坦克3D模型/FLACKP/FLACKP_L.3DS";
//std::string TConfig::TANK_3D_TEXTURE_DIR = "./data/坦克模型2/FLACKP 坦克3D模型/FLACKP/FLACKP/MATRICUL.TGA";
core::vector3df TConfig::TANK_INIT_ROTATION = core::vector3df(-86.2f, 274.f, -1.7f);
core::vector3df TConfig::TANKpos_MINUS_CAMERApos = core::vector3df(-60.583,0,-68.2787);

std::string TConfig::MISSILE_3D_MESH_DIR = "./data/坦克模型/churchill.obj";
std::string TConfig::MISSILE_3D_TEXTURE_DIR = "./data/坦克模型2/churchill/churchill/Churchill.tga";

f32 TConfig::MISSILE_SPEED = 10.0;

int TConfig::MISSILE_INTERVAL_TIME = 0;
int TConfig::MISSILE_EXIST_TIME = 10;


core::vector3df TConfig::st = core::vector3df(2341.42, 349.962, 1969.35);
core::vector3df TConfig::ed = core::vector3df(1610.4, 1435.141, 2132.17);

core::vector3df TConfig::getTANKpos_MINUS_CAMERApos()
{
	return TANKpos_MINUS_CAMERApos;
}
TConfig::TConfig()
{
}


TConfig::~TConfig()
{
}
