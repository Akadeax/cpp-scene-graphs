#pragma once
#include "Vector2f.h"

class Sprite;

class Entity
{
public:
	explicit Entity(const std::string& filePath, Entity* pParent = nullptr);
	explicit Entity(Sprite* pSprite, Entity* pParent = nullptr);
	~Entity();

	void Draw() const;

	void Translate(Vector2f delta);
	void SetLocalPosition(Vector2f newPos);

	void Rotate(float theta);
	void SetLocalRotation(float newRotation);

	void Scale(Vector2f scaleFactor);
	void SetScale(Vector2f newScale);

	Vector2f GetLocalPosition() const;
	Vector2f GetWorldPosition() const;

	float GetLocalRotation() const;
	float GetWorldRotation() const;

	Vector2f GetLocalScale() const;

	Sprite* GetSprite() const;

private:
	Sprite* m_pSprite{};
	Entity* m_pParent{};

	Vector2f m_LocalPosition{};
	float m_LocalRotation{};
	Vector2f m_LocalScale{ Vector2f(1, 1) };
};
