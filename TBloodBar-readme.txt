��������  
TBloodBar(irr::IrrlichtDevice* mDevice, video::IVideoDriver* mDriver,int a1)Ϊ����Ѫ��
void TBloodBarEnemy(irr::IrrlichtDevice* mDevice, video::IVideoDriver* mDriver, int a2)Ϊ�з�Ѫ��
a1  a2Ϊ�ܵ����˺�
Ĭ��Ѫ������200��ͨ���ľ���irr::core::rect<s32>����������ɸ���Ѫ��
��Ѫ��ͨ�����ư�ɫ�������ڵ�Ѫ��ʵ�ֵ�
Ѫ����ʾ���ּ���TGame.cpp�е� void TGame::run(TPlayerTank * player)������
mDriver->beginScene��mDriver->endScene()֮�䡣