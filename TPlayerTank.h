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
	void setAnimator(scene::ISceneNodeAnimator* tmp);//������ײanimator
	void setTankAnimator(io::path animFile, io::path textureFile);//����̹��animator
	void letTankGround();//��̹���ŵ�
	
	core::vector3df getPosition();
	TPlayerTank();
~TPlayerTank();
};

