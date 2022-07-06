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
	
	// ����׿� Ŭ���� �ʱ�ȭ ����
#ifdef _DEBUG
	CLoger::GetInstance()->Init();
#endif
	//

	// �̱��ϵ� �ʱ�ȭ ����
	CResourceManager::GetInstance()->Init(HInstance, Hdc);
	CTimerManager::GetInstance()->Init();
	CKeyManager::GetInstance()->Init();
	CSceneManager::GetInstance()->Init();
	CCollisionManager::GetInstance()->Init();
	CEventManager::GetInstance()->Init();
	//

	// ������۸�
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

	// ��� ���� ������ ���� �Ŀ� �̺�Ʈ�� ó���ϰ� ���� �����ϵ���
	CEventManager::GetInstance()->Update(deltaTime);
}

void CMainGame::Update(float InDeltaTime)
{
	// ====================================
	CKeyManager::GetInstance()->Update(InDeltaTime);
	CSceneManager::GetInstance()->Update(InDeltaTime);
	CCollisionManager::GetInstance()->Update(InDeltaTime);
	// ====================================

	// Render �Ǳ� ������ ������ ������Ʈ
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

