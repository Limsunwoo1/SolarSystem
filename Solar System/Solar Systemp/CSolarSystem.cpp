#include "CSolarSystem.h"

CSolarSystem::CSolarSystem() : CObject(Vector2D{ 100, 100 }, Vector2D{ 50, 50 })
{

}
CSolarSystem::CSolarSystem(Vector2D InPsotion, Vector2D InScale) : CObject(Vector2D{InPsotion.x, InPsotion.y}, Vector2D{ InScale.x, InScale.y })
{

}
CSolarSystem::~CSolarSystem()
{

}

void CSolarSystem::Init(Vector2D InPosition)
{
	Vector2D PushVector;

	float length = UtilMath::Length(Vector2D(Position - InPosition));
	for (int angle = 0; angle < 360; angle++)
	{
		PushVector.x = (UtilMath::Cos(angle) * length) + InPosition.x;
		PushVector.y = (UtilMath::Sin(angle) * length) + InPosition.y;

		Circle.push_back(PushVector);
	}
}