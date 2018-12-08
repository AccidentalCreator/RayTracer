#pragma once
#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <glm.hpp>

class Ray;
class Sphere;

struct IntersectionTest
{
	float distance;
	bool hit;
	glm::vec3 intersectPoint;
};


class Geometry
{
public:

	IntersectionTest RaySphereIntersection(Ray _ray, Sphere _sphere, glm::vec3 _origin);

	bool RayPlaneIntersection();

	glm::fvec3 ConvertColour(glm::fvec3 _colour);

private:

};

#endif // !GEOMETRY_H
