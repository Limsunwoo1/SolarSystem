#pragma once
#include "Object.h"
#include <vector>
class CSolarSystem :
    public CObject
{
protected:
    std::vector<Vector2D> Circle;
public:
    CSolarSystem();
    CSolarSystem(Vector2D InPsotion, Vector2D InScale);
    ~CSolarSystem();
public:

    virtual void Init(Vector2D InPosition);
};

