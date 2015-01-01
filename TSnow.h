#include"irrlicht.h"
using namespace irr;

class TSnow{
private:
	double x, y, z;
public:
	TSnow();
	TSnow(IrrlichtDevice *device, scene::ISceneManager* smgr, video::IVideoDriver* mDriver, double x1, double y1, double z1);
	void set(double x1, double y1, double z1);
	//~TSnow();
};