#pragma once
#include "CSolarSystem.h"

class CEarth;
class CMoon :
    public CSolarSystem
{
private:
    Vector2D    mTarGetPosition;
    const CObject*    mEarth;  // Caching 매프레임 가져올경우 지정해둘수있음
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

