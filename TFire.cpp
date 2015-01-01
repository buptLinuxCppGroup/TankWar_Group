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