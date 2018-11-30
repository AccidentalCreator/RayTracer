#pragma once
#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <glm.hpp>

class Ray;
class Sphere;

class Geometry
{
public:
	
	glm::vec3 ShortestDis(Ray _ray, Sphere _sphere, glm::vec3 _origin);
	glm::vec3 ClosestPoint(Ray _ray, Sphere _sphere);
	bool RaySphereIntersection();
	bool RayPlaneIntersection();
	glm::fvec3 ConvertColour(glm::fvec3 _colour);

private:
	glm::vec3 a;
	glm::vec3 p;
	glm::vec3 x;
	glm::vec3 intersection;

	float radius;

	float distance;
};

#endif // !GEOMETRY_H
