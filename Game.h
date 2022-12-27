#pragma once
class Camera;
class Entity;

#pragma region gameInformation
// Set your name and group in the title here
extern std::string g_WindowTitle;

// Change the window dimensions here
extern float g_WindowWidth;
extern float g_WindowHeight;

#pragma endregion gameInformation



#pragma region ownDeclarations
extern Camera* g_pCamera;

extern Entity* g_pPlayer;
extern Entity* g_pPlayerGun;

extern Entity* g_pObstacle;

extern Vector2f g_MouseScreenPos;
extern Vector2f g_MouseWorldPos;

extern float g_Time;

void DrawWorldLine(Vector2f p1, Vector2f p2);

#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float deltaTime);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
