#include "Earth.h"
#include "CTexture.h"
#include "UtilMath.h"

#define SPEED 100
CEarth::CEarth() : CSolarSystem(Vector2D{ 100,100 }, Vector2D{ 50,50 })
{
	mDeltaTime = 0.0f;
}

CEarth::CEarth(Vector2D InPosition, Vector2D InScale) : CSolarSystem(Vector2D{ InPosition.x,InPosition.y }, Vector2D{ InScale.x,InScale.y })
{
	mDeltaTime = 0.0f;
}

CEarth::~CEarth()
{

}

void CEarth::Render(HDC InHdc)
{
	// 32비트 bmp 는 bf.AlphaFormat = AC_SRC_ALPHA
		// 24비트 bmp 는 bf.AlphaFormat = 0

	BLENDFUNCTION bf = {};
	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.AlphaFormat = AC_SRC_OVER;
	bf.SourceConstantAlpha = 255;

	AlphaBlend(InHdc,
		(int)(Position.x - (Texture->GetWidth() * 0.5f)),
		(int)(Position.y - (Texture->GetHeight() * 0.5f)),
		Texture->GetWidth(),
		Texture->GetHeight(),
		Texture->GetHdc(),
		0,
		0,
		Texture->GetWidth(),
		Texture->GetHeight(),
		bf);

	// 특정 영역의 색상을 아예 그리지 않는다
/*	TransparentBlt(InHdc,
		Position.x - (Texture->GetWidth() * 0.5f),
		Position.y - (Texture->GetHeight() * 0.5f),
		Texture->GetWidth(),
		Texture->GetHeight(),
		Texture->GetHdc(),
		0,
		0,
		Texture->GetWidth(),
		Texture->GetHeight(),
		RGB(0, 0, 0));*/

		//BitBlt(InHdc,
		//	Position.x - (Texture->GetWidth() * 0.5f),
		//	Position.y - (Texture->GetHeight() * 0.5f),
		//	//Scale.x,
		//	//Scale.y,
		//	Texture->GetWidth(),
		//	Texture->GetHeight(),
		//	Texture->GetHdc(),
		//	0,
		//	0,
		//	SRCCOPY);
}

void CEarth::Update(float InDeltaTime)
{
	mDeltaTime += InDeltaTime * SPEED;

	if((int)mDeltaTime >= 360)
		mDeltaTime -= 360;

	Position = Circle[(int)mDeltaTime];
}