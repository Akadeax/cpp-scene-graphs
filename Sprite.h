#pragma once
#include "Vector2f.h"

class Sprite final
{
public:
	explicit Sprite(const std::string& filePath, float pixelsPerUnit = 0.25f, Vector2f pivot = Vector2f(0.5f, 0.5f));
	~Sprite();

	void Draw(const Vector2f& position, float angleRad = 0.f, const Vector2f& scale = Vector2f(1, 1), const Rectf& srcRect = {}) const;

	Vector2f GetPivot() const;
	void SetPivot(Vector2f newPivot);

	float GetPixelsPerUnit() const;
private:
	utils::Texture m_Texture{};

	float m_PixelsPerUnit{};
	Vector2f m_Pivot{};
};
