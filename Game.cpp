#include "pch.h"
#include "Game.h"

#include <iostream>

#include "Entity.h"
#include "Matrix2x3f.h"

//Basic game functions
#pragma region gameFunctions
void Start()
{
	g_pPlayer = new Entity(std::vector<Vector2f>
	{
		Vector2f(20, 20),
		Vector2f(20, -20),
		Vector2f(-20, -20),
		Vector2f(-20, 20),
	});

	g_pPlayer->Translate(Vector2f(100, 100));

	g_pPlayerGun = new Entity(std::vector<Vector2f>
	{
		Vector2f(40, 5),
		Vector2f(40, -5),
		Vector2f(0, -5),
		Vector2f(0, 5),
	}, g_pPlayer);
}

void Draw()
{
	ClearBackground();

	SetColor(1, 1, 1, 1);
	g_pPlayer->Draw();
	SetColor(0, 0, 1, 1);
	g_pPlayerGun->Draw();

}

void Update(float deltaTime)
{
	g_pPlayer->Rotate(45 * (g_Pi / 180) * deltaTime);
	g_pPlayerGun->Rotate(45 * (g_Pi / 180) * deltaTime);
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions