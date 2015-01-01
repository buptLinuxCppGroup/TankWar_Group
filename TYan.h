#include"irrlicht.h"
using namespace irr;

class TYan{
private:
	double x, y, z;
public:
	TYan();
	TYan(IrrlichtDevice *device, scene::ISceneManager* smgr, video::IVideoDriver* mDriver, double x1, double y1, double z1);
	void set(double x1, double y1, double z1);
	//~TYan();
};