#include "TEnemyTank.h"


std::vector<TEnemyTank> TEnemyTank::mEnemy = vector<TEnemyTank>();
TEnemyTank::TEnemyTank()
{
	setTankAnimator(TConfig::TANK_3D_MESH_DIR.c_str(), TConfig::TANK_3D_TEXTURE_DIR.c_str());
	//初始化血量
	mHp = TMath::randomBetweenMinMax(TConfig::MISSILE_HP_DOWN,TConfig::MISSILE_HP_UP);
	fullHp = mHp;
	mDied = false;
	mDiedTime = 0;
	mFire.setPos(mTank->getPosition());
	mSpeed = TConfig::TANK_INIT_SPEED;
	mLastMissileTime = 0;
}

bool TEnemyTank::died()
{
	return mDied;
}

TFire TEnemyTank::fire()
{
	return mFire;
}

void TEnemyTank::checkIfFire()
{
	auto firePos = mTank->getPosition();
	firePos += TConfig::FIRE_TANK_CENTER_DIS;
	if (mHp*1.0 / fullHp < 0.8) {
		mFire.setSmallFire(firePos);
		mFire.startFire();
	}
	if (mHp*1.0 / fullHp < 0.6) {
		mFire.setMiddleFire(firePos);
		mFire.startFire();
	}
	if (mHp*1.0 / fullHp < 0.3) {
		mFire.setBigFire(firePos);
		mFire.startFire();
	}
}

time_t TEnemyTank::diedTime()
{
	return mDiedTime;
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

void TEnemyTank::setSpeed(int spd)
{
	this->mSpeed = spd;
}

int TEnemyTank::Speed()
{
	return this->mSpeed;
}

vector3df TEnemyTank::updateTarget(vector3df playerPos)
{
	vector3df nodePos = playerPos - mTank->getPosition();
	float degree = atan(nodePos.Z / nodePos.X) * (180.0f / irr::core::PI);
	if ((this->mTank->getPosition().X - playerPos.X) > 0) {
		degree = 90 - degree;
	}
	else {
		degree = -90 - degree;
	}
	if (nodePos.X == 0.f) {
		return vector3df(0, 0, 0);
	}
	else {
		return vector3df(0, (float)degree + TConfig::TANK_TARGET_ROTATION_ANGLE, 0);
	}
}

vector3df TEnemyTank::updatePosition(vector3df playerPos, f32 attackRangle)
{
	vector3df myPos = mTank->getPosition(); 
	vector3df nodePos = playerPos - mTank->getPosition();
	float degree = atan(nodePos.Z / nodePos.X) ;
	if ((this->mTank->getPosition().X - playerPos.X) > 0) {
		degree = PI / 2 - degree;
	}
	else {
		degree = -PI / 2 - degree;
	}
	f32 xSpeed = abs(cos(degree)*mSpeed);
	f32 zSpeed = abs(sin(degree)*mSpeed);
	if (TMath::getDistanceXZ(myPos, playerPos) > attackRangle)
	{
		if (playerPos.X - myPos.X > attackRangle) myPos.X += xSpeed;
		else if (myPos.X - playerPos.X > attackRangle) myPos.X -= xSpeed;
		if (playerPos.Z - myPos.Z > attackRangle) myPos.Z += zSpeed;
		else if (myPos.Z - playerPos.Z > attackRangle) myPos.Z -= zSpeed;
	}
	myPos.Y = TGame::world()->terrain()->getHeight(myPos.X, myPos.Z)+TConfig::TANK_INIT_HEIGHT;
	return myPos;
}

vector3df TEnemyTank::updateRotation()
{
	vector3df A, B, C(0, 0, 0), t, XYt, AC, BC, myPos = mTank->getPosition(), vertocal(0,10,0);
	int table = 50;
	vector3df point[4];
	point[0] = vector3df(myPos.X - table, TGame::world()->terrain()->getHeight(myPos.X - table, myPos.Z + table) + TConfig::TANK_INIT_HEIGHT, myPos.Z + table);
	point[1] = vector3df(myPos.X - table, TGame::world()->terrain()->getHeight(myPos.X - table, myPos.Z - table) + TConfig::TANK_INIT_HEIGHT, myPos.Z - table);
	point[2] = vector3df(myPos.X + table, TGame::world()->terrain()->getHeight(myPos.X + table, myPos.Z + table) + TConfig::TANK_INIT_HEIGHT, myPos.Z + table);
	point[3] = vector3df(myPos.X + table, TGame::world()->terrain()->getHeight(myPos.X + table, myPos.Z - table) + TConfig::TANK_INIT_HEIGHT, myPos.Z - table);
	pair<int, int> op[2];
	op[0] = pair<int, int>(1, 3);
	op[1] = pair<int, int>(0, 2);

	int curIdx = 0;
	for (int i = 0; i < 4;i++)
	{
		if (C.Y < point[i].Y)
		{
			C = point[i];
			curIdx = i;
		}
	}
	A = point[op[curIdx % 2].first];
	B = point[op[curIdx % 2].second];
	AC = C - A;
	BC = B - A;
	t = TMath::getXMul(AC, BC);
	XYt = vector3df(t.X, t.Y, 0);
	f32 Zdegree = TMath::getAngle(XYt, vertocal)*(180 / PI);
	f32 Ydegree = TMath::getAngle(XYt, t)*(180 / PI);

	/*if (TConfig::showflag)
	{
		cout << "A: ";
		TMath::printV3df(A);
		cout << "B: ";
		TMath::printV3df(B);
		cout << "C: ";
		TMath::printV3df(C);
		cout << "AC: ";
		TMath::printV3df(AC);
		cout << "BC: ";
		TMath::printV3df(BC);
		cout << "R2:" << Ydegree << " " << Zdegree << endl;
		TConfig::showflag = false;
	}*/

	return vector3df(0, Ydegree, Zdegree);
}

void TEnemyTank::avoidCollide()
{
	for (int i = 0; i < mEnemy.size(); i++)
	{
		for (int j = i+1; j < mEnemy.size(); j++)
		{
			//if (i == j) continue;
			vector3df p1 = mEnemy[i].mTank->getPosition();
			vector3df p2 = mEnemy[j].mTank->getPosition();
			double degree = TMath::getAngle(p1, p2);
			//if (degree*(180 / PI) > 0 && degree*(180 / PI) < 180) {
			f32 xSpeed = abs(cos(degree)*mEnemy[i].mSpeed);
			f32 zSpeed = abs(sin(degree)*mEnemy[i].mSpeed);
			if (TMath::getDistance(p1, p2) < TConfig::TANK_DISTANCE)
			{
				/*if (p1.X - p2.X >= 0 && p1.X - p2.X < TConfig::TANK_DISTANCE) p1.X += xSpeed;
				else if (p2.X - p1.X > 0 && p2.X - p1.X < TConfig::TANK_DISTANCE) p1.X -= xSpeed;
				if (p1.Z - p2.Z >= 0 && p1.Z - p2.Z < TConfig::TANK_DISTANCE) p1.Z += zSpeed;
				else if (p2.Z - p1.Z > 0 && p2.Z - p1.Z < TConfig::TANK_DISTANCE) p1.Z -= zSpeed;*/
				vector3df tmp = p1 - p2;
				p1 += tmp * ((double)mEnemy[i].mSpeed/TConfig::TANK_DISTANCE);
			}
			mEnemy[i].mTank->setPosition(p1);
		}
	}

	if (TConfig::showflag )
	{
		for (int i = 0; i < mEnemy.size(); i++)
		{
			cout << "R" << i << ": ";
			cout << mEnemy[i].mTank->getPosition().X << " " << mEnemy[i].mTank->getPosition().Y << " " << mEnemy[i].mTank->getPosition().Z << endl;
		}
		TConfig::showflag = false;
	}
}

time_t TEnemyTank::lastMissileTime()
{
	return mLastMissileTime;
}

void TEnemyTank::setLastMissileTime(time_t s)
{
	mLastMissileTime= s;
}

void TEnemyTank::beAttacked()
{
	mHp -= TConfig::MISSILE_DAMAGE1+TMath::randomBetweenMinMax(0,TConfig::MISSILE_DAMAGE_AROUND);
	if (mHp < 0) {
		mDied = true;
		mDiedTime = time(NULL);
	}
	cerr << mHp << endl;
}

void TEnemyTank::reInit()
{
	core::vector3df newPos;
	core::aabbox3df modelBoundingBox = TGame::world()->terrain()->getBoundingBox();
	core::vector3df minEdgeExtended = modelBoundingBox.MinEdge;
	core::vector3df maxEdgeExtended = modelBoundingBox.MaxEdge;
	newPos.X = TMath::randomBetweenMinMax(minEdgeExtended.X,maxEdgeExtended.X);
	newPos.Z= TMath::randomBetweenMinMax(minEdgeExtended.X, maxEdgeExtended.X);
	newPos.Y = TGame::world()->terrain()->getHeight(newPos.X,newPos.Y)+TConfig::TANK_INIT_HEIGHT;
	mTank->setPosition(newPos);
	this->mSpeed = TConfig::TANK_INIT_SPEED;
	mHp = TMath::randomBetweenMinMax(TConfig::MISSILE_HP_DOWN,TConfig::MISSILE_HP_UP);
	fullHp = mHp;

	mFire.resetFire();
	
	mDied = false;
	mDiedTime = 0;

	mFire.stopFire();

	TGame::player()->scorePlus(TConfig::TANK_SCORE);
	cerr << "当前得分:" << TGame::player()->score() << endl;
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

	
	//mTank->setPosition(core::vector3df(2587.99, 550.624, 2260.09));
	core::vector3df newPos;
	core::aabbox3df modelBoundingBox = TGame::world()->terrain()->getBoundingBox();
	core::vector3df minEdgeExtended = modelBoundingBox.MinEdge;
	core::vector3df maxEdgeExtended = modelBoundingBox.MaxEdge;
	newPos.X = TMath::randomBetweenMinMax(minEdgeExtended.X, maxEdgeExtended.X);
	newPos.Z = TMath::randomBetweenMinMax(minEdgeExtended.X, maxEdgeExtended.X);
	newPos.Y = TGame::world()->terrain()->getHeight(newPos.X, newPos.Y)+TConfig::TANK_INIT_HEIGHT;
	mTank->setPosition(newPos);

	mTank->setScale(TMath::dragScale(mTank->getScale(),3));
	//mTank->setScale(core::vector3df(8,8,8));

	auto tankPos = mTank->getPosition();
	tankPos.Y = TGame::world()->terrain()->getHeight(tankPos.X, tankPos.Z)+TConfig::TANK_INIT_HEIGHT;
	mTank->setPosition(tankPos);
}

TEnemyTank::~TEnemyTank()
{
}
