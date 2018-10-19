#include "Screen.h"

#include <iostream>
#include <exception>

void Screen::CreateScreen(glm::vec2 _screenSize)
{
	window = SDL_CreateWindow("RayTracer", 
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		_screenSize.x, _screenSize.y,
		SDL_WINDOW_RESIZABLE);

	if (!window)
	{
		throw std::exception();
	}

	renderer = SDL_CreateRenderer(window, -1, 0);

	if (!renderer)
	{
		throw std::exception();
	}
}

void Screen::ShowScreen()
{
	SDL_RenderPresent(renderer);
}

void Screen::ClearScreen()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Screen::CloseScreen()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}