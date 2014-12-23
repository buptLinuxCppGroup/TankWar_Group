#pragma once
#include <irrlicht.h>
#include "TGame.h"
#include "TPlayerTank.h"
#include "TMath.h"
using namespace irr;
class THelp
{
public:
	THelp();
	static void showPlayerPos(TPlayerTank* player) {
		TMath::printV3df(player->camera()->getPosition());
	}
~THelp();
};

