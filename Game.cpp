#include "pch.h"
#include "Game.h"

#include <iostream>

#include "Camera.h"
#include "Entity.h"
#include "Sprite.h"

std::string g_WindowTitle{ "Transformation Shenanigans - Nellessen, Patrick - 1DAE12" };

float g_WindowWidth{ 640 };
float g_WindowHeight{ 480 };

Camera* g_pCamera{};

Entity* g_pPlayer{};
Entity* g_pPlayerGun{};

Entity* g_pObstacle{};

Vector2f g_MouseScreenPos{};
Vector2f g_MouseWorldPos{};

float g_Time{};

//Basic game functions
#pragma region gameFunctions
void DrawWorldLine(Vector2f p1, Vector2f p2)
{
	utils::DrawLine(g_pCamera->WorldToScreenPos(p1).ToPoint2f(), g_pCamera->WorldToScreenPos(p2).ToPoint2f(), 3);
}

void Start()
{
	g_pCamera = new Camera();

	g_pPlayer = new Entity(new Sprite("Resources/box.png"));
	g_pPlayerGun = new Entity(new Sprite("Resources/box.png", 0.3f, Vector2f(0, 0.5f)), g_pPlayer);
	g_pPlayerGun->SetLocalScale(Vector2f(1.5f, 0.4f));
	g_pPlayer->Translate(Vector2f(g_WindowWidth / 2, g_WindowHeight / 2));

	g_pObstacle = new Entity(new Sprite("Resources/box.png"));
	g_pObstacle->Translate(Vector2f(600, 600));
	g_pObstacle->SetLocalScale(Vector2f(1, 5));
}

void Draw()
{
	utils::ClearBackground();

	g_pPlayer->Draw();
	g_pPlayerGun->Draw();

	g_pObstacle->Draw();

	std::cout << "PLAYER: " << g_pPlayer->GetLocalPosition().ToString() << '\n';

	std::cout << "MOUSE : " << g_MouseWorldPos.ToString() << '\n';
	std::cout << '\n';

	utils::SetColor(1, 0, 0, 1);
	DrawWorldLine(g_pPlayer->GetWorldPosition(), g_MouseWorldPos);
}

void Update(float deltaTime)
{
	g_Time += deltaTime;
	//g_pPlayer->Rotate(deltaTime);

	const Uint8* pStates{ SDL_GetKeyboardState(nullptr) };

	const float speed{ 200.f };
	if (pStates[SDL_SCANCODE_W])
	{
		// Move along the camera's Y-Axis etc.
		g_pPlayer->Translate(g_pCamera->GetCameraTransformation().e2 * speed * deltaTime);
	}
	else if (pStates[SDL_SCANCODE_S])
	{
		g_pPlayer->Translate(g_pCamera->GetCameraTransformation().e2 * -speed * deltaTime);
	}

	if (pStates[SDL_SCANCODE_D])
	{
		g_pPlayer->Translate(g_pCamera->GetCameraTransformation().e1 * speed * deltaTime);
	}
	else if (pStates[SDL_SCANCODE_A])
	{
		g_pPlayer->Translate(g_pCamera->GetCameraTransformation().e1 * -speed * deltaTime);
	}

	const float camSpeed{ 100.f };
	const float zoomSpeed{ 1.f };
	const float rotSpeed{ 1.f };

	if (pStates[SDL_SCANCODE_UP])
	{
		g_pCamera->Translate(Vector2f(0, camSpeed * deltaTime));
	}
	else if (pStates[SDL_SCANCODE_DOWN])
	{
		g_pCamera->Translate(Vector2f(0, -camSpeed * deltaTime));
	}
	else if (pStates[SDL_SCANCODE_RIGHT])
	{
		g_pCamera->Translate(Vector2f(camSpeed * deltaTime, 0));
	}
	else if (pStates[SDL_SCANCODE_LEFT])
	{
		g_pCamera->Translate(Vector2f(-camSpeed * deltaTime, 0));
	}

	if (pStates[SDL_SCANCODE_J])
	{
		g_pCamera->Rotate(rotSpeed * deltaTime);
	}
	else if (pStates[SDL_SCANCODE_L])
	{
		g_pCamera->Rotate(-rotSpeed * deltaTime);
	}

	if (pStates[SDL_SCANCODE_I])
	{
		g_pCamera->Scale(Vector2f(zoomSpeed * deltaTime, zoomSpeed * deltaTime));
	}
	else if (pStates[SDL_SCANCODE_K])
	{
		g_pCamera->Scale(Vector2f(-zoomSpeed * deltaTime, -zoomSpeed * deltaTime));
	}


	const Vector2f mouseWorldPos{ g_pCamera->ScreenToWorldPos(g_MouseScreenPos) };

	const Vector2f playerToMouse{ mouseWorldPos - g_pPlayer->GetWorldPosition() };
	g_pPlayerGun->SetLocalRotation(atan2f(playerToMouse.y, playerToMouse.x));

	g_MouseWorldPos = mouseWorldPos;
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

}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	const Vector2f mouseScreenPos{ Vector2f(static_cast<float>(e.x), g_WindowHeight - static_cast<float>(e.y)) };
	g_MouseScreenPos = mouseScreenPos;

	
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	const Vector2f mousePos{ Vector2f(static_cast<float>(e.x), g_WindowHeight - static_cast<float>(e.y)) };
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