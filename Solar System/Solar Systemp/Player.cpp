#include "Player.h"
#include "KeyManager.h"
#include "CSceneManager.h"
#include "ResourceManager.h"
#include "EventManager.h"
#include "CTexture.h"

CPlayer::CPlayer() : CObject(Vector2D{ 100, 100 }, Vector2D{ 50, 50 })
{

}

CPlayer::CPlayer(Vector2D InVector, Vector2D InScale) : CObject(Vector2D{ InVector.x , InVector.y }, Vector2D{ InScale.x, InScale.y })
{

}

CPlayer::~CPlayer()
{

}

void CPlayer::Update(float InDeltaTime)
{
	CObject::Update(InDeltaTime);

	int SPEED = 1000;
	if (KEY_STATE(KEY::A) == KEY_STATE::HOLD)
	{
		Vector2D position = Position;
		position.x -= SPEED * InDeltaTime;

		if (position.x < 20)
		{
			position.x = 20;
		}

		Position = position;
	}

	if (KEY_STATE(KEY::D) == KEY_STATE::HOLD)
	{
		Vector2D position = Position;
		position.x += SPEED * InDeltaTime;

		if (position.x > 940)
		{
			position.x = 940;
		}

		Position = position;
	}
}

void CPlayer::Collision(const CObject* InOtherObject)
{
	CObject::Collision(InOtherObject);

	/*EventInfo eventInfo;
	eventInfo.Type = EVENT_TYPE::DELETE_OBJECT;
	eventInfo.Parameter = new OBJ_LAYER(ObjLayer);
	eventInfo.Parameter2 = this;
	CEventManager::GetInstance()->AddEvent(eventInfo);*/
}

void CPlayer::Render(HDC InHdc)
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
	}
	else
	{
		Rectangle(InHdc,
			(int)(Position.x - (Scale.x * 0.5f)),
			(int)(Position.y - (Scale.y * 0.5f)),
			(int)(Position.x + (Scale.x * 0.5f)),
			(int)(Position.y + (Scale.y * 0.5f)));
	}
}