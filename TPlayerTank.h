#pragma once
#include "TTank.h"
#include <ctime>
#include <irrlicht.h>
#include "TMissile.h"
#include <queue>
#include <list>
#include <vector>
using namespace irr;
class TPlayerTank : public TTank
{
private:
	scene::ISceneNodeAnimator* mCollAnim;
	scene::ICameraSceneNode* mCamera;
	scene::IAnimatedMeshSceneNode* mTank;
	bool mLeftClick;
	scene::ISceneCollisionManager* mCollMan;

	time_t mLastMissileTime;

public:
	std::list<TMissile> mMissileQueue;

	bool isRunning;
	bool leftClick();
	void leftClick(bool tclick);

	bool timePermites();//�������ʱ���ѹ���cd��

	std::list<TMissile>& missileQueue();

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

