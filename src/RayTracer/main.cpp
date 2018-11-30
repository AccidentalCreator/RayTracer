#include <iostream>
#include <glm.hpp>
#include <memory>
#include <vector>

#include "Screen.h"
#include "Camera.h"
#include "Ray.h"
#include "Sphere.h"
#include "Geometry.h"
#include "Light.h"
#include "Tracer.h"
#include "Plane.h"


int main()
{
	Screen screen;
	// Creates Screen
	screen.CreateScreen(glm::vec2(640, 480));

	bool finished = false;

	Ray reflectionRay;
	Camera camera;
	Light light;
//	Geometry geometry;

	// Lighting set up
	light.SetPosition(glm::vec3(280, screen.GetScreenSize().y / 2, -500));
	light.SetIntesity(glm::vec3(1, 1, 1));

	std::shared_ptr<Plane> plane;
	plane = std::make_shared<Plane>(glm::vec3(0, screen.GetScreenSize().y - 20, 0), glm::vec3(100, 10, 100), glm::vec3(1, 1, 1));

	// Set spheres
	std::vector<std::shared_ptr<Sphere>> spheres;
	spheres.push_back(std::make_shared<Sphere>(glm::vec3(400, 200, 200), 100, glm::vec3(0, 0, 1), light));
	spheres.push_back(std::make_shared<Sphere>(glm::vec3(200, 200, 200), 100, glm::vec3(1, 0, 0), light));


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

		if (!finished)
		{

			// Clear Screen / Set background Colour
			screen.ClearScreen();

			int screenSizeY = screen.GetScreenSize().y;
			Tracer traceRay;

			//#pragma omp parallel
			//#pragma omp for 
			for (int y = 0; y < screenSizeY; y++)
			{
				Geometry geometry;
				for (int x = 0; x < screen.GetScreenSize().x; x++)
				{
					Ray ray = camera.CreateRay(glm::vec3(x, y, 0));


					glm::vec3 colour(0,0,0);
					traceRay.reset();
					traceRay.TraceRay(ray, geometry, spheres, colour);

					ray.SetColour(colour);

					//#pragma omp critical
					{
						screen.DrawPixel(x, y, ray.GetColour());
					}
				}
			}
			// Displays SDL contents
			screen.ShowScreen();
			finished = true;
		}
		// Cleans up SDL
	}
		screen.CloseScreen();
}


// Reflection _________________________________________

//ray = camera.CreateRay(glm::vec2(point.x, point.y));

//for (int z = 0; z < spheres.size(); z++)
//{
//	if (i == z)
//	{
//		break;
//	}

//	glm::vec3 reflectPoint = geometry.ShortestDis(ray, *spheres.at(z), point);

//	if (geometry.RaySphereIntersection())
//	{
//		reflectPoint = geometry.ClosestPoint(ray, *spheres.at(z), point);
//		colour += spheres.at(z)->ShadeSphere(ray, reflectPoint);
//	}
//}