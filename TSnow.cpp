#include"irrlicht.h"
#include "TSnow.h"

TSnow::TSnow()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}
TSnow::TSnow(IrrlichtDevice *device, scene::ISceneManager* smgr, video::IVideoDriver* mDriver, double x1, double y1, double z1)
{
	x = x1;
	y = y1;
	z = z1;
	scene::IParticleSystemSceneNode* ps = smgr->addParticleSystemSceneNode(false);

	scene::IParticleEmitter* em = ps->createBoxEmitter(
		core::aabbox3d<f32>(-800, 0, -800, 800, 1, 800), // �������ӳ��ֵ�λ�õĴ�С
		core::vector3df(0.0f, -0.06f, 0.0f),   // ���ӵķ���
		100, 120,                             // ÿ�����ӷ���ĸ���80-100
		video::SColor(0, 255, 255, 255),       // darkest color
		video::SColor(0, 255, 255, 255),       // brightest color  ��ɫ��Χ
		50000, 300000, 0,                         // �������Ӵ���ʱ�䣬�Ժ���Ϊ��λ
		core::dimension2df(10.f, 10.f),         // min size     
		core::dimension2df(20.f, 20.f));        // max size

	ps->setEmitter(em); // this grabs the emitter
	em->drop(); // so we can drop it here without deleting it

	scene::IParticleAffector* paf = ps->createFadeOutParticleAffector();

	ps->addAffector(paf); // same goes for the affector
	paf->drop();

	ps->setPosition(core::vector3df(x, y, z));//��һ������ߣ��м��һ���Ǹߣ�����ұߣ���50Ϊ��λ�ƶ���
	ps->setScale(core::vector3df(2, 2, 2));
	ps->setMaterialFlag(video::EMF_LIGHTING, false);
	ps->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	ps->setMaterialTexture(0, mDriver->getTexture("././media/yan1.jpg"));
	ps->setMaterialType(video::EMT_TRANSPARENT_VERTEX_ALPHA);
}

void TSnow::set(double x1, double y1, double z1)
{
	x = x1;
	y = y1;
	z = z1;

}