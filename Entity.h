#pragma once
#include "Vector2f.h"

class Entity
{
public:
	explicit Entity(std::vector<Vector2f> polygonModel, Entity* pParent = nullptr);

	void Draw() const;

	void Translate(Vector2f delta);
	void Rotate(float theta);

	Vector2f GetLocalPosition() const;
	float GetLocalRotation() const;

private:
	const std::vector<Vector2f> m_PolygonModel{};
	Entity* m_pParent{};

	Vector2f m_LocalPosition{};
	float m_LocalRotation{};
};
