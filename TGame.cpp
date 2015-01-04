#include "TEvent.h"
#include "TMath.h"
#include "THelp.h"
#include "TConfig.h"
#include "TBloodBar.h"
#include "TMark.h"
#include "TGame.h"
#include "TEnemyTank.h"
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
	int table = 40;
	vector3df Shock[4];
	Shock[0] = vector3df(table, table, 0);
	Shock[1] = vector3df(-table, -table, 0);
	Shock[2] = vector3df(table, -table, 0);
	Shock[3] = vector3df(-table, table, 0);
	int shockIdx = 0;

	
	
	int i1 = 0, i2 = 0, i3 = 0,h = 0;
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


			vector<TEnemyTank> Enemy = TEnemyTank::enemy();
			for (int i = 0; i < Enemy.size(); i++)
			{
				vector3df R0 = TConfig::TANK_INIT_ROTATION;
				vector3df R1 = Enemy[i].updateTarget(player->getPosition());
				vector3df R2 = Enemy[i].updateRotation();

				//Enemy[i].tank()->setRotation(R0 + R1 + R2);
				Enemy[i].tank()->setRotation(R0 + R1 );
				Enemy[i].tank()->setPosition(Enemy[i].updatePosition(player->getPosition(),TConfig::TANK_ATTACK_RANGLE));
			}
			TEnemyTank::avoidCollide();

			/*Shocked
			player->camera()->setTarget(player->camera()->getTarget()+Shock[shockIdx]);
			Shocked*/

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

			event->updateEnemyMissiles();
			
			i2 = 200-(int)(TGame::player()->hp()/ 5000);
			TBloodBar B(mDevice, mDriver, i2);
			i1 = TGame::player()->score();
			TMark M(mDevice, mDriver, i1);
		
			TEnemyTank hp;
			TBloodBar enemy;
			h = hp.getFullHp();
			i3 = 200 - (hp.hp() / (h / 200));
			enemy.TBloodBarEnemy(mDevice, mDriver, i3);

			mDriver->endScene();


			/*Shocked
			player->camera()->setTarget(player->camera()->getTarget() - Shock[shockIdx]);
			shockIdx = (shockIdx + 1) % 4;
			Shocked*/

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
