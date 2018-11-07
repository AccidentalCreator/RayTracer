#include "Sphere.h"
#include "Ray.h"


Sphere::Sphere(glm::vec3 _center, int _radius)
{
	centre = _center;
	radius = _radius;
}

Sphere::~Sphere()
{

}

glm::vec3 Sphere::ShadeSphere(Ray _ray, glm::vec3 _intersecion)
{
	return glm::vec3(255, 0, 0);
}


glm::vec3 Sphere::RaySphereIntersec(Ray *_ray)
{

	//if (_ray->GetColourSet())
	//{
	//	return _ray->GetColour(); // Keeps its colour
	//							 // Need to check which is infront
	//}

	//float t = glm::dot(centre - _ray->origin, glm::normalize(_ray->direction));
	//glm::vec3 p = _ray->origin + glm::normalize(_ray->direction) * t;

	//float y = glm::length(centre - p);
	// // if y < radius does not hit sphere
	//if (y < radius)
	//{
	//	float x = glm::sqrt(radius * radius - y * y);
	//	float t1 = t - x;
	//	float t2 = t + x;

	//	float colour = ColMod(centre.z, centre.z - radius, t1);

	//	_ray->SetColour(glm::vec3(colour));

	//	return glm::vec3(colour);
	//}
	//else
	//{
	//	return glm::vec3(0, 0, 0); // Sets colour to black
	//}

	return glm::vec3(0, 0, 0);
}

float Sphere::ColMod(float _a, float _b, float _t)
{
	float colour = ((_t - _a) / (_b - _a)) * 255;

	return colour;
}

