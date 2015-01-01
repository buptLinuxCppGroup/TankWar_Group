这里负责的是火，烟，雪，雨的使用和介绍,他们都是一类的形式实现，所使用的都是particleSystem里面的函数
1、几乎所有的上述类都是相同的（TFire,TSnow,TRain,TYan),都包含了一个，无参构造函数，有参构造函数，和一个setPosition函数
2、每个类值包含了ClassName(), ClassName(......) set(...)三个函数
3、利用，createBoxEniter()函数来实现，要修改的主要参数有：粒子出现的位置大小， 粒子方向，每秒粒子出现的个数， 当个例子存活的时间
    scene::IParticleEmitter* em = ps->createBoxEmitter(
		core::aabbox3d<f32>(-8, 0, -8, 8, 1, 8), // 设置粒子出现的位置的大小
		core::vector3df(0.0f, 0.06f, 0.0f),   // 粒子的方向 （ 雪，和火的方向不同）
		80, 100,                             // 每秒粒子发射的个数80-100
		video::SColor(0, 255, 255, 255),       // darkest color
		video::SColor(0, 255, 255, 255),       // brightest color  颜色范围
		800, 1200, 0,                         // 单个粒子存活的时间，以毫秒为单位
		core::dimension2df(10.f, 10.f),         // min size     
		core::dimension2df(20.f, 20.f));        // max size

	ps->setEmitter(em); // this grabs the emitter
        ps->setPosition(core::vector3df(x2, y2, z2));//第一个是左边，中间的一个是高，最后右边，以50为单位移动吧，具体依据实际情况来定
4、调用该类时，只要在TGame.cpp的game loop前，传建一个实例（带参数的实例 例如：
        TFire T(mDevice, mSmgr, mDriver, 2587.99, 1050.624, 2260.09);
	TYan Y(mDevice, mSmgr, mDriver, 2587.99, 500.624, 2260.09);
	TSnow S(mDevice, mSmgr, mDriver, 2480.99, 1000.624, 2200.09);
	TRain R(mDevice, mSmgr, mDriver, 2480.99, 1000.624, 2300.09);
就行了