#include "CTitleScene.h"
#include "Func.h"
#include "Button.h"
#include "Solar.h"
#include "Earth.h"
#include "Moon.h"
#include "CSceneManager.h"
#include "ResourceManager.h"
#include "UtilLog.h"
#include "Loger.h"
#include <string>

CTitleScene::CTitleScene() 
{
}

CTitleScene::~CTitleScene()
{

}

void CTitleScene::Init()
{
	CSolar* Solar = new CSolar(Vector2D{510, 480}, Vector2D{ 50, 50 });
	Solar->SetObjectLayer(OBJ_LAYER::SOLAR);
	Solar->SetTexture(CResourceManager::GetInstance()->FindTexture("SOLAR"));
	AddObject(OBJ_LAYER::SOLAR, Solar);
	
	CEarth* EARTH = new CEarth(Vector2D{ 510, 200 }, Vector2D{ 50, 50 });
	EARTH->SetObjectLayer(OBJ_LAYER::EARTH);
	EARTH->SetTexture(CResourceManager::GetInstance()->FindTexture("EARTH"));
	EARTH->Init(Solar->GetPosition());
	AddObject(OBJ_LAYER::EARTH, EARTH);

	CMoon* Moon = new CMoon(Vector2D{ 510, 50 }, Vector2D{ 50, 50 });
	Moon->SetObjectLayer(OBJ_LAYER::MOON);
	Moon->SetTexture(CResourceManager::GetInstance()->FindTexture("MOON"));
	Moon->Init(EARTH->GetPosition());
	Moon->SetEarth(EARTH);
	AddObject(OBJ_LAYER::MOON, Moon);

	// UI는 충돌체크하면 로직이 꼬일수도 있음 체크해도 UI 끼리만 하도록 주의
	std::vector<OBJ_LAYER> checkLayerList;
	checkLayerList.push_back(OBJ_LAYER::SOLAR);
	CheckCollisionLayer[OBJ_LAYER::EARTH] = checkLayerList;

	LOG("일반 로그 테스트");
	WARN_LOG("경고 로그 테스트");
	ERROR_LOG("에러 로그 테스트");
	ETC1_LOG("커스텀 로그 테스트");
}

void CTitleScene::Clear()
{	
	CScene::Clear();
}

void CTitleScene::Update(float InDeltaTime)
{
	CScene::Update(InDeltaTime);
}