#pragma once
#include <irrlicht.h>
#include "TPlayerTank.h"
using namespace irr;
class TWorld
{
private:
	scene::ITerrainSceneNode* mTerrain;
	scene::ITriangleSelector* mSelector;

	//tree
	scene::IBillboardSceneNode** mTrees;
	scene::IMeshSceneNode** mTrees2;
	s32 mTreeCount;
	video::SMaterial mTreeMaterial;

	//light
	scene::ILightSceneNode* mLight;
public:
	scene::ITerrainSceneNode* terrain();
	scene::ITriangleSelector* selector();
	scene::ILightSceneNode* light();

	void addTree2(io::path file,io::path file2,int count, TPlayerTank* player,core::vector3df scale = core::vector3df(60.f,60.f,60.f));

	TWorld(io::path terrainFile = "./data/terrain/terrain-heightmap.bmp");
~TWorld();
};

