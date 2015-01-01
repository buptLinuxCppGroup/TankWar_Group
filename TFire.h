#pragma once
#include"irrlicht.h"

using namespace irr;
class TFire{
private:
	double x1, y1, z1;

public:
	TFire();
	TFire(IrrlichtDevice *device, scene::ISceneManager* smgr, video::IVideoDriver* mDriver, double x2, double y2, double z2);
	void set(double x2, double y2, double z2);
};