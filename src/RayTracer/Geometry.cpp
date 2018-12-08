#include "Geometry.h"
#include "Ray.h"
#include "Sphere.h"


IntersectionTest Geometry::RaySphereIntersection(Ray _ray, Sphere _sphere, glm::vec3 _origin)
{
	IntersectionTest queryPoint;

	float radius = _sphere.GetRadius();

	// Check if ray inside sphere

	float insideCheckDis = glm::length(_ray.origin - _sphere.GetCenter());

	// If inside sphere dont intersect
	if (insideCheckDis <= radius)
	{
		queryPoint.hit = false;
		return queryPoint;
	}



	// Shortist Distance Calculation

	glm::vec3 a = _ray.origin - _origin;
	glm::vec3 p = _sphere.GetCenter() - _origin;
	
	glm::vec3 rayDirNorm = glm::normalize(_ray.direction);

	// x is the shortest distance from point to line 
	glm::vec3 x = a + (glm::dot((p - a), rayDirNorm) * rayDirNorm);



	// Check if intersects with sphere

	float d = glm::length(p - a - glm::dot((p - a), rayDirNorm) *  rayDirNorm);

	float z = glm::sqrt((_sphere.GetRadius() * _sphere.GetRadius()) - (d * d));

	float intersecDis = (glm::dot((p - a), rayDirNorm) - z);

	if (intersecDis < 0)
	{
		queryPoint.hit = false;
		return queryPoint;
	}

	float distance = glm::length(p - x);
	if (distance <= radius)
	{
		queryPoint.hit = true;
	}
	else
	{
		queryPoint.hit = false;
		return queryPoint;
	}




	// Find closest point
	queryPoint.intersectPoint = a + (glm::dot((p - a), rayDirNorm) - z) * rayDirNorm;




	// Finds distance
	queryPoint.distance = glm::length(_ray.origin - queryPoint.intersectPoint);

	return queryPoint;
}


bool Geometry::RayPlaneIntersection()
{
	return false;
}

glm::fvec3 Geometry::ConvertColour(glm::fvec3 _colour)
{
	_colour = glm::clamp(_colour, glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
	return glm::fvec3(_colour.x * 255, _colour.y * 255, _colour.z * 255);
}
