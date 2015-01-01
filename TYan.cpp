#include "TYan.h"
#include "irrlicht.h"

TYan::TYan()
{

	this->x = 0;
	this->y = 0;
	this->z = 0;
}
TYan::TYan(IrrlichtDevice *device, scene::ISceneManager* smgr, video::IVideoDriver* mDriver, double x1, double y1, double z1)
{
	scene::IParticleSystemSceneNode* ps = smgr->addParticleSystemSceneNode(false);
	scene::IParticleEmitter* em = ps->createBoxEmitter(
		core::aabbox3d<f32>(-80, 0, -80, 80, 1, 80), // 设置粒子出现的位置的大小
		core::vector3df(0.0f, 0.06f, 0.0f),   // 粒子的方向
		800, 1000,                             // 每秒粒子发射的个数80-100
		video::SColor(0, 255, 255, 255),       // darkest color
		video::SColor(0, 255, 255, 255),       // brightest color  颜色范围
		2400, 4200, 0,                         // 单个粒子存活的时间，以毫秒为单位
		core::dimension2df(10.f, 10.f),         // min size     
		core::dimension2df(20.f, 20.f));        // max size

	ps->setEmitter(em); // this grabs the emitter
	em->drop(); // so we can drop it here without deleting it

	scene::IParticleAffector* paf = ps->createFadeOutParticleAffector();

	ps->addAffector(paf); // same goes for the affector
	paf->drop();

	ps->setPosition(core::vector3df(x1, y1, z1));//第一个是左边，中间的一个是高，最后右边，以50为单位移动吧
	ps->setScale(core::vector3df(2, 2, 2));
	ps->setMaterialFlag(video::EMF_LIGHTING, false);
	ps->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	ps->setMaterialTexture(0, mDriver->getTexture("././media/yan2.jpg"));
	ps->setMaterialType(video::EMT_TRANSPARENT_VERTEX_ALPHA);
}
void TYan::set(double x1, double y1, double z1)
{
	x = x1;
	y = y1;
	z = z1;
}