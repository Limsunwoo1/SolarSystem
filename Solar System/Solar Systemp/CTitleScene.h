#pragma once
#include "CScene.h"

class CTitleScene :
    public CScene
{
protected:


public:

    CTitleScene();
    ~CTitleScene();

    virtual void Init() override;	// ������ �ʿ��� ������Ʈ���� ��ü���� �����ؼ� �����Ѵ�
    virtual void Clear() override;   // ���� ���� ������ ���� �Ҹ��Ų��

    virtual void Update(float InDeltaTime) override;
};

