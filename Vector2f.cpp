#include "pch.h"
#include "Vector2f.h"

Vector2f::Vector2f(float x, float y)
	: x{ x }, y{ y }
{
}

std::string Vector2f::ToString() const
{
	return "{" + std::to_string(x) + ", " + std::to_string(y) + "}";
}

float Vector2f::GetLength() const
{
	return sqrtf(x * x + y * y);
}

Vector2f Vector2f::GetNormalized() const
{
	const float len{ GetLength() };
	return Vector2f(x / len, y / len);
}

float Vector2f::Dot(const Vector2f& other) const
{
	return x * other.x + y * other.y;
}

Point2f Vector2f::ToPoint2f() const
{
	return Point2f(x, y);
}

Vector2f Vector2f::operator+(const Vector2f& other) const
{
	return Vector2f(x + other.x, y + other.y);
}

void Vector2f::operator+=(const Vector2f& other)
{
	x += other.x;
	y += other.y;
}
