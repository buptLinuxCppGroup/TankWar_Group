#pragma once
#include <irrlicht.h>
#include <iostream>
#include <string>
#include "TPlayerTank.h"
#include "TInfo.h"
using namespace irr;
class TEvent : public IEventReceiver 
{
private:
	bool keyDown[KEY_KEY_CODES_COUNT];
	TPlayerTank* player;
public:
	TEvent(TPlayerTank* player);
	virtual bool OnEvent(const SEvent& event);
	virtual bool isKeyDown(EKEY_CODE keyCode) const;
	virtual bool isKeyUp(EKEY_CODE keyCode) const;
	void getRightRotation();
	void getRightPosition();
	void watchTankAnim();
	void showInfo();
	void moveTankPos();
	void moveTankRotation();
	void correctY();
	void leftMouse();
	void print_objApos_Minus_objBpos(scene::ISceneNode* a, scene::ISceneNode* b);
~TEvent();
};

