#include "Moon.h"
#include "CSceneManager.h"
#define SPEED 300
CMoon::CMoon() : CSolarSystem(Vector2D{ 100,100 }, Vector2D{ 50,50 })
{

}

CMoon::CMoon(Vector2D InPosition, Vector2D InScale) : CSolarSystem(Vector2D{ InPosition.x,InPosition.y }, Vector2D{ InScale.x,InScale.y })
{

}

CMoon::~CMoon()
{

}

void CMoon::Update(float InDeltaTime)
{
	mDeltaTime += InDeltaTime * SPEED;

	if ((int)mDeltaTime >= 360)
		mDeltaTime -= 360;

	if (!mEarth)
		mEarth = CSceneManager::GetInstance()->Get_Object(OBJ_LAYER::EARTH)[0];

	Position.x = Circle[(int)mDeltaTime].x  + mEarth->GetPosition().x;
	Position.y = Circle[(int)mDeltaTime].y + mEarth->GetPosition().y;
}

void CMoon::Init(Vector2D InPosition)
{
	Vector2D PushVector;

	float length = UtilMath::Length(Vector2D(Position - InPosition));
	for (int angle = 0; angle < 360; angle++)
	{
		PushVector.x = (UtilMath::Cos(angle) * length);
		PushVector.y = (UtilMath::Sin(angle) * length);

		Circle.push_back(PushVector);
	}
}

void CMoon::SetEarth(const CObject* InEarth)
{
	mEarth = InEarth;
}