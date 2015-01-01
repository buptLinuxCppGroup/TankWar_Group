#include "TWorld.h"
#include "TGame.h"
#include "TPlayerTank.h"
#include "TMath.h"
#include <iostream>

scene::ITerrainSceneNode * TWorld::terrain()
{
	return mTerrain;
}

scene::ITriangleSelector * TWorld::selector()
{
	return mSelector;
}

scene::ILightSceneNode * TWorld::light()
{
	return mLight;
}

void TWorld::loadCrossHair()
{
	auto mCrosshair= TGame::driver()->getTexture("F:/linux/irrlicht-1.7.3/examples/02.Quake3Map/data/gun/crosshair.png");
	auto mColors = video::SColor(200, 200, 0, 0);
	s32 mCrosshairSize = 25;
	s32 rw = 1024;
	s32 rh = 768;
	TGame::driver()->draw2DImage(mCrosshair, rect<s32>(rw / 2 - mCrosshairSize, rh / 2 - mCrosshairSize, rw / 2 + mCrosshairSize, rh / 2 + mCrosshairSize), rect<s32>(0, 0, mCrosshair->getOriginalSize().Width, mCrosshair->getOriginalSize().Height),(rect<s32>*)0, &mColors, true);
	//TGame::driver()->draw2DImage()
}

CGrassPatchSceneNode ** TWorld::grassNode()
{
	return NULL;
}

void TWorld::addTree2(io::path file, io::path file2, int count , TPlayerTank* player, core::vector3df scale)
{
	mTreeMaterial.Lighting = true;
	this->mTreeCount = count;
	f32 treeX, treeZ;
	core::aabbox3df modelBoundingBox = mTerrain->getBoundingBox();
	core::vector3df minEdgeExtended = modelBoundingBox.MinEdge;
	core::vector3df maxEdgeExtended = modelBoundingBox.MaxEdge;

	mTrees2 = new scene::IMeshSceneNode*[mTreeCount];

	for (int i = 0; i < mTreeCount; i++) {
		if (i % 2 == 0) {
			mTrees2[i] = TGame::smgr()->addMeshSceneNode(TGame::smgr()->getMesh(file2));
		}
		else {
			mTrees2[i] = TGame::smgr()->addMeshSceneNode(TGame::smgr()->getMesh(file));
		}
		treeX = TMath::randomBetweenMinMax(minEdgeExtended.X,maxEdgeExtended.X);
		treeZ = TMath::randomBetweenMinMax(minEdgeExtended.X, maxEdgeExtended.X);
		mTrees2[i]->setScale(scale);
		mTrees2[i]->setPosition(core::vector3df(treeX,mTerrain->getHeight(treeX,treeZ),treeZ));
		mTrees2[i]->setMaterialFlag(video::EMF_LIGHTING,false);
		
		

		//auto* select = TGame::smgr()->createOctreeTriangleSelector(mTrees2[i]->getMesh(), mTrees2[i],128);
		//mTrees2[i]->setTriangleSelector(select);
		//select->drop();

		//auto node= TGame::smgr()->addOctreeSceneNode(player->tank()->getMesh());
		//auto* tmp=TGame::smgr()->createCollisionResponseAnimator(mTrees2[i]->getTriangleSelector(),player->camera(), mTrees2[i]->getScale() , core::vector3df(0.0f, 0.0f, 0.0f), core::vector3df(0, -400, 0));
		//player->camera()->addAnimator(tmp);
		//tmp->drop();
	}
}

void TWorld::addGrass(s32 size, path phMap, path pgrassCol, path pgrassMap, path pgrassTex1, path pgrassTex2) {
	video::ITexture *tex1;
	video::ITexture *tex2;

	mGrassSize = size;
	mWind = scene::createWindGenerator(30.0f, 3.0f);
	video::IImage* heightMap = TGame::driver()->createImageFromFile(phMap);// TGame::checkErrorFile(heightMap, "Error loading file: ", phMap);
	video::IImage* textureMap = TGame::driver()->createImageFromFile(pgrassCol);  //TGame::checkErrorFile(textureMap, "Error loading file: ", pgrassCol);
	video::IImage* grassMap = TGame::driver()->createImageFromFile(pgrassMap);// TGame::checkErrorFile(grassMap, "Error loading file: ", pgrassMap);
	mGrass = new CGrassPatchSceneNode*[size*size];
	tex1 = TGame::driver()->getTexture(pgrassTex1);	//TGame::checkErrorFile(tex1, "Error loading file: ", pgrassTex1);
	tex2 = TGame::driver()->getTexture(pgrassTex2);// TGame::checkErrorFile(tex2, "Error loading file: ", pgrassTex2);
	TGame::driver()->makeColorKeyTexture(tex2, core::position2d<s32>(0, 0));
	for (int x = 0; x<size; ++x) {
		for (int z = 0; z<size; ++z) {
			// add a grass node        
			mGrass[x*size + z] = new scene::CGrassPatchSceneNode(mTerrain, TGame::smgr(), -1, core::vector3d<s32>(x, 0, z), "grass", heightMap, textureMap, grassMap, mWind);
			mGrass[x*size + z]->setMaterialFlag(video::EMF_LIGHTING, false);
			//mGrass[x*size + z]->setMaterialFlag(video::EMF_FOG_ENABLE, this->fog());
			mGrass[x*size + z]->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF);
			mGrass[x*size + z]->getMaterial(0).TextureLayer[0].TextureWrapV = video::ETC_CLAMP;
			mGrass[x*size + z]->getMaterial(0).MaterialTypeParam = 0.5f;
			mGrass[x*size + z]->setMaterialTexture(0, tex1);
			mGrass[x*size + z]->setMaterialFlag(video::EMF_BACK_FACE_CULLING, true);	
			mGrass[x*size + z]->setDrawDistance(10000);
			mGrass[x*size + z]->setMaxDensity(100);
			mGrass[x*size + z]->drop();
		}
	}
}


TWorld::TWorld(io::path terrainFile)
{
	//地形准备
	this->mTerrain = TGame::smgr()->addTerrainSceneNode(terrainFile);
	this->mTerrain->setScale(core::vector3df(40,2.0f,40));
	this->mTerrain->setPosition(core::vector3df(0,0,0));
	this->mTerrain->setRotation(core::vector3df(0.f,0.f,0.f));
	this->mTerrain->setMaterialFlag(video::EMF_LIGHTING,false);
	this->mTerrain->setMaterialTexture(0,TGame::driver()->getTexture("F:/linux/irrlicht-1.7.3/examples/02.Quake3Map/data/terrain/ttex.jpg"));

	this->mTerrain->setMaterialType(video::EMT_DETAIL_MAP);
	this->mTerrain->scaleTexture(1.0f,20.0f);
	this->mTerrain->setMaterialFlag(video::EMF_FOG_ENABLE,false);
	this->mTerrain->setMaterialFlag(video::EMF_BACK_FACE_CULLING, true);
	this->mSelector = TGame::smgr()->createTerrainTriangleSelector(this->mTerrain,0);
	this->mTerrain->setTriangleSelector(this->mSelector);

	//灯光准备
	this->mLight = TGame::smgr()->addLightSceneNode();
}

void TWorld::skybox(path top, path bottom, path left, path right, path front, path back) {
	mSkybox = TGame::smgr()->addSkyBoxSceneNode(
		TGame::driver()->getTexture(top),		//up
		TGame::driver()->getTexture(bottom),	//down
		TGame::driver()->getTexture(left),		//left
		TGame::driver()->getTexture(right),		//right
		TGame::driver()->getTexture(front),		//front
		TGame::driver()->getTexture(back)		//back
		);
}

ISceneNode* TWorld::skybox() {
	return this->mSkybox;
}

void TWorld::skydome(path file, u32 horiRes, u32 vertRes, f32 texturePercentage, f32 spherePercentage, f32 radius) {
	mSkydome = TGame::smgr()->addSkyDomeSceneNode(TGame::driver()->getTexture(file), horiRes, vertRes, texturePercentage, spherePercentage, radius);
}


TWorld::~TWorld()
{
}
