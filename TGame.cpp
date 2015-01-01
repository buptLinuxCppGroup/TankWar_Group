#include "TGame.h"
#include "TEvent.h"
#include "TMath.h"
#include "THelp.h"
#include "TConfig.h"
#include "TBloodBar.h"
#include "TMark.h"
#include "TFire.h"
#include "TSnow.h"
#include "TRain.h"
#include "TYan.h"
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

//下面的下雪，雨，火都是一模一样的，除了一些数据和加载的图片



/*scene::IParticleSystemSceneNode* drawFire(scene::ISceneManager* mSmgr, video::IVideoDriver* mDriver, double x, double y, double z){
scene::IParticleSystemSceneNode* ps = mSmgr->addParticleSystemSceneNode(false);

scene::IParticleEmitter* em = ps->createBoxEmitter(
core::aabbox3d<f32>(-7, 0, -7, 7, 1, 7), // 设置粒子出现的位置的大小
core::vector3df(0.0f, 0.06f, 0.0f),   // 粒子的方向
80, 120,                             // 每秒粒子发射的个数80-100
video::SColor(0, 255, 255, 255),       // darkest color
video::SColor(0, 255, 255, 255),       // brightest color  颜色范围
800, 1000, 0,                         // 单个粒子存活的时间，以毫秒为单位
core::dimension2df(10.f, 10.f),         // min size
core::dimension2df(20.f, 20.f));        // max size

ps->setEmitter(em); // this grabs the emitter
em->drop(); // so we can drop it here without deleting it

scene::IParticleAffector* paf = ps->createFadeOutParticleAffector();

ps->addAffector(paf); // same goes for the affector
paf->drop();

ps->setPosition(core::vector3df(x, y, z));//第一个是左边，中间的一个是高，最后右边，以50为单位移动吧
ps->setScale(core::vector3df(2, 2, 2));
ps->setMaterialFlag(video::EMF_LIGHTING, false);
ps->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
ps->setMaterialTexture(0, mDriver->getTexture("././media/fire.bmp"));
ps->setMaterialType(video::EMT_TRANSPARENT_VERTEX_ALPHA);

return ps;
}
*/
/*
cleSystemSceneNode(false);

scene::IParticleEmitter* em = ps->createBoxEmitter(
core::aabbox3d<f32>(-800,0, -800, 800, 1, 800), // 设置粒子出现的位置的大小
core::vector3df(0.0f, -0.06f, 0.0f),   // 粒子的方向
100, 120,                             // 每秒粒子发射的个数80-100
video::SColor(0, 255, 255, 255),       // darkest color
video::SColor(0, 255, 255, 255),       // brightest color  颜色范围
50000, 300000, 0,                         // 单个粒子存活的时间，以毫秒为单位
core::dimension2df(10.f, 10.f),         // min size
core::dimension2df(20.f, 20.f));        // max size

ps->setEmitter(em); // this grabs the emitter
em->drop(); // so we can drop it here without deleting it

scene::IParticleAffector* paf = ps->createFadeOutParticleAffector();

ps->addAffector(paf); // same goes for the affector
paf->drop();

ps->setPosition(core::vector3df(x, y, z));//第一个是左边，中间的一个是高，最后右边，以50为单位移动吧
ps->setScale(core::vector3df(2, 2, 2));
ps->setMaterialFlag(video::EMF_LIGHTING, false);
ps->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
ps->setMaterialTexture(0, mDriver->getTexture("././media/yan1.jpg"));
ps->setMaterialType(video::EMT_TRANSPARENT_VERTEX_ALPHA);

return ps;
}

scene::IParticleSystemSceneNode* drawRain(scene::ISceneManager* mSmgr, video::IVideoDriver* mDriver, double x, double y, double z){
scene::IParticleSystemSceneNode* ps = mSmgr->addParticleSystemSceneNode(false);

scene::IParticleEmitter* em = ps->createBoxEmitter(
core::aabbox3d<f32>(-800, 0, -800, 800, 1, 800), // 设置粒子出现的位置的大小
core::vector3df(0.0f, -0.06f, 0.0f),   // 粒子的方向
100, 120,                             // 每秒粒子发射的个数80-100
video::SColor(0, 255, 255, 255),       // darkest color
video::SColor(0, 255, 255, 255),       // brightest color  颜色范围
50000, 300000, 0,                         // 单个粒子存活的时间，以毫秒为单位
core::dimension2df(10.f, 10.f),         // min size
core::dimension2df(20.f, 20.f));        // max size

ps->setEmitter(em); // this grabs the emitter
em->drop(); // so we can drop it here without deleting it

scene::IParticleAffector* paf = ps->createFadeOutParticleAffector();

ps->addAffector(paf); // same goes for the affector
paf->drop();

ps->setPosition(core::vector3df(x, y, z));//第一个是左边，中间的一个是高，最后右边，以50为单位移动吧
ps->setScale(core::vector3df(2, 2, 2));
ps->setMaterialFlag(video::EMF_LIGHTING, false);
ps->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
ps->setMaterialTexture(0, mDriver->getTexture("././media/yu3.png"));
ps->setMaterialType(video::EMT_TRANSPARENT_VERTEX_ALPHA);

return ps;
}

*/


void TGame::run(TPlayerTank * player)
{
	int i1 = 0, i2 = 0, i3 = 0;
	TEvent* event = new TEvent(player);
	TGame::device()->setEventReceiver(event);

	TFire T(mDevice, mSmgr, mDriver, 2587.99, 1050.624, 2260.09);
	TYan Y(mDevice, mSmgr, mDriver, 2587.99, 500.624, 2260.09);
	TSnow S(mDevice, mSmgr, mDriver, 2480.99, 1000.624, 2200.09);
	TRain R(mDevice, mSmgr, mDriver, 2480.99, 1000.624, 2300.09);
	/**
	//下面的下雨，下雪，点火都是地点是随便写的
	//drawFire
	drawFire(mSmgr, mDriver, 2587.99, 550.624, 2290.09);
	drawFire(mSmgr, mDriver, 2540.99, 750.624, 2090.09);
	drawFire(mSmgr, mDriver, 2540.99, 750.624, 2290.09);
	drawFire(mSmgr, mDriver, 2480.99, 750.624, 2400.09);
	drawFire(mSmgr, mDriver, 2540.99, 750.624, 2000.09);
	drawFire(mSmgr, mDriver, 2300.99, 7500.624, 2100.09);
	drawFire(mSmgr, mDriver, 2400.99, 560.624, 2290.09);
	drawFire(mSmgr, mDriver, 2400.99, 560.624, 2290.09);
	drawFire(mSmgr, mDriver, 2000.99, 560.624, 2000.09);
	drawFire(mSmgr, mDriver, 2000.99, 560.624, 2500.09);

	//drawSnow
	drawSnow(mSmgr, mDriver, 2480.99, 1000.624, -1000.09);
	drawSnow(mSmgr, mDriver, 2480.99, 1000.624, -3000.09);
	drawSnow(mSmgr, mDriver, 2480.99, 1000.624, -5000.09);
	drawSnow(mSmgr, mDriver, 2480.99, 1000.624, -7000.09);
	drawSnow(mSmgr, mDriver, 2480.99, 1000.624, -9000.09);
	drawSnow(mSmgr, mDriver, 2480.99, 1000.624, 1000.09);
	drawSnow(mSmgr, mDriver, 2480.99, 1000.624, 3000.09);
	drawSnow(mSmgr, mDriver, 2480.99, 1000.624, 5000.09);
	drawSnow(mSmgr, mDriver, 2480.99, 1000.624, 7000.09);
	drawSnow(mSmgr, mDriver, 1000.99, 1000.624, 5000.09);
	drawSnow(mSmgr, mDriver, 3000.99, 1000.624, 5000.09);
	drawSnow(mSmgr, mDriver, 5000.99, 1000.624, 5000.09);

	//drawRain
	drawRain(mSmgr, mDriver, 2480.99, 1000.624, -1000.09);
	drawRain(mSmgr, mDriver, 2480.99, 1000.624, -3000.09);
	drawRain(mSmgr, mDriver, 2480.99, 1000.624, -5000.09);
	drawRain(mSmgr, mDriver, 2480.99, 1000.624, -7000.09);
	drawRain(mSmgr, mDriver, 2480.99, 1000.624, -9000.09);
	drawRain(mSmgr, mDriver, 2480.99, 1000.624, 1000.09);
	drawRain(mSmgr, mDriver, 2480.99, 1000.624, 3000.09);
	drawRain(mSmgr, mDriver, 2480.99, 1000.624, 5000.09);
	drawRain(mSmgr, mDriver, 2480.99, 1000.624, 7000.09);
	drawRain(mSmgr, mDriver, 1000.99, 1000.624, 5000.09);
	drawRain(mSmgr, mDriver, 3000.99, 1000.624, 5000.09);
	drawRain(mSmgr, mDriver, 5000.99, 1000.624, 5000.09);


	*/


	if (mDevice->isWindowActive()) {
		while (mDevice->run()) {
			//		if (mDevice->isWindowActive()) {
						///事件处理器
						//event->getRightRotation();
						//event->getRightPosition();

			event->showInfo();
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

			event->updateMissiles();
			
			TBloodBar B(mDevice, mDriver,i1);
			TBloodBar* b = new TBloodBar();
			b->TBloodBarEnemy(mDevice, mDriver, i2);
			TMark M(mDevice, mDriver,i3);



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
