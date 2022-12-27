#include "pch.h"
#include "Entity.h"

#include <iostream>

#include "Matrix2x3f.h"
#include "Sprite.h"

Entity::Entity(const std::string& filePath, Entity* pParent)
	: m_pSprite{ new Sprite(filePath) },
	m_pParent{ pParent }
{
}

Entity::Entity(Sprite* pSprite, Entity* pParent)
	: m_pSprite{ pSprite },
	m_pParent{ pParent }
{
}

Entity::~Entity()
{
	delete m_pSprite;
}

void Entity::Draw() const
{
	m_pSprite->Draw(GetWorldPosition(), GetWorldRotation(), m_LocalScale);
}

void Entity::Translate(Vector2f delta)
{
	m_LocalPosition += delta;
}

void Entity::SetLocalPosition(Vector2f newPos)
{
	m_LocalPosition = newPos;
}

void Entity::Rotate(float theta)
{
	m_LocalRotation += theta;
}

void Entity::SetLocalRotation(float newRotation)
{
	m_LocalRotation = newRotation;
}

void Entity::Scale(Vector2f scaleFactor)
{
	m_LocalScale = Vector2f(m_LocalScale.x * scaleFactor.x, m_LocalScale.y * scaleFactor.y);
}

void Entity::SetLocalScale(Vector2f newScale)
{
	m_LocalScale = newScale;
}

Vector2f Entity::GetLocalPosition() const
{
	return m_LocalPosition;
}

float Entity::GetLocalRotation() const
{
	return m_LocalRotation;
}

float Entity::GetWorldRotation() const
{
	float totalRotation{ };
	const Entity* pCurrentParent{ this };
	while (pCurrentParent != nullptr)
	{
		totalRotation += pCurrentParent->GetLocalRotation();
		pCurrentParent = pCurrentParent->m_pParent;
	}

	return totalRotation;
}

Vector2f Entity::GetLocalScale() const
{
	return m_LocalScale;
}

// Get position after transformation of itself and all parents is applied
Vector2f Entity::GetWorldPosition() const
{
	Vector2f transformedPosition{};

	const Entity* pCurrentParent{ this };
	while (pCurrentParent != nullptr)
	{
		Matrix2x3f translation{ Matrix2x3f::TranslationMatrix(pCurrentParent->m_LocalPosition) };

		const Matrix2x3f rotation{ Matrix2x3f::RotationMatrix(pCurrentParent->m_LocalRotation) };
		const Vector2f scale{ Vector2f(1,1) * (1.f / pCurrentParent->GetSprite()->GetPixelsPerUnit()) };
		const Matrix2x3f scaling{ Matrix2x3f::ScalingMatrix(scale)};

		//std::cout << scale.ToString() << '\n';

		transformedPosition = scaling.Apply(transformedPosition);
		transformedPosition = rotation.Apply(transformedPosition);
		transformedPosition = translation.Apply(transformedPosition);

		pCurrentParent = pCurrentParent->m_pParent;
	}

	return transformedPosition;
}

void Entity::SetWorldPosition(Vector2f worldPos)
{
}

Sprite* Entity::GetSprite() const
{
	return m_pSprite;
}
