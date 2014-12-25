#pragma once
#include <irrlicht.h>
#include <iostream>
#include <string>
#include "TPlayerTank.h"
#include "TMissile.h"
#include "TInfo.h"
#include "TMissile.h"
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
	void leftMouse(core::vector3df st, core::vector3df ed);
	void updateMissiles();
	void print_objApos_Minus_objBpos(scene::ISceneNode* a, scene::ISceneNode* b);
	void setStEd(core::vector3df& st, core::vector3df& ed) {
		if (isKeyDown(KEY_KEY_X)) {
			std::cerr << "press x" << std::endl;
			st = TGame::player()->camera()->getPosition();
		}
		if (isKeyDown(KEY_KEY_U)) {
			st.X += 0.1;
		}
		else if (isKeyDown(KEY_KEY_J)) {
			st.X -= 0.1;
		}
		else if (isKeyDown(KEY_KEY_O)) {
			st.Z += 0.1;
		}
		else if (isKeyDown(KEY_KEY_L)) {
			st.Z -= 0.1;
		}
		else if (isKeyDown(KEY_KEY_I)) {
			st.Y += 0.1;
		}
		else if (isKeyDown(KEY_KEY_K)) {
			st.Y -= 0.1;
		}
	}
	~TEvent();
};

