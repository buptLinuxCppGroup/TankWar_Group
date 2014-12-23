#pragma once
#include <irrlicht.h>
#include "TWorld.h"
#include "TPlayerTank.h"
using namespace irr;
class TGame
{
private:
	static scene::ISceneManager* mSmgr;
	static irr::IrrlichtDevice* mDevice;
	static video::IVideoDriver* mDriver;
	static TWorld* mWorld;
	static TPlayerTank* mPlayer;
public:
	static scene::ISceneManager* smgr();
	static irr::IrrlichtDevice* device();
	static video::IVideoDriver* driver();
	static TPlayerTank* player();
	static TWorld* world();
	static void getWorld(TWorld* tworld);
	static void getPlayer(TPlayerTank* tplayer);
	static void init();
	static void drop();
	static void run(TPlayerTank* player);
	TGame();
~TGame();
};

