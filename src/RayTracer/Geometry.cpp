#include "Geometry.h"
#include "Ray.h"
#include "Sphere.h"

glm::vec3 Geometry::ShortestDis(Ray _ray, Sphere _sphere)
{
	radius = _sphere.GetRadius();
	glm::vec3 camera = glm::vec3(0, 0, 0);

	a = _ray.origin - camera;
	p = _sphere.GetCenter() - camera;

	x = a + ((p - a) * _ray.direction) * _ray.direction;

	return x;
}

bool Geometry::RaySphereIntersection()
{
	distance = glm::length(p - x);
	if (distance <= radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}

glm::vec3 Geometry::ClosestPoint(Ray _ray, Sphere _sphere, glm::vec3 _point)
{
	float x = glm::sqrt((_sphere.GetRadius() * _sphere.GetRadius()) - (distance * distance));
	glm::vec3 closestPoint = a + (((p - a) * _ray.direction) - x) * _ray.direction;

	return closestPoint;
}

float Geometry::RayDistance(Ray _ray, glm::vec3 _center, int _radius)
{
	return 0.0f;
}

glm::vec3 Geometry::SphereNormal(glm::vec3 _center, glm::vec3 _point)
{
	return glm::vec3();
}
