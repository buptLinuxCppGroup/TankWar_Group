#pragma once
#include <irrlicht.h>
#include <ctime>
#include "TConfig.h"
using namespace irr;
class TMissile
{
private:
	static bool hasGravity;

	scene::IAnimatedMeshSceneNode* mMissile;
	core::vector3df pos;
	core::vector3df direction;
	f32 speed;
	time_t mOutTime;

	scene::ISceneNode* light2;
	scene::ISceneNodeAnimator* anim;
	scene::IBillboardSceneNode* bill;
	scene::IParticleSystemSceneNode* ps;
	scene::IParticleEmitter* em;
	scene::IParticleAffector* paf;
public:
	core::vector3df getDirection();
	void setDirection(core::vector3df s);
	void enimInit();
	void enimInitForEnemy();
	void missileKind1();
	void missileKind2();
	void missileKind3();
	TMissile(core::vector3df pos, core::vector3df direction);
	TMissile(core::vector3df pos, core::vector3df direction,bool isEnemyMissile);
	time_t outTime();
	time_t outTime(time_t ttime);
	scene::ISceneNode* missile();
	void setMissileAnimator(io::path animFile, io::path textureFile, core::vector3df pos);
	void update();
	void drop();
~TMissile();
};

