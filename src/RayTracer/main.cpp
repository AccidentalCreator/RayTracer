#include <iostream>
#include <glm.hpp>
#include <memory>
#include <vector>

#include "Screen.h"
#include "Camera.h"
#include "Tracer.h"
#include "Ray.h"
#include "Sphere.h"
#include "Geometry.h"


int main()
{
	Screen screen;
	// Creates Screen
	screen.CreateScreen(glm::vec2(640, 480));

	Ray ray;
	Ray reflectionRay;
	Camera camera;
	Tracer tracer;
	Geometry geometry;
	glm::vec3 colour;
	glm::vec3 reflectColour;
	//Sphere sphere(glm::vec3(300, 200, 0), 100, glm::vec3(0, 0, 1));
	//Sphere sphere2(glm::vec3(150, 200, 0), 100, glm::vec3(1, 0, 0));

	std::vector<Sphere*> spheres;
	spheres.push_back(new Sphere(glm::vec3(400, 200, 200), 100, glm::vec3(0, 0, 1)));
	spheres.push_back(new Sphere(glm::vec3(150, 200, 200), 100, glm::vec3(1, 0, 0)));

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
				ray = camera.CreateRay(glm::vec3(x, y, 0));
				for (int i = 0; i < spheres.size(); i++)
				{
					glm::vec3 point = geometry.ShortestDis(ray, *spheres.at(i), glm::vec3(0, 0, 0));

					// If point in sphere
					if (geometry.RaySphereIntersection())
					{
						// Find closest point
						point = geometry.ClosestPoint(ray, *spheres.at(i), point);
						colour = spheres.at(i)->ShadeSphere(ray, point);

						//// Reflection _________________________________________

						//reflectionRay = camera.CreateRay(point);
						//reflectionRay.SetDirection(geometry.Normalise(point));

						//for (int z = 0; z < spheres.size(); z++)
						//{
						//	if (i == z)
						//	{
						//		break;
						//	}

						//	glm::vec3 reflectPoint = geometry.ShortestDis(reflectionRay, *spheres.at(z), point);

						//	if (geometry.RaySphereIntersection())
						//	{
						//		//reflectColour = spheres.at(z)->GetColour();
						//		colour = glm::vec3(1, 1, 1);
						//		//colour += reflectColour;
						//	}
						//}

						colour = geometry.ConvertColour(colour);
						ray.SetColour(colour);
					}
					else
					{
						colour = ray.GetColour();
						ray.SetColour(colour);
					}
				}
				screen.DrawPixel(x, y, ray.GetColour());
			}
		}
		// Displays SDL contents
		screen.ShowScreen();
	}
	// Cleans up SDL
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