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




	// Position
	Vector2f GetLocalPosition() const;
	void SetLocalPosition(Vector2f newPos);
	void Translate(Vector2f delta);

	Vector2f GetWorldPosition() const;
	void SetWorldPosition(Vector2f worldPos);

	// Rotation
	float GetLocalRotation() const;
	void SetLocalRotation(float newRotation);
	void Rotate(float theta);

	float GetWorldRotation() const;

	// Scale
	Vector2f GetLocalScale() const;
	void SetLocalScale(Vector2f newScale);
	void Scale(Vector2f scaleFactor);


	Sprite* GetSprite() const;

private:
	Sprite* m_pSprite{};
	Entity* m_pParent{};

	Vector2f m_LocalPosition{};
	float m_LocalRotation{};
	Vector2f m_LocalScale{ Vector2f(1, 1) };
};
