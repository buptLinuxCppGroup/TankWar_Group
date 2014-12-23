#pragma once
#include "TMath.h"
#include "TGame.h"
#include <string>
#include <iostream>
class TInfo
{
public:

	TInfo()
	{
	}
	
	static void showWorldScale() {
		std::cerr << "showWorldScale" << std::endl;
		TMath::printV3df(TGame::world()->terrain()->getScale());
	}

	static void showTankSize() {
		std::cerr << "showTankSize" << std::endl;
		TMath::printV3df(TGame::player()->tank()->getScale());
	}

	static void showTankRotation() {
		std::cerr << "showTankRotation" << std::endl;
		TMath::printV3df(TGame::player()->tank()->getRotation());
	}

	static void showTankPos() {
		std::cerr << "showTankPos" << std::endl;
		TMath::printV3df(TGame::player()->tank()->getPosition());
	}

	static void showCameraPos() {
		std::cerr << "showCameraPos" << std::endl;
		TMath::printV3df(TGame::player()->camera()->getPosition());
	}

	static void showCameraTarget() {
		std::cerr << "showCameraTarget" << std::endl;
		TMath::printV3df(TGame::player()->camera()->getTarget());
	}


	~TInfo()
	{
	}
};

