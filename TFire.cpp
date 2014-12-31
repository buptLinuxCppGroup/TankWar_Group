#include "TFire.h"
#include "TEnemyTank.h"


TFire::TFire()
{
	minRate = 80;
	maxRate = 100;
	minLife = 800;
	maxLife = 1000;
	minSize = dimension2df(10.f,10.f);
	maxSize = dimension2df(20.f,20.f);
	texturePath = "../../media/fire.bmp";
	pos = vector3df(0,0,0);
	scale = vector3df(2,2,2);
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
	scene::IParticleSystemSceneNode* ps =
		TGame::smgr()->addParticleSystemSceneNode(false);

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

}


TFire::~TFire()
{
}
