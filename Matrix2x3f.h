#pragma once
#include "Vector2f.h"

struct Matrix2x3f
{
	explicit Matrix2x3f() = default;
	explicit Matrix2x3f(Vector2f e1, Vector2f e2, Vector2f translation);
	explicit Matrix2x3f(float e1X, float e1Y, float e2X, float e2Y, float translationX, float translationY);

	Vector2f e1{}, e2{}, translation{};

	Vector2f Transform(const Vector2f& other) const;

	std::string ToString() const;

	static Matrix2x3f TranslationMatrix(Vector2f delta);
	static Matrix2x3f TranslationMatrix(float dx, float dy);

	static Matrix2x3f RotationMatrix(float theta);

	static Matrix2x3f ScalingMatrix(float scaleX, float scaleY);
};

