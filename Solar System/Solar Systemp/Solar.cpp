#include "Solar.h"

CSolar::CSolar() : CSolarSystem(Vector2D{100,100}, Vector2D{ 50,50 })
{
	
}

CSolar::CSolar(Vector2D InPosition, Vector2D InScale) : CSolarSystem(Vector2D{ InPosition.x,InPosition.y }, Vector2D{ InScale.x,InScale.y })
{

}

CSolar::~CSolar()
{

}

