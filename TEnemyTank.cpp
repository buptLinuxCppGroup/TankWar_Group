#include "TEnemyTank.h"



TEnemyTank::TEnemyTank()
{
	setTankAnimator(TConfig::TANK_3D_MESH_DIR.c_str(), TConfig::TANK_3D_TEXTURE_DIR.c_str());
}

void TEnemyTank::setTankAnimator(io::path animFile, io::path textureFile)
{
	scene::IAnimatedMesh* mesh = TGame::smgr()->getMesh(animFile);
	mTank = TGame::smgr()->addAnimatedMeshSceneNode(mesh);
	mTank->setMaterialFlag(video::EMF_LIGHTING, false);
	mTank->setMD2Animation(scene::EMAT_CROUCH_ATTACK);
	mTank->setMaterialTexture(0, TGame::driver()->getTexture(textureFile));
	mTank->setRotation(TConfig::TANK_INIT_ROTATION);

	//auto tmpPos = mCamera->getPosition();
	//tmpPos.Y = TGame::world()->terrain()->getHeight(tmpPos.X,tmpPos.Z);

	
	mTank->setPosition(core::vector3df(2587.99, 550.624, 2260.09));
	mTank->setScale(TMath::dragScale(mTank->getScale(), 3));

}

TEnemyTank::~TEnemyTank()
{
}
