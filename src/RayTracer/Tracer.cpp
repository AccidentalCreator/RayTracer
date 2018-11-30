#include "Tracer.h"
#include "Geometry.h"
#include "Ray.h"
#include "Sphere.h"

#include <iostream>

Tracer::Tracer()
{
	r = 0;
	camera = Camera();
}

Tracer::~Tracer()
{
}

void Tracer::reset()
{
	r = 0;
}

void Tracer::TraceRay(Ray _ray, Geometry _geometry, std::vector<std::shared_ptr<Sphere>> _spheres, glm::fvec3 &colour)
{
	for (int i = 0; i < _spheres.size(); i++)
	{
		glm::vec3 point;

		point = _geometry.ShortestDis(_ray, *_spheres.at(i), glm::vec3(0, 0, 0));

		// If point in sphere
		if (_geometry.RaySphereIntersection())
		{
			// Find closest point
			point = _geometry.ClosestPoint(_ray, *_spheres.at(i));

			// Reflection
			if (r == 1)
			{
				colour += 0.8f * _spheres.at(i)->SphereColour(_ray, point);
			}

			// Number of reflections
			if (r < 1)
			{
				colour = _spheres.at(i)->ShadeSphere(_ray, point, colour);
				//printf("1st: %f %f %f\n", colour.x, colour.y, colour.z);
				
				glm::vec3 reflectionVector = _spheres.at(i)->Reflection(_ray, point);
				_ray = camera.CreateRay(point);
				_ray.direction = reflectionVector;

				r++;
				TraceRay(_ray, _geometry, _spheres, colour);

				colour = glm::clamp(colour, glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
				colour = _geometry.ConvertColour(colour);
			}
		}
	}
}
