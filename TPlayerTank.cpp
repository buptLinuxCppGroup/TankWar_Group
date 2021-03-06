#include "TPlayerTank.h"
#include "TGame.h"
#include "TMath.h"
#include "TConfig.h"
#include "TWorld.h"
#include "THelp.h"
#include <iostream>




bool TPlayerTank::leftClick()
{
	return mLeftClick;
}

void TPlayerTank::leftClick(bool tclick)
{
	mLeftClick = tclick;
}

int TPlayerTank::score()
{
	return mScore;
}

int TPlayerTank::hp()
{
	return mHp;
}

void TPlayerTank::beAttacked()
{
	mHp -= TConfig::MISSILE_DAMAGE1;
}

void TPlayerTank::score(int s)
{
	mScore = s;
}

void TPlayerTank::scorePlus(int s)
{
	mScore += s;
}

bool TPlayerTank::timePermites()
{
	time_t nowTime;
	nowTime = time(NULL);
	if (nowTime - mLastMissileTime >= TConfig::MISSILE_INTERVAL_TIME) {
		mLastMissileTime = nowTime;
		return true;
	}
	else
		return false;
}

std::vector<TMissile>& TPlayerTank::missileQueue()
{
	return mMissileQueue;
}

scene::ISceneNodeAnimator * TPlayerTank::animator()
{
	return mCollAnim;
}

scene::ICameraSceneNode * TPlayerTank::camera()
{
	return mCamera;
}

scene::IAnimatedMeshSceneNode * TPlayerTank::tank()
{
	return mTank;
}

scene::ISceneCollisionManager * TPlayerTank::collMan()
{
	return mCollMan;
}

void TPlayerTank::setAnimator(scene::ISceneNodeAnimator * tmp)
{
	mCollAnim = tmp;
	mCamera->addAnimator(mCollAnim);
	tmp->drop();
}

void TPlayerTank::setTankAnimator(io::path animFile,io::path textureFile)
{
	scene::IAnimatedMesh* mesh = TGame::smgr()->getMesh(animFile);
	mTank = TGame::smgr()->addAnimatedMeshSceneNode(mesh);
	mTank->setMaterialFlag(video::EMF_LIGHTING,false);
	mTank->setMaterialTexture(0,TGame::driver()->getTexture(textureFile));
	//mTank->setRotation(TConfig::TANK_INIT_ROTATION);

	//auto tmpPos = mCamera->getPosition();
	//tmpPos.Y = TGame::world()->terrain()->getHeight(tmpPos.X,tmpPos.Z);

	//mTank->setPosition(core::vector3df(-33.5,-197.7,94.2));
	core::vector3df positionOffset = core::vector3df(-1.5f, 3.5f, -2.5f);
	core::vector3df rotationOffset = core::vector3df(0.0f, -90.0f, -4.0f);

	mTank->setPosition(positionOffset);
	mTank->setRotation(rotationOffset);
	mTank->setParent(mCamera);
	mTank->setMD2Animation("idle");

}

void TPlayerTank::letTankGround()
{
	auto pos = mTank->getPosition();
	pos.Y = TGame::world()->terrain()->getHeight(pos.X,pos.Z) + tank()->getScale().Y;
	mTank->setPosition(pos);
}


core::vector3df TPlayerTank::getPosition()
{
	return mCamera->getPosition();
}



TPlayerTank::TPlayerTank()
{
	//init camera
	irr::SKeyMap keyMap[4] = {
		{ EKA_MOVE_FORWARD,	KEY_KEY_W },
		{ EKA_MOVE_BACKWARD,	KEY_KEY_S },
		{ EKA_STRAFE_LEFT,	KEY_KEY_A },
		{ EKA_STRAFE_RIGHT,	KEY_KEY_D },
	};
	mCamera = TGame::smgr()->addCameraSceneNodeFPS(0, 100.0f, 0.5f, -1, keyMap, 8, false, 0.0f, false, true);
	mCamera->setPosition(core::vector3df(2341.5f,350.0f,1969.2f));
	
	//set tank animator
	setTankAnimator(TConfig::GUN1_3D_MESH_DIR.c_str(), TConfig::GUN1_3D_TEXTURE_DIR.c_str());

	mLeftClick = false;
	mCollMan = TGame::smgr()->getSceneCollisionManager();

	mLastMissileTime = 0;

	mScore = 0;
	mHp = 999999;
}


TPlayerTank::~TPlayerTank()
{
}
