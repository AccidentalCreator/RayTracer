#include "Tracer.h"
#include "Geometry.h"
#include "Ray.h"
#include "Sphere.h"

#include <iostream>

Tracer::Tracer()
{
}

Tracer::~Tracer()
{
}


void Tracer::TraceRay(Ray _ray, Geometry _geometry, std::vector<std::shared_ptr<Sphere>> _spheres, glm::fvec3 &colour)
{
	for (int i = 0; i < _spheres.size(); i++)
	{
		IntersectionTest queryPoint = _geometry.RaySphereIntersection(_ray, *_spheres.at(i), glm::vec3(0, 0, 0));
		if (queryPoint.hit)
		{
			// Checks if hit another object first
			if (queryPoint.distance > _ray.intersecDist)
			{
				return;
			}

			// Reflection
			if (_ray.reflections == 1)
			{
				colour += 0.8f * _spheres.at(i)->ShadeSphere(_ray, queryPoint.intersectPoint);
			}
			
			// Number of reflections
			if (_ray.reflections < 1)
			{
				_ray.intersecDist = queryPoint.distance;
				colour = _spheres.at(i)->ShadeSphere(_ray, queryPoint.intersectPoint);
				_ray.direction = _spheres.at(i)->Reflection(_ray, queryPoint.intersectPoint);
				_ray.origin = queryPoint.intersectPoint;
				_ray.reflections++;

				TraceRay(_ray, _geometry, _spheres, colour);

				colour = _geometry.ConvertColour(colour);
			}
		}
	}

}
