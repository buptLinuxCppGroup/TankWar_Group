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

scene::IAnimatedMeshSceneNode * TMissile::missile()
{
	return mMissile;
}

TMissile::TMissile(core::vector3df pos, core::vector3df direction)
{
	this->pos = pos;
	this->speed = TConfig::MISSILE_SPEED;
	this->direction = direction.normalize();
	this->mOutTime = time(NULL);
	setMissileAnimator(TConfig::MISSILE_3D_MESH_DIR.c_str(), TConfig::MISSILE_3D_TEXTURE_DIR.c_str(),pos);
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
<<<<<<< HEAD
=======
	//cerr << "1" << endl;

	//TMath::printV3df(pos);
>>>>>>> origin/master

	pos=pos + direction*speed*10;

	mMissile->setPosition(pos);
	
<<<<<<< HEAD
=======
	//TMath::printV3df(pos);
	//TMath::printV3df(direction);
>>>>>>> origin/master
}

void TMissile::drop() {
	mMissile->setVisible(false);
	//mMissile->drop();
}

TMissile::~TMissile()
{
}
