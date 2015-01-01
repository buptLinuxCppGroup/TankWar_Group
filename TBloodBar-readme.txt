两个函数  
TBloodBar(irr::IrrlichtDevice* mDevice, video::IVideoDriver* mDriver,int a1)为本体血条
void TBloodBarEnemy(irr::IrrlichtDevice* mDevice, video::IVideoDriver* mDriver, int a2)为敌方血条
a1  a2为受到的伤害
默认血量都是200，通过改矩形irr::core::rect<s32>的坐标参数可更改血量
掉血是通过绘制白色矩形来遮挡血条实现的
血条显示部分加在TGame.cpp中的 void TGame::run(TPlayerTank * player)函数里
mDriver->beginScene和mDriver->endScene()之间。