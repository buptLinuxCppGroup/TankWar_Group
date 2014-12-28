
#include <irrlicht.h>
#include <iostream>
#include "TGame.h"
#include "TPlayerTank.h"
#include "TEnemyTank.h"
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
	world.addTree2("./data/tree.b3d","./data/tree2.b3d",25,&player);
	world.addGrass(10, "./data/terrain/terrain-heightmap.bmp","./data/terrain/grass/terrain-grasscol.bmp","./data/terrain/grass/terrain-grassmap.png","./data/terrain/grass/grass.png","./data/terrain/grass/grass2.bmp");
	// create skybox and skydome
	TGame::driver()->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);
	//world.skybox("./data/terrain/sky/irrlicht2_up.jpg","./data/terrain/sky/irrlicht2_dn.jpg","./data/terrain/sky/irrlicht2_lf.jpg","./data/terrain/sky/irrlicht2_rt.jpg","./data/terrain/sky/irrlicht2_ft.jpg", "./data/terrain/sky/irrlicht2_bk.jpg");
	world.skydome("./data/terrain/sky/skydome.jpg", 16, 8, 0.95f, 2.0f);	
	TGame::driver()->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);
	
	player.camera()->setFarValue(10000);
	
	player.setAnimator(
		TGame::smgr()->createCollisionResponseAnimator(
		world.selector(), player.camera(),core::vector3df(300,600,300),
		core::vector3df(0.0f, -75.0f, 0.0f), core::vector3df(0, -400, 0)
		)
	);

	
	
	

	world.selector()->drop();

	TEnemyTank enemy;

	/////ÓÎÏ·ÔËÐÐ
	TGame::run(&player);
	TGame::drop();
	return 0;
}

