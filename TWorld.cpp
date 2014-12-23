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
		
		

		auto* select = TGame::smgr()->createOctreeTriangleSelector(mTrees2[i]->getMesh(), mTrees2[i],128);
		mTrees2[i]->setTriangleSelector(select);
		select->drop();

		//auto node= TGame::smgr()->addOctreeSceneNode(player->tank()->getMesh());
		auto* tmp=TGame::smgr()->createCollisionResponseAnimator(mTrees2[i]->getTriangleSelector(),player->camera(), mTrees2[i]->getScale() , core::vector3df(0.0f, 0.0f, 0.0f), core::vector3df(0, -400, 0));
		player->camera()->addAnimator(tmp);
		tmp->drop();
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
	this->mTerrain->setMaterialTexture(0,TGame::driver()->getTexture("./data/terrain/ttex.jpg"));
	this->mTerrain->setMaterialTexture(0, TGame::driver()->getTexture("./data/terrain/tdec.jpg"));
	this->mTerrain->setMaterialType(video::EMT_DETAIL_MAP);
	this->mTerrain->scaleTexture(1.0f,20.0f);
	this->mTerrain->setMaterialFlag(video::EMF_FOG_ENABLE,false);
	this->mTerrain->setMaterialFlag(video::EMF_BACK_FACE_CULLING, true);
	this->mSelector = TGame::smgr()->createTerrainTriangleSelector(this->mTerrain,0);
	this->mTerrain->setTriangleSelector(this->mSelector);
	this->mTerrain->setScale((TMath::dragScale(mTerrain->getScale(),3)));

	//灯光准备
	this->mLight = TGame::smgr()->addLightSceneNode();
}

TWorld::~TWorld()
{
}
