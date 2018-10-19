#include <iostream>
#include <glm.hpp>

#include "Screen.h"


int main()
{
	Screen screen;
	// Creates Screen
	screen.CreateScreen(glm::vec2(640, 480));

	bool running = true;

	while (running)
	{
		SDL_Event event = { 0 };

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}

		// Clear Screen / Set background Colour
		screen.ClearScreen();


		// Displays SDL contents
		screen.ShowScreen();

	}
	
	// Cleans up SDL
	screen.CloseScreen();

}