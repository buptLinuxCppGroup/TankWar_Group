
#include <irrlicht.h>
#include <iostream>
#include "TGame.h"
#include "TPlayerTank.h"
#include "TWorld.h"
#include "TMath.h"
using namespace std;
using namespace irr;
using namespace video;
using namespace scene;

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif


int main() {
	TGame::init();
	TWorld world;
	TGame::getWorld(&world);
	TPlayerTank player;
	TGame::getPlayer(&player);
	world.addTree2("F:/linux/irrlicht-1.7.3/examples/02.Quake3Map/data/tree.b3d","F:/linux/irrlicht-1.7.3/examples/02.Quake3Map/data/tree2.b3d",10,&player);
	player.setAnimator(
		TGame::smgr()->createCollisionResponseAnimator(
		world.selector(), player.camera(),core::vector3df(200,400,200),
		core::vector3df(0.0f, -75.0f, 0.0f), core::vector3df(0, 0, 0)
		)
	);
	/*player.tank()->addAnimator(
		TGame::smgr()->createCollisionResponseAnimator(
		world.selector(), player.tank(), player.tank()->getScale() ,
		core::vector3df(0.0f, -1.0f, 0.0f), core::vector3df(0, 0, 0)
		)
	);*/
	

	world.selector()->drop();

	/////ÓÎÏ·ÔËÐÐ
	TGame::run(&player);
	TGame::drop();
	return 0;
}

