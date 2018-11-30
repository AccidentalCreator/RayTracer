#ifndef SPHERE_H
#define SPHERE_H

#include "Light.h"

#include <glm.hpp>
#include <memory>


class Ray;
//class Light;

class Sphere
{
public:
	Sphere(glm::vec3 _center, int _radius, glm::vec3 _colour, Light _light);
	~Sphere();

	glm::vec3 ShadeSphere(Ray _ray, glm::vec3 _intersection);
	glm::vec3 Reflection(Ray _ray, glm::vec3 _intersection);

	glm::vec3 GetCenter() { return centre; }
	float GetRadius() { return radius; }
	glm::vec3 GetColour() { return colour; }

private:
	glm::vec3 colour;
	glm::vec3 centre;
	glm::vec3 normal;
	float radius;

	Light light;

};

#endif // !SPHERE_H
