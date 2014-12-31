#include "TEnemyTank.h"


std::vector<TEnemyTank> TEnemyTank::mEnemy = vector<TEnemyTank>();
TEnemyTank::TEnemyTank()
{
	setTankAnimator(TConfig::TANK_3D_MESH_DIR.c_str(), TConfig::TANK_3D_TEXTURE_DIR.c_str());
	//初始化血量
	mHp = TMath::randomBetweenMinMax(TConfig::MISSILE_HP_DOWN,TConfig::MISSILE_HP_UP);
	cerr << "血量：" << mHp << endl;
}

scene::IAnimatedMeshSceneNode* TEnemyTank::tank()
{
	return mTank;
}

std::vector<TEnemyTank>& TEnemyTank::enemy()
{
	return mEnemy;
}

int TEnemyTank::hp()
{
	return mHp;
}

void TEnemyTank::beAttacked()
{
	mHp -= TConfig::MISSILE_DAMAGE1;
}

void TEnemyTank::reInit()
{
	core::vector3df newPos;
	core::aabbox3df modelBoundingBox = TGame::world()->terrain()->getBoundingBox();
	core::vector3df minEdgeExtended = modelBoundingBox.MinEdge;
	core::vector3df maxEdgeExtended = modelBoundingBox.MaxEdge;
	newPos.X = TMath::randomBetweenMinMax(minEdgeExtended.X,maxEdgeExtended.X);
	newPos.Z= TMath::randomBetweenMinMax(minEdgeExtended.X, maxEdgeExtended.X);
	newPos.Y = TGame::world()->terrain()->getHeight(newPos.X,newPos.Y);
	mTank->setPosition(newPos);
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
