#include "TEnemyTank.h"


std::vector<TEnemyTank> TEnemyTank::mEnemy = vector<TEnemyTank>();
TEnemyTank::TEnemyTank()
{
	setTankAnimator(TConfig::TANK_3D_MESH_DIR.c_str(), TConfig::TANK_3D_TEXTURE_DIR.c_str());
	
}

scene::IAnimatedMeshSceneNode* TEnemyTank::tank()
{
	return mTank;
}

std::vector<TEnemyTank>& TEnemyTank::enemy()
{
	return mEnemy;
}

void TEnemyTank::setTankAnimator(io::path animFile, io::path textureFile)
{
	scene::IAnimatedMesh* mesh = TGame::smgr()->getMesh(animFile);
	mTank = TGame::smgr()->addAnimatedMeshSceneNode(mesh);
	mTank->setMaterialFlag(video::EMF_LIGHTING, false);
	mTank->setMaterialTexture(0, TGame::driver()->getTexture(textureFile));
	mTank->setRotation(TConfig::TANK_INIT_ROTATION);

	//auto tmpPos = mCamera->getPosition();
	//tmpPos.Y = TGame::world()->terrain()->getHeight(tmpPos.X,tmpPos.Z);

	
	mTank->setPosition(core::vector3df(2587.99, 550.624, 2260.09));
	mTank->setScale(TMath::dragScale(mTank->getScale(),3));
	//mTank->setScale(core::vector3df(8,8,8));

	auto tankPos = mTank->getPosition();
	tankPos.Y = TGame::world()->terrain()->getHeight(tankPos.X, tankPos.Z);
	mTank->setPosition(tankPos);
}

TEnemyTank::~TEnemyTank()
{
}
