#pragma once
#include "CSolarSystem.h"
#include <vector>
class CEarth :
    public CSolarSystem
{
public:
    std::vector<Vector2D> Ellipse;
public:
    CEarth();
    CEarth(Vector2D InPosition, Vector2D InScale);
    ~CEarth();
public:
    virtual void Render(HDC InHdc) override;
    virtual void Update(float InDeltaTime);
};

