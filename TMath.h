#pragma once
#include <irrlicht.h>
using namespace irr;
class TMath
{
public:
	//template<typename T> static T plusTwoVec3(const T s1, const T s2);
	static core::vector3df plusTwoVec3(const core::vector3df s1, const core::vector3df s2);
	static core::vector3df minusTwoVec3(const core::vector3df s1, const core::vector3df s2);
	static void printV3df(const core::vector3df s);
	static double getDistance(const core::vector3df d1, const core::vector3df d2);
	
	template<typename T> static T randomBetweenMinMax(T tMin, T tMax) {
		double tRandNum = rand()*1.0 / RAND_MAX;
		T ans = tMin + (tMax - tMin)*tRandNum;
		return ans;
	}

	static core::vector3df dragScale(core::vector3df s,f32 fac);
	TMath();
~TMath();
};


