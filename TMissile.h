#pragma once
#include <irrlicht.h>
#include <ctime>
#include "TConfig.h"
using namespace irr;
class TMissile
{
private:
	scene::IAnimatedMeshSceneNode* mMissile;
	core::vector3df pos;
	core::vector3df direction;
	f32 speed;
	time_t mOutTime;
public:
	TMissile(core::vector3df pos, core::vector3df direction);
	time_t outTime();
	time_t outTime(time_t ttime);
	scene::IAnimatedMeshSceneNode* missile();
	void setMissileAnimator(io::path animFile, io::path textureFile, core::vector3df pos);
	void update();
	void drop();
~TMissile();
};

