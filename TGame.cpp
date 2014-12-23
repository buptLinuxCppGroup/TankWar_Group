#include "TGame.h"
#include "TEvent.h"
#include "TMath.h"
#include "THelp.h"
#include <iostream>
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
	TEvent* event = new TEvent(player);
	TGame::device()->setEventReceiver(event);
	while (mDevice->run()) {
		if (mDevice->isWindowActive()) {
			///�¼�������
			//event->getRightRotation();
			//event->getRightPosition();
			event->showInfo();
			event->moveTankPos();
			event->moveTankRotation();
			event->correctY();
			event->leftMouse();
			//THelp::showPlayerPos(player);//��ʾ�����λ��
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

			///��Ⱦ����
			mDriver->beginScene(true, true, video::SColor(255, 200, 200, 200));
			mSmgr->drawAll();
			mDriver->endScene();
		}
		else {
			mDevice->yield();
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