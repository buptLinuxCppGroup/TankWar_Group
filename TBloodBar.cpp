#include"TBloodBar.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

TBloodBar::TBloodBar(){
}

TBloodBar::TBloodBar(irr::IrrlichtDevice* mDevice, video::IVideoDriver* mDriver,int a1)
{
	irr::gui::IGUIEnvironment *guienv = mDevice->getGUIEnvironment();
	irr::gui::IGUIFont *font = guienv->getFont("lucida.xml");
	guienv->drawAll();
	static int damage1 = 0;
	damage1 = damage1 + a1;
	font->draw(L"HP", irr::core::rect<s32>(5, 15, 10, 35), irr::video::SColor(255, 0, 0, 0));
	if (damage1 < 200){
		mDriver->draw2DRectangle(irr::video::SColor(255, 255, 0, 0), irr::core::rect<s32>(30, 15, 230 - damage1, 35));
		mDriver->draw2DRectangle(irr::video::SColor(255, 255, 255, 255), irr::core::rect<s32>(230 - damage1, 15, 230, 35));
	}
	else{
		mDriver->draw2DRectangle(irr::video::SColor(255, 255, 255, 255), irr::core::rect<s32>(30, 15, 200, 35));
		cout << "game over" << endl;
	}

}

void TBloodBar::TBloodBarEnemy(irr::IrrlichtDevice* mDevice, video::IVideoDriver* mDriver, int a2)
{
	irr::gui::IGUIEnvironment *guienv = mDevice->getGUIEnvironment();
	irr::gui::IGUIFont *font = guienv->getFont("lucida.xml");
	guienv->drawAll();
	static int damage2 = 0;
	damage2 = damage2 + a2;
	font->draw(L"EnemyHP", irr::core::rect<s32>(500, 15, 10, 35), irr::video::SColor(255, 0, 0, 0));
	if (damage2 < 200){
		mDriver->draw2DRectangle(irr::video::SColor(255, 255, 0, 0), irr::core::rect<s32>(560, 15, 760 - damage2, 35));
		mDriver->draw2DRectangle(irr::video::SColor(255, 255, 255, 255), irr::core::rect<s32>(760 - damage2, 15, 760, 35));
	}
	else{
		mDriver->draw2DRectangle(irr::video::SColor(255, 255, 255, 255), irr::core::rect<s32>(560, 15, 760, 35));
		cout << "You have slain an enemy" << endl;
	}
}