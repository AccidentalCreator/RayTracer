#include <iostream>
#include <glm.hpp>

#include "Screen.h"
#include "Camera.h"
#include "Tracer.h"
#include "Ray.h"


int main()
{
	Screen screen;
	// Creates Screen
	screen.CreateScreen(glm::vec2(640, 480));

	Ray ray;
	Camera camera;
	Tracer tracer;
	glm::vec3 colour;

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

		for (int y = 0; y < screen.GetScreenSize().y; y++)
		{
			for (int x = 0; x < screen.GetScreenSize().x; x++)
			{
				// Creates ray
				ray = camera.CreateRay(glm::vec2(x, y));

				// Send Ray to tracer function
				colour = tracer.TraceRay(ray);

				screen.DrawPixel(x, y, colour);

			}
		}


		// Displays SDL contents
		screen.ShowScreen();

	}
	
	// Cleans up SDL
	screen.CloseScreen();

}