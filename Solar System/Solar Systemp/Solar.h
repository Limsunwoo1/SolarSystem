#pragma once
#include "CSolarSystem.h"
class CSolar :
    public CSolarSystem
{
public:
    CSolar();
    CSolar(Vector2D InPosition, Vector2D InSacle);
    ~CSolar();
};

