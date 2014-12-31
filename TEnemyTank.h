#pragma once
#include "TPlayerTank.h"
#include "TFire.h"
#include "TGame.h"
#include "TMath.h"
#include "TConfig.h"
#include "TWorld.h"
#include "THelp.h"
#include <ctime>
#include <iostream>
#include <vector>
class TEnemyTank
{
private:
	scene::IAnimatedMeshSceneNode* mTank;
	static std::vector<TEnemyTank> mEnemy;
	int fullHp;
	int mHp;
	bool mDied;
	time_t mDiedTime;
	TFire mFire;
public:
	bool died();
	TFire fire();
	void checkIfFire();
	time_t diedTime();
	scene::IAnimatedMeshSceneNode* tank();
	static std::vector<TEnemyTank>& enemy();
	int hp();
	void beAttacked();
	void reInit();
	TEnemyTank();
	void setTankAnimator(io::path animFile, io::path textureFile);//����̹��animator
~TEnemyTank();
};

