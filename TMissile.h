#pragma once
#include <irrlicht.h>
#include "TConfig.h"
using namespace irr;
class TMissile
{
private:
	scene::IAnimatedMeshSceneNode* mMissile;
	core::vector3df pos;
	core::vector3df direction;
	f32 speed;
public:
	scene::IAnimatedMeshSceneNode* missile();
	TMissile(core::vector3df pos, core::vector3df direction);
	void setMissileAnimator(io::path animFile, io::path textureFile, core::vector3df pos);
	void update();
	void drop();
~TMissile();
};

