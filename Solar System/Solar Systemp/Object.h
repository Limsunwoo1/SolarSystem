#pragma once
#include "framework.h"

class CTexture;

enum class OBJ_LAYER : short {
	BACKGROUND =	0,
	SOLAR	=		10,
	EARTH	=		15,
	MOON	=		20,
	MAX		=		32,
};

class CObject
{
	PROTECT_MEMBER(Vector2D, Position)

		PROTECT_MEMBER(Vector2D, Scale)

		PROTECT_MEMBER(Vector2D, CollisionScale)

		PROTECT_MEMBER(OBJ_LAYER, ObjectLayer)

private:
	static unsigned int Id;
	unsigned int ObjectId;

protected:
	CTexture*	Texture;

	bool		PrevCollision;
	bool		CurCollision;

	float		mDeltaTime;
public:
	CObject();
	CObject(Vector2D InPosition, Vector2D InScale);
	virtual ~CObject();

	virtual void Update(float InDeltaTime);
	virtual void LateUpdate(float InDeltaTime); // Render 되기 전 마지막 업데이트
	virtual void Render(HDC InHdc);

	virtual void Collision(const CObject* InOtherObject);
public:
	void SetTexture(CTexture* InTexture);

	unsigned int GetId() const { return ObjectId; }
};

