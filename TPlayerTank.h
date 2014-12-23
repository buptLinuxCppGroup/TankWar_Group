#pragma once
#include "TTank.h"
#include <irrlicht.h>
using namespace irr;
class TPlayerTank : public TTank
{
private:
	scene::ISceneNodeAnimator* mCollAnim;
	scene::ICameraSceneNode* mCamera;
	scene::IAnimatedMeshSceneNode* mTank;
	bool mLeftClick;
	scene::ISceneCollisionManager* mCollMan;
public:
	bool isRunning;
	bool leftClick();
	void leftClick(bool tclick);
	scene::ISceneNodeAnimator* animator();
	scene::ICameraSceneNode* camera();
	scene::IAnimatedMeshSceneNode* tank();
	scene::ISceneCollisionManager* collMan();
	void setAnimator(scene::ISceneNodeAnimator* tmp);//设置碰撞animator
	void setTankAnimator(io::path animFile, io::path textureFile);//设置坦克animator
	void letTankGround();//让坦克着地
	
	core::vector3df getPosition();
	TPlayerTank();
~TPlayerTank();
};

