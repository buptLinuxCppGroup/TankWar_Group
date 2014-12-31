#pragma once
#include <irrlicht.h>
#include "TGame.h"
#include <ctime>
using namespace irr;
class TFire
{
private:
	scene::IParticleSystemSceneNode* ps;
	int minRate;
	int maxRate;
	int minLife;
	int maxLife;
	core::dimension2df minSize;
	core::dimension2df maxSize;
	io::path texturePath;
	core::vector3df pos;
	core::vector3df scale;
	bool isFireNow;
public:
	TFire();
	core::dimension2df getMinSize();
	core::dimension2df getMaxSize();
	bool fireNow();
	void setRateRange(int tmin,int tmax);
	void setLifeRange(int tmin, int tmax);
	void setTexturePath(io::path t);
	void setSizeRange(core::dimension2df tmin, core::dimension2df tmax);
	void setPos(vector3df tpos);
	void setScale(vector3df tscale);
	void startFire();
	void stopFire();
	void resetFire();
	void setSmallFire(vector3df tpos);
	void setMiddleFire(vector3df tpos);
	void setBigFire(vector3df tpos);
~TFire();
};

