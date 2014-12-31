#include "TEvent.h"
#include "TPlayerTank.h"
#include "TMath.h"
#include "TConfig.h"
#include <iostream>
using namespace std;


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
		//player->tank()->setPosition(TMath::plusTwoVec3(TConfig::getTANKpos_MINUS_CAMERApos(),player->camera()->getPosition()));//改变坦克位置
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

	

	
	
	//给出x，z坐标，让坦克落地
	//player->letTankGround();

	//打印坦克的旋转
	//TMath::printV3df(player->tank()->getRotation());
}

void TEvent::showInfo()
{
	if (isKeyDown(KEY_KEY_Z)) {
		TInfo::showCameraPos();
		//TInfo::showTankPos();
		//TInfo::showWorldScale();
		//TInfo::showCameraTarget();
		TMath::printV3df(TConfig::st);
	}
}

void TEvent::moveTankPos()
{
	//移动这个坦克
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
	//旋转这个坦克
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

void TEvent::leftMouse(core::vector3df st,core::vector3df ed)
{
	if (TGame::player()->leftClick()) {
		//std::cerr << "cnm" << std::endl;
		core::line3d<f32> ray;
		ray.start = TGame::player()->camera()->getPosition();
		//ray.start.Y -= 1;
		ray.end = ray.start + (TGame::player()->camera()->getTarget() - ray.start).normalize() * 5000.0f;
		
		if (TGame::player()->timePermites()) {
			cerr << "permit" << endl;//Ok,能正常识别时间，每隔3秒允许
			TGame::player()->missileQueue().push_back(TMissile(TGame::player()->camera()->getPosition(), (TGame::player()->camera()->getTarget() - ray.start).normalize()));
			cerr << TGame::player()->missileQueue().size() << endl;
		}

		//TGame::driver()->draw3DLine(st, ed, video::SColor(255, 0, 0, 0));
		//TGame::driver()->draw3DLine(ray.start, st,video::SColor(255,0,0,0));
		TGame::driver()->draw3DLine(ray.start, ray.end, video::SColor(255, 0, 0, 0));

		if (isKeyDown(KEY_KEY_Z)) {
			std::cerr << "her" << std::endl;
			TMath::printV3df(ray.start);
		}

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
		//std::cerr << "look:" << std::endl;
		//TMath::printV3df(intersection);

		if (selectedSceneNode) {
			std::cerr << "here" << std::endl;
			TMath::printV3df(selectedSceneNode->getPosition());
			//TGame::driver()->draw3DTriangle(hitTriangle, video::SColor(0, 255, 0, 0));
		}
		else {
			std::cerr<<"蛤蛤没打中"<<endl;
		}
	}
}

void TEvent::updateMissiles()
{
	time_t nowTime = time(NULL);
	auto& missileList = TGame::player()->missileQueue();
	for (auto it = missileList.begin(); it != missileList.end();it++) {
		auto missile = *it;
		if (nowTime - missile.outTime() > TConfig::MISSILE_EXIST_TIME) {
			missile.drop();
			missileList.erase(it);
			break;
		}
		else {
			break;
		}
	}
	//cerr << missileList.size() << endl;
	for (auto& missile : missileList) {
		if (!missile.missile()->isVisible()) continue;
		missile.update();
		auto enemyList = TEnemyTank::enemy();
		for (auto& enemyTank : enemyList) {
			if (TMath::getDistance(missile.missile()->getPosition(), enemyTank.tank()->getPosition()) < TConfig::MISSILE_TANK_DISTANCE) {
				cerr << "hahahaha,打中了" << endl;
				missile.missile()->setVisible(false);
				break;
			}
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
