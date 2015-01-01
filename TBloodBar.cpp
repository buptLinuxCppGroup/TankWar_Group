#include"TBloodBar.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
TBloodBar::TBloodBar(){
}

TBloodBar::TBloodBar(irr::IrrlichtDevice* mDevice, video::IVideoDriver* mDriver, int a){
	irr::gui::IGUIEnvironment *guienv = mDevice->getGUIEnvironment();
	irr::gui::IGUIFont *font = guienv->getFont("lucida.xml");
	guienv->drawAll();
	static int damage = 0;
	damage = damage + a;
	font->draw(L"HP", irr::core::rect<s32>(5, 15, 10, 35), irr::video::SColor(255, 0, 0, 0));
	if (damage < 200){
		mDriver->draw2DRectangle(irr::video::SColor(255, 255, 0, 0), irr::core::rect<s32>(30, 15, 200 - damage, 35));
		mDriver->draw2DRectangle(irr::video::SColor(255, 255, 255, 255), irr::core::rect<s32>(200 - damage, 15, 200, 35));
	}
	else{
		mDriver->draw2DRectangle(irr::video::SColor(255, 255, 255, 255), irr::core::rect<s32>(30, 15, 200, 35));
		cout << "game over" << endl;
	}
}