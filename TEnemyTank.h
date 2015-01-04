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
	int mSpeed;
	int fullHp;
	int mHp;
	bool mDied;
	time_t mDiedTime;
	TFire mFire;

	time_t mLastMissileTime;
public:
	std::vector<TMissile> mMissileQueue;

	bool died();
	TFire fire();
	void checkIfFire();
	time_t diedTime();
	scene::IAnimatedMeshSceneNode* tank();
	static std::vector<TEnemyTank>& enemy();
	int hp();
	void setSpeed(int speed);
	int Speed();
	vector3df updateTarget(vector3df playerPos);
	vector3df updatePosition(vector3df playerPos,f32 attackRangle);
	vector3df updateRotation();
	static void avoidCollide();
	time_t lastMissileTime();
	void setLastMissileTime(time_t s);
	void beAttacked();
	int getFullHp();
	void reInit();
	TEnemyTank();
	void setTankAnimator(io::path animFile, io::path textureFile);//…Ë÷√ÃπøÀanimator
~TEnemyTank();
};

