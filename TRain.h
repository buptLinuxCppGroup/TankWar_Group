#include "irrlicht.h"
using namespace irr;

class TRain{
private:
	double x, y, z;
public:
	TRain();
	TRain(IrrlichtDevice *device, scene::ISceneManager* smgr, video::IVideoDriver* mDriver, double x1, double y1, double z1);
	void set(double x1, double y1, double z1);
	//~TRain();
};