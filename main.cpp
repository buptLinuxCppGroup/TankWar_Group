
#include <irrlicht.h>
#include <iostream>
#include "TGame.h"
#include "TPlayerTank.h"
#include "TEnemyTank.h"
#include "TWorld.h"
#include "TFire.h"
#include "TMath.h"
#include <vector>
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
	world.addTree2("F:/linux/irrlicht-1.7.3/examples/02.Quake3Map/data/tree.b3d","F:/linux/irrlicht-1.7.3/examples/02.Quake3Map/data/tree2.b3d",25,&player);
	world.addGrass(10, "F:/linux/irrlicht-1.7.3/examples/02.Quake3Map/data/terrain/terrain-heightmap.bmp","F:/linux/irrlicht-1.7.3/examples/02.Quake3Map/data/terrain/grass/terrain-grasscol.bmp","F:/linux/irrlicht-1.7.3/examples/02.Quake3Map/data/terrain/grass/terrain-grassmap.png","F:/linux/irrlicht-1.7.3/examples/02.Quake3Map/data/terrain/grass/grass.png","F:/linux/irrlicht-1.7.3/examples/02.Quake3Map/data/terrain/grass/grass2.bmp");
	// create skybox and skydome
	TGame::driver()->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);
	//world.skybox("./data/terrain/sky/irrlicht2_up.jpg","./data/terrain/sky/irrlicht2_dn.jpg","./data/terrain/sky/irrlicht2_lf.jpg","./data/terrain/sky/irrlicht2_rt.jpg","./data/terrain/sky/irrlicht2_ft.jpg", "./data/terrain/sky/irrlicht2_bk.jpg");
	world.skydome("F:/linux/irrlicht-1.7.3/examples/02.Quake3Map/data/terrain/sky/skydome.jpg", 16, 8, 0.95f, 2.0f);	
	TGame::driver()->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);
	world.loadCrossHair();//加准星

	player.camera()->setFarValue(10000);
	
	player.setAnimator(
		TGame::smgr()->createCollisionResponseAnimator(
		world.selector(), player.camera(),core::vector3df(300,600,300),
		core::vector3df(0.0f, -75.0f, 0.0f), core::vector3df(0, -400, 0)
		)
	);

	
	
	

	//world.selector()->drop();
	TEnemyTank tmp[10];
	for (int i = 0; i < 10;i++)
		TEnemyTank::enemy().push_back(tmp[i]);
	/*enemy.tank()->addAnimator(
			TGame::smgr()->createCollisionResponseAnimator(
			TGame::smgr()->createOctTreeTriangleSelector(player., 0), enemy.tank(), core::vector3df(600, 1200, 600),
			core::vector3df(0.0f, -75.0f, 0.0f), core::vector3df(0, -400, 0)
			)
			);*/
	
	/*enemy.tank()->setMaterialFlag(video::EMF_WIREFRAME,
			!enemy.tank()->getMaterial(0).Wireframe);
	enemy.tank()->setMaterialFlag(video::EMF_POINTCLOUD, false);*/

	
	/////游戏运行
	TGame::run(&player);
	TGame::drop();
	return 0;
}

