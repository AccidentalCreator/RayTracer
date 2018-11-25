#ifndef SPHERE_H
#define SPHERE_H

#include <glm.hpp>
#include <memory>

class Ray;

class Sphere
{
public:
	Sphere(glm::vec3 _center, int _radius, glm::vec3 _colour);
	~Sphere();

	glm::vec3 ShadeSphere(Ray _ray, glm::vec3 _intersection);
	glm::vec3 ClosetsPoint(Ray _ray, glm::vec3 _queryPoint);
	glm::vec3 RaySphereIntersec(Ray *_ray);
	glm::vec3 Normalise(glm::vec3 _samplePoint);

	glm::vec3 GetCenter() { return centre; }
	float GetRadius() { return radius; }
	glm::vec3 GetColour() { return colour; }

private:
	glm::vec3 colour;
	glm::vec3 centre;
	glm::vec3 normal;
	float radius;
	float ColMod(float a, float b, float t);

};

#endif // !SPHERE_H
