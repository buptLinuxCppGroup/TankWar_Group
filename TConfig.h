#pragma once
#include <string>
#include <ctime>
#include <irrlicht.h>
using namespace irr;
class TConfig
{
private:
	static core::vector3df TANKpos_MINUS_CAMERApos;
public:

	static bool showflag;

	//̹��mesh��texture·��
	static std::string TANK_3D_MESH_DIR;
	static std::string TANK_3D_TEXTURE_DIR;

	//ǹmesh��texture·��
	static std::string GUN1_3D_MESH_DIR;
	static std::string GUN1_3D_TEXTURE_DIR;

	//����mesh��texture·��
	static std::string MISSILE_3D_MESH_DIR;
	static std::string MISSILE_3D_TEXTURE_DIR;

	//�����ٶ�
	static f32 MISSILE_SPEED;

	//����������ʱ��͵�������ʱ��
	static double MISSILE_INTERVAL_TIME;
	static int MISSILE_EXIST_TIME;

	//���õ�����з�̹�˵����о���
	const static int MISSILE_TANK_DISTANCE = 400;

	//�ڵ��˺�
	static int MISSILE_DAMAGE1;
	const static int MISSILE_DAMAGE_AROUND = 400;

	//�ڵ���������
	static int MISSILE_KIND;

	//̹��Ѫ��������
	const static int MISSILE_HP_UP = 8000;
	const static int MISSILE_HP_DOWN = 5000;

	//̹�˳�ʼ��ת�Ƕ�
	static core::vector3df TANK_INIT_ROTATION;

	//̹����������ʱ��
	static time_t TANK_DIED_EXISTTIME;
	//û�õ�
	static core::vector3df getTANKpos_MINUS_CAMERApos();

	//����̹�����ľ���
	const static int FIRE_TANK_CENTER_DIS_X = 150;
	const static int FIRE_TANK_CENTER_DIS_Z = 250;
	const static int FIRE_TANK_CENTER_DIS_Y = 200;
	const static core::vector3df FIRE_TANK_CENTER_DIS;


	//��ɱ����̹�˵÷�
	const static int TANK_SCORE = 100;

	//̹�����Ŀ��ʱ�ĽǶ�����
	const static int TANK_ATTACK_RANGLE;
	const static f32 TANK_TARGET_ROTATION_ANGLE;

	//̹����Ե�ͼ�߶�����
	const static f32 TANK_INIT_HEIGHT;
	static core::vector3df st ;
	static core::vector3df ed ;

	//̹�˵ĳ�ʼ�ٶ�
	const static int TANK_INIT_SPEED = 5;

	//̹�˼�ľ���
	const static int TANK_DISTANCE = 550;
	TConfig();
~TConfig();
};

