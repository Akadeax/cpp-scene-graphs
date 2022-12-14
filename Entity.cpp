#include "pch.h"
#include "Entity.h"

#include "Matrix2x3f.h"

Entity::Entity(std::vector<Vector2f> polygonModel, Entity* pParent)
	: m_PolygonModel{ polygonModel },
	m_pParent{ pParent }
{
}

void Entity::Draw() const
{
	const Entity* pCurrentParent{ this };
	std::vector<Vector2f> worldVectors(m_PolygonModel);

	while(pCurrentParent != nullptr)
	{
		Matrix2x3f translation{ Matrix2x3f::TranslationMatrix(pCurrentParent->m_LocalPosition) };
		Matrix2x3f rotation{ Matrix2x3f::RotationMatrix(pCurrentParent->m_LocalRotation) };

		for(int i{ 0 }; i < m_PolygonModel.size(); ++i)
		{
			worldVectors[i] = rotation.Transform(worldVectors[i]);
			worldVectors[i] = translation.Transform(worldVectors[i]);
		}

		pCurrentParent = pCurrentParent->m_pParent;
	}

	std::vector<Point2f> worldPoints(m_PolygonModel.size());
	for(int i{ 0 }; i < m_PolygonModel.size(); ++i)
	{
		worldPoints[i] = worldVectors[i].ToPoint2f();
	}

	utils::FillPolygon(worldPoints);
}

void Entity::Translate(Vector2f delta)
{
	m_LocalPosition += delta;
}

void Entity::Rotate(float theta)
{
	m_LocalRotation += theta;
}

Vector2f Entity::GetLocalPosition() const
{
	return m_LocalPosition;
}

float Entity::GetLocalRotation() const
{
	return m_LocalRotation;
}
