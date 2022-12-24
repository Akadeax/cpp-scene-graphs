#include "pch.h"
#include "Sprite.h"

#include "Matrix2x3f.h"

Sprite::Sprite(const std::string& filePath, float pixelsPerUnit, Vector2f pivot)
	: m_PixelsPerUnit{ pixelsPerUnit },
	m_Pivot{ pivot }
{
	utils::TextureFromFile(filePath, m_Texture);
}

Sprite::~Sprite()
{
	utils::DeleteTexture(m_Texture);
}

void Sprite::Draw(const Vector2f& position, float angleRad, const Vector2f& scale, const Rectf& srcRect) const
{
	const float spriteScale{ (1.f / m_PixelsPerUnit) };
	utils::DrawTexture(m_Texture, m_Pivot, position, angleRad, scale * spriteScale);
}

Vector2f Sprite::GetPivot() const
{
	return m_Pivot;
}

void Sprite::SetPivot(Vector2f newPivot)
{
	m_Pivot = newPivot;
}

float Sprite::GetPixelsPerUnit() const
{
	return m_PixelsPerUnit;
}
