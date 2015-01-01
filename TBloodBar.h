#pragma once
#include<irrlicht.h>
using namespace irr;

class TBloodBar
{

public:
	TBloodBar();
	TBloodBar(irr::IrrlichtDevice* mDevice, video::IVideoDriver* mDriver,int a1);
	void TBloodBarEnemy(irr::IrrlichtDevice* mDevice, video::IVideoDriver* mDriver, int a2);
};