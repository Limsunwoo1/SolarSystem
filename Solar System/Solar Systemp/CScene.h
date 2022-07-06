#pragma once
#include <vector>
#include <map>
#include "Object.h"
class CScene
{
public:
	typedef std::map<OBJ_LAYER, std::vector<OBJ_LAYER>> CollisionLayerInfo;
	typedef std::pair<OBJ_LAYER, std::vector<OBJ_LAYER>> CollisionLayerPair;

protected:
	std::vector<CObject*> OBJvector[(int)OBJ_LAYER::MAX];

	CollisionLayerInfo CheckCollisionLayer;
public:
	CScene();
	virtual ~CScene();

	virtual void Init();	// ������ �ʿ��� ������Ʈ���� ��ü���� �����ؼ� �����Ѵ�
	virtual void Clear();   // ���� ���� ������ ���� �Ҹ��Ų��

	virtual void Update(float InDeltaTime);
	virtual void LateUpdate(float InDeltaTime);

	void AddObject(OBJ_LAYER InLayer, CObject* InObject);
	void DeleteObject(OBJ_LAYER InLayer, CObject* InObject);

	const std::vector<CObject*>& Get_Object(OBJ_LAYER InLayer) const;

	const CollisionLayerInfo& GetCollisionLayer() {return CheckCollisionLayer;}

	void Render(HDC InHdc);
	void ClearObject();
};

