#include <iostream>
#include <glm.hpp>
#include <memory>

#include "Screen.h"
#include "Camera.h"
#include "Tracer.h"
#include "Ray.h"
#include "Sphere.h"


int main()
{
	Screen screen;
	// Creates Screen
	screen.CreateScreen(glm::vec2(640, 480));

	Ray ray;
	Camera camera;
	Tracer tracer;
	glm::vec3 colour;
	Sphere sphere(glm::vec3(300, 200, 0), 50);
	Sphere sphere2(glm::vec3(500, 200, 0), 50);


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

				colour = sphere.RaySphereIntersec(&ray);

				//std::cout << ray.GetColourSet() << std::endl;
				colour = sphere2.RaySphereIntersec(&ray);

				screen.DrawPixel(x, y, colour);

			}
		}


		// Displays SDL contents
		screen.ShowScreen();

	}
	
	// Cleans up SDL
	screen.CloseScreen();

}