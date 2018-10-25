#ifndef SPHERE_H
#define SPHERE_H

#include <glm.hpp>
#include <memory>

class Ray;

class Sphere
{
public:
	Sphere(glm::vec3 _center, int _radius);
	~Sphere();

	glm::vec3 ShadeSphere(Ray _ray, glm::vec3 _intersecion);
	glm::vec3 ClosetsPoint(Ray _ray, glm::vec3 _queryPoint);
	glm::vec3 RaySphereIntersec(Ray *_ray);
	glm::vec3 SphereNormal(glm::vec3 _samplePoint);


private:
	glm::vec3 centre;
	glm::vec3 normal;
	int radius;
	float ColMod(float a, float b, float t);

};

#endif // !SPHERE_H
