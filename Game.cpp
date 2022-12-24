#include "pch.h"
#include "Game.h"

#include <iostream>

#include "Entity.h"
#include "Sprite.h"

std::string g_WindowTitle{ "Transformation Shenanigans - Nellessen, Patrick - 1DAE12" };

float g_WindowWidth{ 640 };
float g_WindowHeight{ 480 };

Entity* g_pPlayer{};
Entity* g_pPlayerGun{};

float g_Time{};

//Basic game functions
#pragma region gameFunctions
void Start()
{
	g_pPlayer = new Entity(new Sprite("Resources/box.png"));
	g_pPlayerGun = new Entity(new Sprite("Resources/box.png", 0.3f, Vector2f(0, 0.5f)), g_pPlayer);
	g_pPlayerGun->SetScale(Vector2f(1.5f, 0.4f));
	g_pPlayer->Translate(Vector2f(g_WindowWidth / 2, g_WindowHeight / 2));
}

void Draw()
{
	utils::ClearBackground();

	g_pPlayer->Draw();
	g_pPlayerGun->Draw();
}

void Update(float deltaTime)
{
	g_Time += deltaTime;
	//g_pPlayer->Rotate(deltaTime);
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
	Vector2f mousePos{ Vector2f(static_cast<float>(e.x), g_WindowHeight - static_cast<float>(e.y)) };

	Vector2f playerToMouse{ mousePos - g_pPlayer->GetWorldPosition() };
	g_pPlayerGun->SetLocalRotation(atan2f(playerToMouse.y, playerToMouse.x));
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