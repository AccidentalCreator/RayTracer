#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2\SDL.h>
#include <glm.hpp>

class Screen
{
public:

	void CreateScreen(glm::vec2 _screenSize);
	void ClearScreen();
	void ShowScreen();
	void CloseScreen();

	void DrawPixel(int _x, int _y, glm::vec3 _colour);

	glm::vec2 GetScreenSize();

private:
	glm::vec2 screenSize;

	SDL_Window *window;
	SDL_Renderer *renderer;
};


#endif // !SCREEN_H

