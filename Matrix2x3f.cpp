#include "pch.h"
#include "Matrix2x3f.h"

Matrix2x3f::Matrix2x3f(Vector2f e1, Vector2f e2, Vector2f translation)
	: e1{ e1 }, e2{ e2 }, translation{ translation }
{
}

Matrix2x3f::Matrix2x3f(float e1X, float e1Y, float e2X, float e2Y, float translationX, float translationY)
	: e1{ Vector2f(e1X, e1Y) }, e2{ Vector2f(e2X, e2Y) }, translation{ Vector2f(translationX, translationY) }
{
}

Vector2f Matrix2x3f::Transform(const Vector2f& other) const
{
	return Vector2f(e1.x * other.x + e2.x * other.y + translation.x * 1, e1.y * other.x + e2.y * other.y + translation.y * 1);
}

std::string Matrix2x3f::ToString() const
{
	return "{" + std::to_string(e1.x) + ", " + std::to_string(e2.x) + ", " + std::to_string(translation.x) + 
		"},\n{" + std::to_string(e1.y) + ", " + std::to_string(e2.y) + ", " + std::to_string(translation.y) + "}";
}

Matrix2x3f Matrix2x3f::TranslationMatrix(Vector2f delta)
{
	return TranslationMatrix(delta.x, delta.y);
}

Matrix2x3f Matrix2x3f::TranslationMatrix(float dx, float dy)
{
	return Matrix2x3f(1, 0, 0, 1, dx, dy);
}

Matrix2x3f Matrix2x3f::RotationMatrix(float theta)
{
	return Matrix2x3f(cosf(theta), sinf(theta), -sinf(theta), cosf(theta), 0, 0);
}

Matrix2x3f Matrix2x3f::ScalingMatrix(float scaleX, float scaleY)
{
	return Matrix2x3f(scaleX, 0, 0, scaleY, 0, 0);
}
