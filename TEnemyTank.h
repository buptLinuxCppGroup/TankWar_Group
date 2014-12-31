#pragma once
#include "TPlayerTank.h"
#include "TGame.h"
#include "TMath.h"
#include "TConfig.h"
#include "TWorld.h"
#include "THelp.h"
#include <iostream>
#include <vector>
class TEnemyTank
{
private:
	scene::IAnimatedMeshSceneNode* mTank;
	static std::vector<TEnemyTank> mEnemy;
	int mHp;
public:
	scene::IAnimatedMeshSceneNode* tank();
	static std::vector<TEnemyTank>& enemy();
	int hp();
	void beAttacked();
	void reInit();
	TEnemyTank();
	void setTankAnimator(io::path animFile, io::path textureFile);//…Ë÷√ÃπøÀanimator
~TEnemyTank();
};

