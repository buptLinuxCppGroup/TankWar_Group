#include "TMissile.h"
#include "TGame.h"
#include "TMath.h"
#include <iostream>
#include <ctime>
using namespace std;

time_t TMissile::outTime()
{
	return mOutTime;
}

time_t TMissile::outTime(time_t ttime)
{
	return mOutTime=ttime;
}

scene::ISceneNode* TMissile::missile()
{
	return light2;
}

void TMissile::enimInit()
{
	switch (TConfig::MISSILE_KIND)
	{
	case 1: {
		TConfig::MISSILE_INTERVAL_TIME = 1.0;
		TConfig::MISSILE_DAMAGE1 = 5000;
		TConfig::MISSILE_EXIST_TIME = 10;
		TConfig::MISSILE_SPEED = 5;
		missileKind1();
		break;
	}
	case 2: {
		TConfig::MISSILE_INTERVAL_TIME = 1.0;
		TConfig::MISSILE_DAMAGE1 = 2000;
		TConfig::MISSILE_EXIST_TIME = 8;
		TConfig::MISSILE_SPEED = 7;
		missileKind2();
		break;
	}
	case 3: {
		TConfig::MISSILE_INTERVAL_TIME = 0.0;
		TConfig::MISSILE_DAMAGE1 = 700;
		TConfig::MISSILE_EXIST_TIME = 4;
		TConfig::MISSILE_SPEED = 15.0;
		missileKind3();
		break;
	}
	default:
		break;
	}
}

void TMissile::missileKind1()
{
	// add light 2 (red)
	light2 =
		TGame::smgr()->addLightSceneNode(0, core::vector3df(0, 0, 0),
		video::SColorf(1.0f, 0.2f, 0.2f, 0.0f), 800.0f);

	// add fly circle animator to light 2
	/*anim = TGame::smgr()->createFlyCircleAnimator(core::vector3df(0, 150, 0), 200.0f,
	0.001f, core::vector3df(0.2f, 0.9f, 0.f));
	light2->addAnimator(anim);
	anim->drop();*/

	// attach billboard to light
	bill = TGame::smgr()->addBillboardSceneNode(light2, core::dimension2d<f32>(120, 120));
	bill->setMaterialFlag(video::EMF_LIGHTING, false);
	bill->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	bill->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
	bill->setMaterialTexture(0, TGame::driver()->getTexture("../../media/particlegreen.jpg"));

	// add particle system
	ps =
		TGame::smgr()->addParticleSystemSceneNode(false, light2);

	// create and set emitter
	em = ps->createBoxEmitter(
		core::aabbox3d<f32>(-3, 0, -3, 3, 1, 3),
		core::vector3df(0.0f, 0.03f, 0.0f),
		80, 100,
		video::SColor(10, 255, 255, 255), video::SColor(10, 255, 255, 255),
		400, 1100);
	em->setMinStartSize(core::dimension2d<f32>(30.0f, 40.0f));
	em->setMaxStartSize(core::dimension2d<f32>(300.0f, 400.0f));

	ps->setEmitter(em);
	em->drop();

	// create and set affector
	paf = ps->createFadeOutParticleAffector();
	ps->addAffector(paf);
	paf->drop();

	// adjust some material settings
	ps->setMaterialFlag(video::EMF_LIGHTING, false);
	ps->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	ps->setMaterialTexture(0, TGame::driver()->getTexture("../../media/fireball.bmp"));
	//ps->setMaterialTexture(0, TGame::driver()->getTexture("../../media/portal2.bmp"));
	ps->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
}

void TMissile::missileKind2()
{
	// add light 2 (red)
	light2 =
		TGame::smgr()->addLightSceneNode(0, core::vector3df(0, 0, 0),
		video::SColorf(1.0f, 0.2f, 0.2f, 0.0f), 800.0f);

	// add fly circle animator to light 2
	/*anim = TGame::smgr()->createFlyCircleAnimator(core::vector3df(0, 150, 0), 200.0f,
	0.001f, core::vector3df(0.2f, 0.9f, 0.f));
	light2->addAnimator(anim);
	anim->drop();*/

	// attach billboard to light
	bill = TGame::smgr()->addBillboardSceneNode(light2, core::dimension2d<f32>(120, 120));
	bill->setMaterialFlag(video::EMF_LIGHTING, false);
	bill->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	bill->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
	bill->setMaterialTexture(0, TGame::driver()->getTexture("../../media/particlegreen.jpg"));

	// add particle system
	ps =
		TGame::smgr()->addParticleSystemSceneNode(false, light2);

	// create and set emitter
	em = ps->createBoxEmitter(
		core::aabbox3d<f32>(-3, 0, -3, 3, 1, 3),
		core::vector3df(0.0f, 0.03f, 0.0f),
		80, 100,
		video::SColor(10, 255, 255, 255), video::SColor(10, 255, 255, 255),
		400, 1100);
	em->setMinStartSize(core::dimension2d<f32>(30.0f, 40.0f));
	em->setMaxStartSize(core::dimension2d<f32>(300.0f, 400.0f));

	ps->setEmitter(em);
	em->drop();

	// create and set affector
	paf = ps->createFadeOutParticleAffector();
	ps->addAffector(paf);
	paf->drop();

	// adjust some material settings
	ps->setMaterialFlag(video::EMF_LIGHTING, false);
	ps->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	//ps->setMaterialTexture(0, TGame::driver()->getTexture("../../media/fireball.bmp"));
	ps->setMaterialTexture(0, TGame::driver()->getTexture("../../media/portal2.bmp"));
	ps->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
}

void TMissile::missileKind3()
{
	// add light 2 (red)
	light2 =
		TGame::smgr()->addLightSceneNode(0, core::vector3df(0, 0, 0),
		video::SColorf(1.0f, 0.2f, 0.2f, 0.0f), 800.0f);

	// add fly circle animator to light 2
	/*anim = TGame::smgr()->createFlyCircleAnimator(core::vector3df(0, 150, 0), 200.0f,
	0.001f, core::vector3df(0.2f, 0.9f, 0.f));
	light2->addAnimator(anim);
	anim->drop();*/

	// attach billboard to light
	bill = TGame::smgr()->addBillboardSceneNode(light2, core::dimension2d<f32>(120, 120));
	bill->setMaterialFlag(video::EMF_LIGHTING, false);
	bill->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	bill->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
	bill->setMaterialTexture(0, TGame::driver()->getTexture("../../media/particlewhite.bmp"));

	// add particle system
	ps =
		TGame::smgr()->addParticleSystemSceneNode(false, light2);

	// create and set emitter
	em = ps->createBoxEmitter(
		core::aabbox3d<f32>(-3, 0, -3, 3, 1, 3),
		core::vector3df(0.0f, 0.03f, 0.0f),
		240, 300,
		video::SColor(10, 255, 255, 255), video::SColor(10, 255, 255, 255),
		333, 333);
	em->setMinStartSize(core::dimension2d<f32>(10.0f, 12.0f));
	em->setMaxStartSize(core::dimension2d<f32>(10.0f, 12.0f));

	ps->setEmitter(em);
	em->drop();

	// create and set affector
	paf = ps->createFadeOutParticleAffector();
	ps->addAffector(paf);
	paf->drop();

	// adjust some material settings
	ps->setMaterialFlag(video::EMF_LIGHTING, false);
	ps->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	//ps->setMaterialTexture(0, TGame::driver()->getTexture("../../media/fireball.bmp"));
	ps->setMaterialTexture(0, TGame::driver()->getTexture("../../media/particlewhite.bmp"));
	ps->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
}

TMissile::TMissile(core::vector3df pos, core::vector3df direction)
{
	this->pos = pos;
	this->speed = TConfig::MISSILE_SPEED;
	this->direction = direction.normalize();
	this->mOutTime = time(NULL);
	//setMissileAnimator(TConfig::MISSILE_3D_MESH_DIR.c_str(), TConfig::MISSILE_3D_TEXTURE_DIR.c_str(),pos);
	enimInit();
}

void TMissile::setMissileAnimator(io::path animFile, io::path textureFile,core::vector3df pos)
{
	scene::IAnimatedMesh* mesh = TGame::smgr()->getMesh(animFile);
	mMissile = TGame::smgr()->addAnimatedMeshSceneNode(mesh);
	mMissile->setMaterialFlag(video::EMF_LIGHTING, false);
	mMissile->setMD2Animation(scene::EMAT_CROUCH_ATTACK);
	mMissile->setMaterialTexture(0, TGame::driver()->getTexture(textureFile));
	mMissile->setRotation(TConfig::TANK_INIT_ROTATION);

	//auto tmpPos = mCamera->getPosition();
	//tmpPos.Y = TGame::world()->terrain()->getHeight(tmpPos.X,tmpPos.Z);

	mMissile->setPosition(pos);
	mMissile->setScale(TMath::dragScale(mMissile->getScale(), 1));

}

void TMissile::update()
{

	//cerr << "1" << endl;

	//TMath::printV3df(pos);


	pos=pos + direction*speed*10;

	//mMissile->setPosition(pos);
	light2->setPosition(pos);
	

	//TMath::printV3df(pos);
	//TMath::printV3df(direction);

}

void TMissile::drop() {
	//mMissile->setVisible(false);
	light2->setVisible(false);
	//mMissile->drop();
}

TMissile::~TMissile()
{
}
