#pragma once
#include "Vector2D.h"
#include <math.h>

#define PIE 3.141592f

// �ﰢ�Լ� ���� ���ǻ���
// sinf, cosf �� �ﰢ�Լ������ؼ� ���� ��� ���ڴ� ���� �� ( Radian ) �̿����Ѵ�.
// �츮�� ���� 0~360�� ��� ������ 10�����̶�� �ǹ��� ��׸� �� ( Degree )
// Radian �� ������ 0 ~ 360�� �� 0 ~ 2���� ������ ǥ���ȴ�.

// 0 ~ 180 ���� ���� => 0 ~ PIE ������ ������ ��ȯ�Ǵ� ���� ����ٰ� �Ҷ�
// 0 ���� �����ϴ� ��ʽ��� ¥�� �����
// Ư������/Ư�������� �ִ� �� * ��ʵǴ� ������� �ִ밪
// 
// Ư�� �� ���� �����ϴ� ��ʽ�
// 0 ���� �����ϰԲ� ��ʽ��� ����� ����
// Ư������/Ư�������� �ִ� �� * ��ʵǴ� ������� �ִ밪 + ��ʵǴ� ������� �ּҰ�

// minX ~ maxX �� ���� minY ~ maxY
// (X - minX) / (maxX - minX) * maxY + minY

namespace UtilMath
{
	inline float ToRaidan(float InDegree)
	{
		return InDegree * PIE / 180.f;
	}

	inline float ToDegree(float InRadian)
	{
		return InRadian * 180.f / PIE;
	}

	inline float Sin(float InDegree)
	{
		return sinf(ToRaidan(InDegree));
	}

	inline float Cos(float InDegree)
	{
		return cosf(ToRaidan(InDegree));
	}

	inline float Tan(float InDegree)
	{
		return tanf(ToRaidan(InDegree));
	}

	// ũ�Ⱑ 1�� ����ȭ�� ���ʹ� �븻����, ���⺤��, �������Ͷ�� �Ѵ�.
	inline Vector2D Normalize(const Vector2D& InVector)
	{
		float length = sqrtf((InVector.x * InVector.x) + (InVector.y * InVector.y));

		if (length != 0)
			return Vector2D(InVector.x / length, InVector.y / length);
		else
			return Vector2D(0.f, 0.f);
	}

	// ������ ������ ���Ѵ�.
	inline float DotProduct(const Vector2D& InVector1, const Vector2D& InVector2)
	{
		return InVector1 * InVector2;
	}

	inline float Length(const Vector2D& InVector1)
	{
		return sqrtf((InVector1.x * InVector1.x) + (InVector1.y * InVector1.y));
	}
}