#include "MainGame.h"
#include "TimerManager.h"
#include "KeyManager.h"
#include "CSceneManager.h"
#include "Player.h"
#include "ResourceManager.h"
#include "CollisionManager.h"
#include "EventManager.h"
#include "Loger.h"
#include "Define.h"
#include <iostream>
#include <windows.h>

CMainGame::CMainGame()
	: Hdc(0)
	, BackHdc(0)
	, BitMap(0)
	, BackBitMap(0)
	, Hwnd(0)
	, HInstance(0)
{

}

CMainGame::~CMainGame()
{
	// ====================================
	SelectObject(BackHdc, BitMap);
	DeleteObject(BackBitMap);
	DeleteDC(BackHdc);
	// ====================================

	//delete Player;
}

void CMainGame::Init(HWND InHwnd, HINSTANCE InHInstance)
{
	// ====================================
	HInstance = InHInstance;
	Hwnd = InHwnd;
	Hdc = GetDC(Hwnd);
	
	// 디버그용 클래스 초기화 구간
#ifdef _DEBUG
	CLoger::GetInstance()->Init();
#endif
	//

	// 싱글턴들 초기화 구간
	CResourceManager::GetInstance()->Init(HInstance, Hdc);
	CTimerManager::GetInstance()->Init();
	CKeyManager::GetInstance()->Init();
	CSceneManager::GetInstance()->Init();
	CCollisionManager::GetInstance()->Init();
	CEventManager::GetInstance()->Init();
	//

	// 더블버퍼링
	BackHdc = CreateCompatibleDC(Hdc);
	BackBitMap = CreateCompatibleBitmap(Hdc, 1920, 1080);
	BitMap = (HBITMAP)SelectObject(BackHdc, BackBitMap);   
	// ====================================

	
}

void CMainGame::Logic()
{
	// ====================================
	CTimerManager::GetInstance()->Update();
	float deltaTime = CTimerManager::GetInstance()->GetDeltaTime();
	Update(deltaTime);
	Render();
	// ====================================

	// 모든 게임 로직이 끝난 후에 이벤트를 처리하고 새로 시작하도록
	CEventManager::GetInstance()->Update(deltaTime);
}

void CMainGame::Update(float InDeltaTime)
{
	// ====================================
	CKeyManager::GetInstance()->Update(InDeltaTime);
	CSceneManager::GetInstance()->Update(InDeltaTime);
	CCollisionManager::GetInstance()->Update(InDeltaTime);
	// ====================================

	// Render 되기 직전에 마지막 업데이트
	// ====================================
	CSceneManager::GetInstance()->LateUpdate(InDeltaTime);
	// ====================================
}

void CMainGame::Render()
{
	// ====================================
	Rectangle(BackHdc, 0, 0, WIDTH, HEIGHT);

	CSceneManager::GetInstance()->Render(BackHdc);

	BitBlt(Hdc, 0, 0, WIDTH, HEIGHT, BackHdc, 0, 0, SRCCOPY);
	// ====================================
}

