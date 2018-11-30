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

void Tracer::TraceRay(Ray _ray, Geometry _geometry, std::vector<std::shared_ptr<Sphere>> _spheres, glm::vec3 &colour)
{
	for (int i = 0; i < _spheres.size(); i++)
	{
		glm::vec3 point;

		point = _geometry.ShortestDis(_ray, *_spheres.at(i), glm::vec3(0, 0, 0));

		// If point in sphere
		if (_geometry.RaySphereIntersection())
		{
			// Find closest point
			point = _geometry.ClosestPoint(_ray, *_spheres.at(i), point);

			colour += _spheres.at(i)->ShadeSphere(_ray, point);

			if (r == 0)
			{
				glm::vec3 colour1 = _spheres.at(i)->ShadeSphere(_ray, point);
				//std::cout << "NotReflect: " << colour1.x << " " << colour1.y << " " << colour1.z << " " << std::endl;
			}
			if (r == 1)
			{
				glm::vec3 colour2 = _spheres.at(i)->ShadeSphere(_ray, point);
				//std::cout << "Reflect: " << colour2.x << " " << colour2.y << " " << colour2.z << " " << std::endl;
			}


			// Reflection

			//std::cout << reflectionVector.x << " " << reflectionVector.y << " " << reflectionVector.z << " " << std::endl;
			if (r < 2)
			{
				glm::vec3 reflectionVector = _spheres.at(i)->Reflection(_ray, point);
				_ray = camera.CreateRay(point);
				_ray.direction = reflectionVector;
				//std::cout << colour.x << " " << colour.y << " " << colour.z << " " << std::endl;
				//std::cout << r << std::endl;
				r++;
				TraceRay(_ray, _geometry, _spheres, colour);
			}

			colour = glm::clamp(colour, glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
			colour = _geometry.ConvertColour(colour);
			
		}
	}
	//return colour;
}
