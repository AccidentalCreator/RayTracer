#include "Geometry.h"
#include "Ray.h"
#include "Sphere.h"

glm::vec3 Geometry::ShortestDis(Ray _ray, Sphere _sphere, glm::vec3 _origin)
{
	radius = _sphere.GetRadius();

	a = _ray.origin - _origin;
	p = _sphere.GetCenter() - _origin;

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

glm::vec3 Geometry::ConvertColour(glm::vec3 _colour)
{
	return glm::vec3(_colour.x * 255, _colour.y * 255, _colour.z * 255);
}

glm::vec3 Geometry::Normalise(glm::vec3 _point)
{
	glm::vec3 normal = glm::vec3(_point.x / _point.length(), _point.y / _point.length(), _point.z / _point.length());

	return normal;
}
