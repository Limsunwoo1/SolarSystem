#pragma once
#include "Object.h"
class CUI :
    public CObject
{
private:

public:
    CUI();
    CUI(Vector2D InPosition, Vector2D InScale);
    virtual ~CUI();

    virtual void Update(float InDeltaTime) override;
    virtual void Render(HDC InHdc) override;

    virtual void MouseFirstOn() {}            // ���콺�� �������� ���� ���
    virtual void MouseOn() {}                 // ���콺�� �������� ���� ���
    virtual void MouseFirstOff() {}           // ���콺�� ���� ���� ���� ��� ȣ��

                                              // Ŭ���� ��ư�� �������� ���� �߻��Ѵ�
    virtual void MouseLButtonPress() {}       // ���� ���콺 ��ư�� �������� ��
    virtual void MouseLButtonRelease() {}     // ���� ���콺 ��ư�� �������� ����
    virtual void MouseRButtonPress() {}       // ������ ���콺 ��ư�� �������� ��
    virtual void MouseRButtonRelease() {}     // ������ ���콺 ��ư�� �������� ����

public:
    static bool CheckMouseCollision(CUI* InUI);
};

