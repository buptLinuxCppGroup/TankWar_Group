#include "TMath.h"
#include <iostream>

#define DOU(x) (x)*(x)

/*template <typename T>
T TMath::plusTwoVec3(const T s1, const T s2)
{
	T ans;
	ans.X = s1.X + s2.X;
	ans.Y = s1.Y + s2.Y;
	ans.Z = s1.Z + s2.Z;
	return ans;
}*/

core::vector3df TMath::plusTwoVec3(const core::vector3df s1, const core::vector3df s2)
{
	core::vector3df ans;
	core::vector3df normS2 = s2;
	//normS2.normalize();
	//ans.X = s1.X + normS2.X * 1000;
	//ans.Y = s1.Y + normS2.Y * 1000;
	//ans.Z = s1.Z + normS2.Z * 1000;
	ans.X = s1.X +  10;
	ans.Y = s1.Y +  30;
	ans.Z = s1.Z +  150;
	return ans;
}

core::vector3df TMath::minusTwoVec3(const core::vector3df s1, const core::vector3df s2)
{
	return core::vector3df(s1.X-s2.X,s1.Y-s2.Y,s1.Z-s2.Z);
}

void TMath::printV3df(const core::vector3df s)
{
	std::cerr << s.X << ' ' << s.Y << ' ' << s.Z << std::endl;
}

double TMath::getDistance(const core::vector3df d1, const core::vector3df d2)
{
	return sqrt(DOU(d1.X-d2.X) + DOU(d1.Y - d2.Y) + DOU(d1.Z - d2.Z));
}

core::vector3df TMath::dragScale(core::vector3df s,f32 fac)
{
	core::vector3df res = s;
	res.X = res.X*fac;
	res.Y = res.Y*fac;
	res.Z = res.Z*fac;
	return res;
}

TMath::TMath()
{
}


TMath::~TMath()
{
}
