<<<<<<< HEAD
#include"irrlicht.h"
#include"TFire.h"

TFire::TFire()
{
	this->x1 = 0;
	this->y1 = 0;
	this->z1 = 0;
}
TFire::TFire(IrrlichtDevice *device, scene::ISceneManager* smgr, video::IVideoDriver* mDriver, double x2, double y2, double z2)
{
	x1 = x2;
	y1 = y2;
	z1 = z2;
	scene::IParticleSystemSceneNode* ps = smgr->addParticleSystemSceneNode(false);
	scene::IParticleEmitter* em = ps->createBoxEmitter(
		core::aabbox3d<f32>(-8, 0, -8, 8, 1, 8), // 设置粒子出现的位置的大小
		core::vector3df(0.0f, 0.06f, 0.0f),   // 粒子的方向
		80, 100,                             // 每秒粒子发射的个数80-100
		video::SColor(0, 255, 255, 255),       // darkest color
		video::SColor(0, 255, 255, 255),       // brightest color  颜色范围
		800, 1200, 0,                         // 单个粒子存活的时间，以毫秒为单位
		core::dimension2df(10.f, 10.f),         // min size     
		core::dimension2df(20.f, 20.f));        // max size

	ps->setEmitter(em); // this grabs the emitter
	em->drop(); // so we can drop it here without deleting it

	scene::IParticleAffector* paf = ps->createFadeOutParticleAffector();

	ps->addAffector(paf); // same goes for the affector
	paf->drop();

	ps->setPosition(core::vector3df(x2, y2, z2));//第一个是左边，中间的一个是高，最后右边，以50为单位移动吧
	ps->setScale(core::vector3df(2, 2, 2));
	ps->setMaterialFlag(video::EMF_LIGHTING, false);
	ps->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	ps->setMaterialTexture(0, mDriver->getTexture("././media/fire.bmp"));
	ps->setMaterialType(video::EMT_TRANSPARENT_VERTEX_ALPHA);
}
void TFire::set(double x2, double y2, double z2)
{
	this->x1 = x2;
	this->y1 = y2;
	this->z1 =z2;
	
}
=======
#include "TFire.h"
#include "TEnemyTank.h"


TFire::TFire()
{
	/*minRate = 80;
	maxRate = 100;
	minLife = 800;
	maxLife = 1000;
	minSize = dimension2df(10.f,10.f);
	maxSize = dimension2df(20.f,20.f);
	texturePath = "../../media/fire.bmp";
	pos = vector3df(0,0,0);
	scale = vector3df(2,2,2);
	isFireNow = false;*/
	minRate = 80;
	maxRate = 100;
	minLife = 240;
	maxLife = 300;
	minSize = dimension2df(60.f, 60.f);
	maxSize = dimension2df(120.f, 120.f);
	texturePath = "../../media/fire.bmp";
	pos = vector3df(0, 0, 0);
	scale = vector3df(20, 20, 20);
	isFireNow = false;
	ps =TGame::smgr()->addParticleSystemSceneNode(false);
}

core::dimension2df TFire::getMinSize()
{
	return minSize;
}

core::dimension2df TFire::getMaxSize()
{
	return maxSize;
}

bool TFire::fireNow()
{
	return isFireNow;
}

void TFire::setRateRange(int tmin, int tmax)
{
	minRate = tmin;
	maxRate = tmax;
}

void TFire::setLifeRange(int tmin, int tmax)
{
	minLife = tmin;
	maxLife = tmax;
}

void TFire::setTexturePath(io::path t)
{
	texturePath = t;
}

void TFire::setSizeRange(core::dimension2df tmin, core::dimension2df tmax)
{
	minSize = tmin;
	maxSize = tmax;
}

void TFire::setPos(vector3df tpos)
{
	pos = tpos;
}

void TFire::setScale(vector3df tscale)
{
	scale = tscale;
}

void TFire::startFire()
{
	ps->setVisible(true);
	if (isFireNow) {
		return;
	}
	else {

		scene::IParticleEmitter* em = ps->createBoxEmitter(
			core::aabbox3d<f32>(-7, 0, -7, 7, 1, 7), // emitter size
			core::vector3df(0.0f, 0.06f, 0.0f),   // initial direction
			minRate, maxRate,                             // emit rate
			video::SColor(0, 255, 255, 255),       // darkest color
			video::SColor(0, 255, 255, 255),       // brightest color
			minLife, maxLife, 0,                         // min and max age, angle
			minSize,         // min size
			maxSize);        // max size

		ps->setEmitter(em); // this grabs the emitter
		em->drop(); // so we can drop it here without deleting it

		scene::IParticleAffector* paf = ps->createFadeOutParticleAffector();

		ps->addAffector(paf); // same goes for the affector
		paf->drop();

		ps->setPosition(pos);
		ps->setScale(scale);
		ps->setMaterialFlag(video::EMF_LIGHTING, false);
		ps->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
		ps->setMaterialTexture(0, TGame::driver()->getTexture(texturePath));
		ps->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
		
		isFireNow = true;
	}
}

void TFire::stopFire()
{
	ps->setVisible(false);
	//ps->setPosition(core::vector3df(0,0,0));
	isFireNow = false;
}

void TFire::resetFire()
{
	minRate = 80;
	maxRate = 80;
	minLife = 800;
	maxLife = 1000;
	minSize = dimension2df(10.f, 10.f);
	maxSize = dimension2df(20.f, 20.f);
	texturePath = "../../media/fire.bmp";
	pos = vector3df(0, 0, 0);
	scale = vector3df(2, 2, 2);
	stopFire();
}

void TFire::setSmallFire(vector3df tpos)
{
	
	minRate = 80;
	maxRate = 80;
	minLife = 800;
	maxLife = 2000;
	minSize = dimension2df(60.f, 60.f);
	maxSize = dimension2df(120.f, 120.f);
	texturePath = "../../media/fire.bmp";
	pos = tpos;
	scale = vector3df(20, 80, 20);
	isFireNow = false;
}

void TFire::setMiddleFire(vector3df tpos)
{
	
	minRate = 80;
	maxRate = 80;
	minLife = 800;
	maxLife = 2000;
	minSize = dimension2df(80.f, 80.f);
	maxSize = dimension2df(160.f, 160.f);
	texturePath = "../../media/fire.bmp";
	pos = tpos;
	scale = vector3df(40, 200, 40);
	isFireNow = false;
}

void TFire::setBigFire(vector3df tpos)
{
	
	minRate = 80;
	maxRate = 80;
	minLife = 800;
	maxLife = 2000;
	minSize = dimension2df(300.f, 300.f);
	maxSize = dimension2df(500.f, 500.f);
	texturePath = "../../media/fire.bmp";
	pos = tpos;
	scale = vector3df(80, 550, 80);
	isFireNow = false;
}


TFire::~TFire()
{
}
>>>>>>> c374e2dda2842502f0d47f20de3cd24c69857ce6
