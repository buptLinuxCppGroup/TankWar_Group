#include "TEvent.h"
#include "TPlayerTank.h"
#include "TMath.h"
#include "TConfig.h"
#include <iostream>


TEvent::TEvent(TPlayerTank* tplayer)
{
	player = tplayer;
	for (int i = 0; i < KEY_KEY_CODES_COUNT; i++) {
		keyDown[i] = false;
	}
}

bool TEvent::OnEvent(const SEvent & event)
{
	switch (event.EventType) {
		case EET_KEY_INPUT_EVENT: {
			keyDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
			break;
		}
		case EET_MOUSE_INPUT_EVENT: {
			switch (event.MouseInput.Event)
			{
				case EMIE_LMOUSE_PRESSED_DOWN: {
					TGame::player()->leftClick(true);
					break;
				}
				case EMIE_LMOUSE_LEFT_UP: {
					TGame::player()->leftClick(false);
					break;
				}
				default:
					break;
			}
			break;
		}
		default:
			break;
	}
	return false;
}

bool TEvent::isKeyDown(EKEY_CODE keyCode) const
{
	return keyDown[keyCode];
}

bool TEvent::isKeyUp(EKEY_CODE keyCode) const
{
	return !keyDown[keyCode];
}



void TEvent::getRightRotation()
{
	if (isKeyDown(KEY_KEY_U)) {
		auto newPos = player->tank()->getRotation();
		newPos.X += 0.1;
		player->tank()->setRotation(newPos);
	}
	else if (isKeyDown(KEY_KEY_J)) {
		auto newPos = player->tank()->getRotation();
		newPos.X -= 0.1;
		player->tank()->setRotation(newPos);
	}
	else if (isKeyDown(KEY_KEY_I)) {
		auto newPos = player->tank()->getRotation();
		newPos.Y += 0.1;
		player->tank()->setRotation(newPos);
	}
	else if (isKeyDown(KEY_KEY_K)) {
		auto newPos = player->tank()->getRotation();
		newPos.Y -= 0.1;
		player->tank()->setRotation(newPos);
	}
	else if (isKeyDown(KEY_KEY_O)) {
		auto newPos = player->tank()->getRotation();
		newPos.Z += 0.1;
		player->tank()->setRotation(newPos);
	}
	else if (isKeyDown(KEY_KEY_L)) {
		auto newPos = player->tank()->getRotation();
		newPos.Z -= 0.1;
		player->tank()->setRotation(newPos);
	}
	else if (isKeyDown(KEY_KEY_M))
	{
		TMath::printV3df(player->tank()->getRotation());
	}
}

void TEvent::getRightPosition()
{
	if (this->isKeyDown(KEY_KEY_U)) {
		auto newPos = player->tank()->getPosition();
		newPos.X += 0.1;
		player->tank()->setPosition(newPos);
	}
	else if (this->isKeyDown(KEY_KEY_J)) {
		auto newPos = player->tank()->getPosition();
		newPos.X -= 0.1;
		player->tank()->setPosition(newPos);
	}
	else if (this->isKeyDown(KEY_KEY_I)) {
		auto newPos = player->tank()->getPosition();
		newPos.Y += 0.1;
		player->tank()->setPosition(newPos);
	}
	else if (this->isKeyDown(KEY_KEY_K)) {
		auto newPos = player->tank()->getPosition();
		newPos.Y -= 0.1;
		player->tank()->setPosition(newPos);
	}
	else if (this->isKeyDown(KEY_KEY_O)) {
		auto newPos = player->tank()->getPosition();
		newPos.Z += 0.1;
		player->tank()->setPosition(newPos);
	}
	else if (this->isKeyDown(KEY_KEY_L)) {
		auto newPos = player->tank()->getPosition();
		newPos.Z -= 0.1;
		player->tank()->setPosition(newPos);
	}
	else if (this->isKeyDown(KEY_KEY_M))
	{
		TMath::printV3df(player->tank()->getPosition());
	}
}

void TEvent::watchTankAnim()
{
	if (isKeyDown(KEY_KEY_W) || isKeyDown(KEY_KEY_S) || isKeyDown(KEY_KEY_A) || isKeyDown(KEY_KEY_D)) {
		
		if (!player->isRunning) {
			player->tank()->setMD2Animation(scene::EMAT_RUN);
			player->isRunning = true;
		}
		//player->tank()->setPosition(TMath::plusTwoVec3(TConfig::getTANKpos_MINUS_CAMERApos(),player->camera()->getPosition()));//�ı�̹��λ��
		//player->tank()->setPosition(player->camera()->getPosition());
		//player->letTankGround();

		//std::cerr << "1" << std::endl;
		//TMath::printV3df(player->camera()->getPosition());
		//std::cerr << "2" << std::endl;
		//TMath::printV3df(player->tank()->getPosition());
		//std::cerr << "3" << std::endl;
		//TMath::printV3df(TMath::minusTwoVec3(player->tank()->getPosition(), player->camera()->getPosition()));
		//std::cerr << "4" << std::endl;
		//TMath::printV3df(TConfig::getTANKpos_MINUS_CAMERApos());
	}
	else {
		player->isRunning = false;
		player->tank()->setMD2Animation(scene::EMAT_STAND);
	}

	

	
	
	//����x��z���꣬��̹�����
	//player->letTankGround();

	//��ӡ̹�˵���ת
	//TMath::printV3df(player->tank()->getRotation());
}

void TEvent::showInfo()
{
	if (isKeyDown(KEY_KEY_Z)) {
		TInfo::showCameraPos();
		//TInfo::showTankPos();
		//TInfo::showWorldScale();
		//TInfo::showCameraTarget();
	}
}

void TEvent::moveTankPos()
{
	//�ƶ����̹��
	auto nowpos = player->tank()->getPosition();
	if (isKeyDown(KEY_KEY_U)) {
		nowpos.X += 5;
	}
	else if (isKeyDown(KEY_KEY_J)) {
		nowpos.X -= 5;
	}
	else if (isKeyDown(KEY_KEY_O)) {
		nowpos.Z += 5;
	}
	else if (isKeyDown(KEY_KEY_L)) {
		nowpos.Z -= 5;
	}
	else if (isKeyDown(KEY_KEY_I)) {
		nowpos.Y += 5;
	}
	else if (isKeyDown(KEY_KEY_K)) {
		nowpos.Y -= 5;
	}
	player->tank()->setPosition(nowpos);
}

void TEvent::moveTankRotation()
{
	//��ת���̹��
	auto nowrota = player->tank()->getRotation();
	if (isKeyDown(KEY_KEY_V)) {
	nowrota.Y += 5;
	}
	else if (isKeyDown(KEY_KEY_N)) {
	nowrota.Y-= 5;
	}
	player->tank()->setRotation(nowrota);

}

void TEvent::correctY()
{
	auto target = TGame::player()->camera()->getTarget();
	while (target.Y >= 1700) target.Y -= 10;
	while (target.Y <= 400) target.Y += 10;
	TGame::player()->camera()->setTarget(target);
}

void TEvent::leftMouse()
{
	if (TGame::player()->leftClick()) {
		std::cerr << "cnm" << std::endl;
		core::line3d<f32> ray;
		ray.start = TGame::player()->camera()->getPosition();
		ray.end = ray.start + (TGame::player()->camera()->getTarget() - ray.start).normalize() * 500.0f;
		
		TGame::driver()->draw3DLine(ray.start,ray.end);
		
		core::vector3df intersection;
		core::triangle3df hitTriangle;
		scene::ISceneNode *node = 0;
		scene::ISceneNode * selectedSceneNode =
			TGame::player()->collMan()->getSceneNodeAndCollisionPointFromRay(
			ray,
			intersection,
			hitTriangle,
			0,
			0);
		if (selectedSceneNode) {
			std::cerr << "here" << std::endl;
			TMath::printV3df(selectedSceneNode->getPosition());
		}
	}
}

void TEvent::print_objApos_Minus_objBpos(scene::ISceneNode * a, scene::ISceneNode * b)
{
	if(isKeyDown(KEY_KEY_B))
		TMath::printV3df(TMath::minusTwoVec3(a->getPosition(),b->getPosition()));
}

TEvent::~TEvent()
{
}