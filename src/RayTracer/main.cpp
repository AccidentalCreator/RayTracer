#include <iostream>
#include <glm.hpp>
#include <memory>
#include <vector>
#include <thread>
#include <mutex>
#include <time.h>

#include "Screen.h"
#include "Camera.h"
#include "Ray.h"
#include "Sphere.h"
#include "Geometry.h"
#include "Light.h"
#include "Tracer.h"
#include "Plane.h"
#include "Timer.h"

std::mutex mutex;

void TraceSection(int _minX, int _minY, int _maxX, int _maxY, std::vector<std::shared_ptr<Sphere>> _spheres, Camera _camera, Tracer _tracer, Screen _screen);

int main()
{
	Screen screen;
	// Creates Screen
	screen.CreateScreen(glm::vec2(640, 480));

	// Initialise random seed
	srand(time(NULL));

	bool finished = false;

	std::vector<std::thread> threads;

	// Lighting set up
	Light light;
	light.SetPosition(glm::vec3(640, screen.GetScreenSize().y / 2, -200));
	light.SetIntesity(glm::vec3(1, 1, 1));

	//std::shared_ptr<Plane> plane;
	//plane = std::make_shared<Plane>(glm::vec3(0, screen.GetScreenSize().y - 20, 0), glm::vec3(100, 10, 100), glm::vec3(1, 1, 1));

	// Set spheres
	std::vector<std::shared_ptr<Sphere>> spheres;
	spheres.push_back(std::make_shared<Sphere>(glm::vec3(450, 240, 200), 80, glm::fvec3(0, 0, 0.5f), light));
	spheres.push_back(std::make_shared<Sphere>(glm::vec3(200, 240, 200), 80, glm::fvec3(0.5f, 0, 0), light));
	spheres.push_back(std::make_shared<Sphere>(glm::vec3(330, 90, 200), 80, glm::fvec3(0.5f, 0, 0.5f), light));
	spheres.push_back(std::make_shared<Sphere>(glm::vec3(330, 390, 200), 80, glm::fvec3(0, 0.5f, 0), light));

	// Random Spheres
	//for (int i = 0; i < 25; i++)
	//{
	//	int x = rand() % 640;
	//	int y = rand() % 480;
	//	int z = 100 + rand() % 300;
	//	int r = 10 + rand() % 90;
	//	float rCol = (1 + rand() % 100);
	//	float gCol = (1 + rand() % 100);
	//	float bCol = (1 + rand() % 100);
	//	rCol /= 100;
	//	gCol /= 100;
	//	bCol /= 100;
	//	spheres.push_back(std::make_shared<Sphere>(glm::vec3(x, y, z), r, glm::fvec3(rCol, gCol, bCol), light));
	//}

	Timer timer;
	Tracer traceRay;
	Camera camera;

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

			//int noOfThreads = 5; // Number of threads = 2^noOfThreads
			//int stepX = screen.GetScreenSize().x / noOfThreads;
			//int stepY = screen.GetScreenSize().y / noOfThreads;

			// timer.StartCounter();
			//for (int y = 0; y < noOfThreads; y++)
			//{
			//	for (int x = 0; x < noOfThreads; x++)
			//	{
			//		threads.push_back(std::thread(TraceSection, stepX * x, stepY * y, (stepX * x) + stepX, (stepY * y) + stepY, spheres, camera, traceRay, screen));
			//	}
			//}
			//for (int i = 0; i < threads.size(); i++)
			//{
			//	threads.at(i).join();
			//}
			//std::cout << timer.GetCounter() << std::endl;


			// ---------- Multithreaded Job Pool ---------- 

			// Number of threads to be used
			int noOfThreads = 5;
			// Number of rows to be used
			int noOfSectionsX = 10;
			// Number of columns to be used
			int noOfSectionsY = 10;
			// The size of the sections
			int stepX = screen.GetScreenSize().x / noOfSectionsX;
			int stepY = screen.GetScreenSize().y / noOfSectionsY;
			bool threadsFinished = false;

			// Stores the top left position of each sections
			std::vector<glm::vec2> sections;
			for (int y = 0; y < noOfSectionsY; y++)
			{
				for (int x = 0; x < noOfSectionsX; x++)
				{
					sections.push_back(glm::vec2(stepX * x, stepY * y));
				}
			}

			// Start timer
			timer.StartCounter();
			// Creates the original threads
			for (int i = 0; i < noOfThreads; i++)
			{
				glm::vec2 position = sections.at(sections.size() - 1);
				threads.push_back(std::thread(TraceSection, position.x, position.y, position.x + stepX, position.y + stepY, spheres, camera, traceRay, screen));
				sections.pop_back();
				// Checks if all the sections have been traced
				if (sections.size() == 0)
				{
					threadsFinished = true;
					break;
				}
			}

			// Once a thread has finished it is given a new section to trace
			while (!threadsFinished)
			{
				for (int i = 0; i < threads.size(); i++)
				{
					if (threads.at(i).joinable())
					{
						glm::vec2 position = sections.at(sections.size() - 1);
						threads.push_back(std::thread(TraceSection, position.x, position.y, position.x + stepX, position.y + stepY, spheres, camera, traceRay, screen));
						sections.pop_back();

						// Checks if all the sections have been traced
						if (sections.size() == 0)
						{
							threadsFinished = true;
							break;
						}
					}
				}
			}

			for (int i = 0; i < threads.size(); i++)
			{
				threads.at(i).join();
			}

			// Output time taken
			std::cout << timer.GetCounter() << std::endl;
			

			// Displays SDL contents
			screen.ShowScreen();
			finished = true;
		}
	}
		// Cleans up SDL
		screen.CloseScreen();
}

void TraceSection(int _minX, int _minY, int _maxX, int _maxY, std::vector<std::shared_ptr<Sphere>> _spheres, Camera _camera, Tracer _tracer, Screen _screen)
{
	for (int y = _minY; y < _maxY; y++)
	{
		Geometry geometry;
		for (int x = _minX; x < _maxX; x++)
		{
			Ray ray = _camera.CreateRay(glm::vec3(x, y, 0));

			glm::fvec3 colour(0, 0, 0);
			_tracer.TraceRay(ray, geometry, _spheres, colour);

			ray.SetColour(colour);

			mutex.lock();
				_screen.DrawPixel(x, y, ray.GetColour());
			mutex.unlock();
		}
	}
}
