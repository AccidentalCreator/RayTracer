#include "Geometry.h"
#include "Ray.h"
#include "Sphere.h"

glm::vec3 Geometry::ShortestDis(Ray _ray, Sphere _sphere, glm::vec3 _origin)
{
	radius = _sphere.GetRadius();

	a = _ray.origin -_origin;
	p = _sphere.GetCenter() - _origin;

	glm::vec3 dirNormal = glm::normalize(_ray.direction);

	x = a + ((p - a) * dirNormal) * dirNormal;

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

bool Geometry::RayPlaneIntersection()
{
	return false;
}

glm::vec3 Geometry::ClosestPoint(Ray _ray, Sphere _sphere)
{
	glm::vec3 dirNormal = glm::normalize(_ray.direction);

	float d = glm::length(p - a - glm::dot((p - a), dirNormal) *  dirNormal);

	float X = glm::sqrt((_sphere.GetRadius() * _sphere.GetRadius()) - (d * d));

	glm::vec3 closestPoint = a + (glm::dot((p - a), dirNormal) - X) * dirNormal;

	return closestPoint;
}

glm::fvec3 Geometry::ConvertColour(glm::fvec3 _colour)
{
	return glm::fvec3(_colour.x * 255, _colour.y * 255, _colour.z * 255);
}
