���︺����ǻ��̣�ѩ�����ʹ�úͽ���,���Ƕ���һ�����ʽʵ�֣���ʹ�õĶ���particleSystem����ĺ���
1���������е������඼����ͬ�ģ�TFire,TSnow,TRain,TYan),��������һ�����޲ι��캯�����вι��캯������һ��setPosition����
2��ÿ����ֵ������ClassName(), ClassName(......) set(...)��������
3�����ã�createBoxEniter()������ʵ�֣�Ҫ�޸ĵ���Ҫ�����У����ӳ��ֵ�λ�ô�С�� ���ӷ���ÿ�����ӳ��ֵĸ����� �������Ӵ���ʱ��
    scene::IParticleEmitter* em = ps->createBoxEmitter(
		core::aabbox3d<f32>(-8, 0, -8, 8, 1, 8), // �������ӳ��ֵ�λ�õĴ�С
		core::vector3df(0.0f, 0.06f, 0.0f),   // ���ӵķ��� �� ѩ���ͻ�ķ���ͬ��
		80, 100,                             // ÿ�����ӷ���ĸ���80-100
		video::SColor(0, 255, 255, 255),       // darkest color
		video::SColor(0, 255, 255, 255),       // brightest color  ��ɫ��Χ
		800, 1200, 0,                         // �������Ӵ���ʱ�䣬�Ժ���Ϊ��λ
		core::dimension2df(10.f, 10.f),         // min size     
		core::dimension2df(20.f, 20.f));        // max size

	ps->setEmitter(em); // this grabs the emitter
        ps->setPosition(core::vector3df(x2, y2, z2));//��һ������ߣ��м��һ���Ǹߣ�����ұߣ���50Ϊ��λ�ƶ��ɣ���������ʵ���������
4�����ø���ʱ��ֻҪ��TGame.cpp��game loopǰ������һ��ʵ������������ʵ�� ���磺
        TFire T(mDevice, mSmgr, mDriver, 2587.99, 1050.624, 2260.09);
	TYan Y(mDevice, mSmgr, mDriver, 2587.99, 500.624, 2260.09);
	TSnow S(mDevice, mSmgr, mDriver, 2480.99, 1000.624, 2200.09);
	TRain R(mDevice, mSmgr, mDriver, 2480.99, 1000.624, 2300.09);
������