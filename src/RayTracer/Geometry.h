#pragma once
#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <glm.hpp>

class Ray;
class Sphere;

class Geometry
{
public:
	
	glm::vec3 ShortestDis(Ray _ray, Sphere _sphere);
	glm::vec3 ClosestPoint(Ray _ray, Sphere _sphere, glm::vec3 _point);
	bool RaySphereIntersection();
	float RayDistance(Ray _ray, glm::vec3 _center, int _radius);
	glm::vec3 SphereNormal(glm::vec3 _center, glm::vec3 _point);

private:
	glm::vec3 a;
	glm::vec3 p;
	glm::vec3 x;

	float radius;

	float distance;
};

#endif // !GEOMETRY_H
