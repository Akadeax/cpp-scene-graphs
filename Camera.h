#pragma once
#include "Matrix2x3f.h"

class Camera
{
public:
	Matrix2x3f GetCameraTransformation() const;
	Matrix2x3f GetViewTransformation() const;

	void Translate(Vector2f deltaPos);
	void Rotate(float deltaAngle);
	void Scale(Vector2f deltaScale);

	Vector2f ScreenToWorldPos(Vector2f screenPos) const;
	Vector2f WorldToScreenPos(Vector2f screenPos) const;

	Vector2f GetScale() const;

private:
	Vector2f m_Position{ Vector2f(0, 0) };
	float m_Rotation{ 0 };
	Vector2f m_Scale{ Vector2f(1, 1) };
};

