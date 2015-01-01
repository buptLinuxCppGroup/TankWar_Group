#include"TMark.h"

TMark::TMark()
{
}

TMark::TMark(irr::IrrlichtDevice* mDevice, video::IVideoDriver* mDriver, int a)
{
	irr::gui::IGUIEnvironment *guienv = mDevice->getGUIEnvironment();
	irr::gui::IGUIFont *font = guienv->getFont("lucida.xml");
	guienv->drawAll();
	int score = 0;
	score = score + a;
	font->draw(L"Score", irr::core::rect<s32>(5, 40, 10, 60), irr::video::SColor(255, 0, 0, 0));
	font->draw((irr::core::stringw)score, irr::core::rect<s32>(50, 40, 80, 60), irr::video::SColor(255, 0, 0, 0));
}
