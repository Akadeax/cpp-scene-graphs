#include "pch.h"
#include "Camera.h"
#include "Game.h"
#include <iostream>

Matrix2x3f Camera::GetCameraTransformation() const
{
	// TODO: Pivot?


	Matrix2x3f cam{ Matrix2x3f::Identity() };

	cam = cam.Apply(Matrix2x3f::TranslationMatrix(m_Position));
	cam = cam.Apply(Matrix2x3f::RotationMatrix(m_Rotation));
	cam = cam.Apply(Matrix2x3f::ScalingMatrix(m_Scale));

	return cam;
}

Matrix2x3f Camera::GetViewTransformation() const
{
	const Matrix2x3f cam{ GetCameraTransformation() };

	const Vector2f e1Norm{ cam.e1.GetNormalized() };
	const float e1Length{ cam.e1.GetLength() };

	const Vector2f e2Norm{ cam.e2.GetNormalized() };
	const float e2Length{ cam.e2.GetLength() };

	return Matrix2x3f(
		e1Norm.x / e1Length, e2Norm.x / e2Length,
		e1Norm.y / e1Length, e2Norm.y / e2Length,
		-e1Norm.Dot(m_Position) / e1Length, -e2Norm.Dot(m_Position) / e2Length
	);
}

void Camera::Translate(Vector2f deltaPos)
{
	m_Position += deltaPos;
}

void Camera::Rotate(float deltaAngle)
{
	m_Rotation += deltaAngle;
}

void Camera::Scale(Vector2f deltaScale)
{
	m_Scale += deltaScale;
}

Vector2f Camera::ScreenToWorldPos(Vector2f screenPos) const
{
	return GetCameraTransformation().Apply(screenPos);
}

Vector2f Camera::WorldToScreenPos(Vector2f screenPos) const
{
	return GetViewTransformation().Apply(screenPos);
}

Vector2f Camera::GetScale() const
{
	return m_Scale;
}
