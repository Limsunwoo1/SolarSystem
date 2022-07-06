#include "Object.h"
#include "CTexture.h"
#include "Define.h"

unsigned int CObject::Id = 100;

static HPEN Green_Pen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
static HPEN Red_Pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
static HPEN Black_Pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));

static HBRUSH Null_Brush = (HBRUSH)GetStockObject(NULL_BRUSH);
static HBRUSH Default_Brush = CreateSolidBrush(RGB(255, 255, 255));

CObject::CObject()
	: Position()
	, Scale()
	, CollisionScale()
	, ObjectLayer(OBJ_LAYER::MAX)
	, Texture(nullptr)
{
	PrevCollision = false;
	CurCollision = false;
	ObjectId = Id++;
}
CObject::CObject(Vector2D InPosition, Vector2D InScale)
	: Position(InPosition)
	, Scale(InScale)
	, CollisionScale(InScale)
	, ObjectLayer(OBJ_LAYER::MAX)
	, Texture(nullptr)
{
	PrevCollision = false;
	CurCollision = false;
	ObjectId = Id++;
}

CObject::~CObject()
{

}

void CObject::SetTexture(CTexture* InTexture)
{
	Texture = InTexture;

	SetScale(Vector2D((int)Texture->GetWidth(), (int)Texture->GetHeight()));
	SetCollisionScale(Vector2D((int)Texture->GetWidth(), (int)Texture->GetHeight()));
}

void CObject::Update(float InDeltaTime)
{
	CurCollision = false;
}

void CObject::LateUpdate(float InDeltaTime)
{
	PrevCollision = CurCollision;
}

void CObject::Render(HDC InHdc)
{
	// ���İ� == ����
	// �����ϰ� ���°�, �������ϰ� ���°Ÿ� ���ĺ��� �̶�� �Ѵ�
	// ������ ���´ٴ� ������ �ǹ�

	// bmp ������ ���� ������ 24��Ʈ¥��
	// R : 8��Ʈ
	// G : 8��Ʈ
	// B : 8��Ʈ 0 ~ 255 ��
	// 32 ��Ʈ�� ���⿡ A : 8 ��Ʈ�� �߰��� �� ( ���İ� )

	if (Texture)
	{
		// 32��Ʈ bmp �� bf.AlphaFormat = AC_SRC_ALPHA
		// 24��Ʈ bmp �� bf.AlphaFormat = 0

		BLENDFUNCTION bf = {};
		bf.BlendOp = AC_SRC_OVER;
		bf.BlendFlags = 0;
		bf.AlphaFormat = 0;
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

		// Ư�� ������ ������ �ƿ� �׸��� �ʴ´�
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
	else
	{
		Rectangle(InHdc,
			(int)(Position.x - (Scale.x * 0.5f)),
			(int)(Position.y - (Scale.y * 0.5f)),
			(int)(Position.x + (Scale.x * 0.5f)),
			(int)(Position.y + (Scale.y * 0.5f)));
	}

#ifdef SHOW_COLLISION
	if (CurCollision)
		SelectObject(InHdc, Red_Pen);
	else
		SelectObject(InHdc, Green_Pen);
	SelectObject(InHdc, Null_Brush);

	Rectangle(InHdc,
		Position.x - (CollisionScale.x * 0.5f),
		Position.y - (CollisionScale.y * 0.5f),
		Position.x + (CollisionScale.x * 0.5f),
		Position.y + (CollisionScale.y * 0.5f));

	SelectObject(InHdc, Black_Pen);
	SelectObject(InHdc, Default_Brush);
#endif
}

void CObject::Collision(const CObject* InOtherObject)
{
	CurCollision = true;
}
