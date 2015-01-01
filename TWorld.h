#pragma once
#include <irrlicht.h>
#include "TPlayerTank.h"
#include "CGrassPatchSceneNode.h"
#include "CWindGenerator.h"
#include "Math.h"

using namespace irr;
using namespace core;                                         //Use the core namespace
using namespace scene;                                        //Use the scene namespace
using namespace video;                                        //Use the video namespace
using namespace io;                                           //Use the io namespace
using namespace gui;
using namespace std;

class TWorld
{
private:
	scene::ISceneNode *mSkybox, *mSkydome;
	//grass & wind
	scene::IWindGenerator *mWind;
	scene::CGrassPatchSceneNode **mGrass;
	s32 mGrassSize;
	
	//scene
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

	void loadCrossHair();

	void skybox(path top, path bottom, path left, path right, path front, path back);
	ISceneNode* skybox();
	void skydome(path file, u32 horiRes = 816U, u32 vertRes = 8U, f32 texturePercentage = 0.95f, f32 spherePercentage = 2.0f, f32 radius = 1000.f);

	void addGrass(s32 size, io::path phMap, io::path pgrassCol, io::path pgrassMap, io::path pgrassTex1, io::path pgrassTex2);
	CGrassPatchSceneNode** grassNode();


	void addTree2(io::path file,io::path file2,int count, TPlayerTank* player,core::vector3df scale = core::vector3df(60.f,60.f,60.f));

	TWorld(io::path terrainFile = "./data/terrain/terrain-heightmap.bmp");
    ~TWorld();
};

