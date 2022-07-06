#include "Button.h"

CButton::CButton(Vector2D InPosition, Vector2D InScale)
	: CUI(InPosition, InScale)
	, ButtonText("GAME")
{
	for (int i = 0; i < (int)BUTTON_STATE::MAX; ++i)
	{
		ButtonFuncPtr[i] = nullptr;
	}
}

CButton::~CButton()
{

}

void CButton::Render(HDC InHdc)
{
	CObject::Render(InHdc);

	// c_str() : vector<char> ������ string ������ char const* ���·� ��ȯ����
	TextOutA(InHdc, (int)(Position.x - (ButtonText.size() * 5.f)), (int)(Position.y), ButtonText.c_str(), (int)ButtonText.size());
	// ��Ʈ���� Ư¡�� �ٸ��� ���� ����� ���ĺ����� �۾��� ���̰� �ٸ�
}

void CButton::MouseFirstOn()
{

}

void CButton::MouseOn()
{

}

void CButton::MouseFirstOff()
{

}

void CButton::MouseLButtonPress()
{
	if (ButtonFuncPtr[(int)BUTTON_STATE::LBUTTON_PRESS])
		ButtonFuncPtr[(int)BUTTON_STATE::LBUTTON_PRESS]();
}

void CButton::MouseLButtonRelease()
{
	if (ButtonFuncPtr[(int)BUTTON_STATE::LBUTTON_RELEASE])
		ButtonFuncPtr[(int)BUTTON_STATE::LBUTTON_RELEASE]();
}

void CButton::MouseRButtonPress()
{
	if (ButtonFuncPtr[(int)BUTTON_STATE::RBUTTON_PRESS])
		ButtonFuncPtr[(int)BUTTON_STATE::RBUTTON_PRESS]();
}

void CButton::MouseRButtonRelease()
{
	if (ButtonFuncPtr[(int)BUTTON_STATE::RBUTTON_RELEASE])
		ButtonFuncPtr[(int)BUTTON_STATE::RBUTTON_RELEASE]();
}