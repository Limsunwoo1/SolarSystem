#pragma once
#include "CSolarSystem.h"

class CEarth;
class CMoon :
    public CSolarSystem
{
private:
    Vector2D    mTarGetPosition;
    const CObject*    mEarth;  // Caching �������� �����ð�� �����صѼ�����
public:

    CMoon();
    CMoon(Vector2D InPosition, Vector2D InScale);
    ~CMoon();
public:
    virtual void Update(float InDeltaTime) override;

public:
    virtual void Init(Vector2D InPosition) override;
    void SetEarth(const CObject* InEarth);
};

