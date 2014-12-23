#pragma once
#include "TPlayerTank.h"
#include "TGame.h"
#include "TMath.h"
#include "TConfig.h"
#include "TWorld.h"
#include "THelp.h"
#include <iostream>
class TEnemyTank
{
private:
	scene::IAnimatedMeshSceneNode* mTank;
public:
	TEnemyTank();
	void setTankAnimator(io::path animFile, io::path textureFile);//…Ë÷√ÃπøÀanimator
~TEnemyTank();
};

