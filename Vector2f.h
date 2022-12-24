#pragma once
struct Vector2f
{
	explicit Vector2f() = default;
	explicit Vector2f(float x, float y);

	float x{}, y{};

	std::string ToString() const;

	float GetLength() const;
	Vector2f GetNormalized() const;

	float Dot(const Vector2f& other) const;

	Point2f ToPoint2f() const;

	bool operator==(const Vector2f& other) const;
	Vector2f operator+(const Vector2f& other) const;
	Vector2f operator-(const Vector2f& other) const;
	void operator+=(const Vector2f& other);
	Vector2f operator*(float scalar) const;

};
