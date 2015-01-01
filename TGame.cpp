#include "TEvent.h"
#include "TMath.h"
#include "THelp.h"
#include "TConfig.h"
#include "TBloodBar.h"
#include "TMark.h"
#include "TGame.h"
#include <iostream>
using namespace std;
scene::ISceneManager* TGame::mSmgr = NULL;
irr::IrrlichtDevice* TGame::mDevice = NULL;
video::IVideoDriver* TGame::mDriver = NULL;
TWorld* TGame::mWorld=NULL;
TPlayerTank* TGame::mPlayer = NULL;

scene::ISceneManager * TGame::smgr()
{
	return mSmgr;
}

irr::IrrlichtDevice * TGame::device()
{
	return mDevice;
}

video::IVideoDriver * TGame::driver()
{
	return mDriver;
}

TPlayerTank * TGame::player()
{
	return mPlayer;
}



TWorld * TGame::world()
{
	return mWorld;
}

void TGame::getWorld(TWorld * tworld)
{
	mWorld = tworld;
}

void TGame::getPlayer(TPlayerTank * tplayer)
{
	mPlayer = tplayer;
}

	

void TGame::init()
{
	mDevice = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(1024, 768));
	mDriver = mDevice->getVideoDriver();
	mSmgr = mDevice->getSceneManager();

	mDevice->getCursorControl()->setVisible(false);
	/*mDevice->getFileSystem()->addFileArchive("../../media/map-20kdm2.pk3");
	scene::IAnimatedMesh* mesh = mSmgr->getMesh("20kdm2.bsp");
	scene::ISceneNode* node = mSmgr->addOctreeSceneNode(mesh->getMesh(0),0,-1,1024);
	node->setPosition(core::vector3df(0,0,0));*/

}

void TGame::drop()
{
	mDevice->drop();
}


void TGame::run(TPlayerTank * player)
{
	int i1 = 0, i2 = 0, i3 = 0;
	TEvent* event = new TEvent(player);
	TGame::device()->setEventReceiver(event);
	if (mDevice->isWindowActive()) {
		while (mDevice->run()) {
			//		if (mDevice->isWindowActive()) {
						///事件处理器
						//event->getRightRotation();
						//event->getRightPosition();

			event->showInfo();
			event->changeMissileKind();
			//event->moveTankPos();
			//event->moveTankRotation();
			//event->correctY();
			//THelp::showPlayerPos(player);//显示摄像机位置
			//player->tank()->setPosition(player->camera()->getPosition());


			//core::line3d<f32> ray;
			//ray.start = TGame::player()->camera()->getPosition();
			//ray.end = ray.start + (core::vector3df(100,100,1000) - ray.start).normalize() * 5000.0f;
			//video::SMaterial debugmaterial;
			//debugmaterial.DiffuseColor = irr::video::SColor(0xFFFFFF00);
			//debugmaterial.AmbientColor = irr::video::SColor(0xFFFFFF00);
			////TGame::driver()->setMaterial(debugmaterial);
			////TGame::driver()->setTransform(irr::video::ETS_WORLD, irr::core::IdentityMatrix);
			//TGame::driver()->draw2DLine(core::position2d<s32>(0, 0), core::position2d<s32>(100, 100));

			///渲染部分
			mDriver->beginScene(true, true, video::SColor(255, 200, 200, 200));

			
			//TGame::driver()->draw3DLine(st, ed, video::SColor(255, 0, 0, 0));

			event->setStEd(TConfig::st, TConfig::ed);


			//TGame::driver()->draw3DLine(TConfig::st, TConfig::ed, video::SColor(255, 0, 0, 0));


			event->leftMouse(TConfig::st, TConfig::ed);

			mSmgr->drawAll();

			TGame::world()->loadCrossHair();
			event->updateMissiles();
			TBloodBar B(mDevice, mDriver, i2);
			i1 = TGame::player()->score();
			TMark M(mDevice, mDriver, i1);
			/*
			scene::ISceneNode* bar1 = mSmgr->addLightSceneNode(0, core::vector3df(0, 0, 0), video::SColorf(1.0f, 0.0f, 0.0f, 0.0f), 800.0f);
			bar1->setDebugDataVisible(scene::EDS_BBOX);
			scene::ISceneNodeAnimator* anim = 0;
			anim = mSmgr->createFlyCircleAnimator(core::vector3df(50, 300, 0), 190.0f, -0.003f);
			bar1->addAnimator(anim);
			anim->drop();
			bar1 = mSmgr->addBillboardSceneNode(bar1, core::dimension2d<f32>(60, 60));
			bar1->setMaterialFlag(video::EMF_LIGHTING, false);
			bar1->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
			bar1->setMaterialTexture(0, mDriver->getTexture("../../media/particlered.bmp"));
			*/


			mDriver->endScene();
			//		}
			//		else {
			//			mDevice->yield();
			//		}
		}
	}
	delete event;
}

TGame::TGame()
{
	;
}


TGame::~TGame()
{
}
