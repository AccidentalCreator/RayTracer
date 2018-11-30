#include "Sphere.h"
#include "Ray.h"
#include "Camera.h"
#include "Geometry.h"

#include <algorithm>
#include <iostream>


Sphere::Sphere(glm::vec3 _center, int _radius, glm::vec3 _colour, Light _light)
{
	centre = _center;
	radius = _radius;
	colour = _colour;
	light = _light;
}

Sphere::~Sphere()
{

}

glm::vec3 Sphere::ShadeSphere(Ray _ray, glm::vec3 _intersection)
{
	glm::vec3 sphereColour = colour;

	glm::vec3 sampleToLight = light.GetPosition()  - _intersection;
	// Normal of sample to light
	glm::vec3 normalSL = glm::normalize(sampleToLight);

	// Normal of sample point
	glm::vec3 sampleNormal = (_intersection - centre) / radius;

	float diffuselighting;

	// Calculate direction from light source
	diffuselighting = glm::max(glm::dot(sampleNormal, normalSL), 0.0f);

	sphereColour = diffuselighting * light.GetIntensity() * colour;

	// Speculare uses half vector 
	// change to sphere colour
	return sphereColour;
}

glm::vec3 Sphere::Reflection(Ray _ray, glm::vec3 _intersection)
{
	
	// Normal of sample point
	glm::vec3 sampleNormal = (_intersection - centre) / radius;

	// Sample to light vector
	glm::vec3 sampleToLight = light.GetPosition() - _intersection;

	// Normal of sample to light
	glm::vec3 normalSL = glm::normalize(sampleToLight);

	// Specular reflection equation
	
	glm::vec3 reflectionVector = (2 * (glm::dot(sampleNormal, -normalSL)) * sampleNormal - normalSL);
	
	//glm::vec3 reflectionVector = glm::reflect(-normalSL, sampleNormal);


	//glm::vec3 reflectionVector = _ray.direction - 2 * glm::dot(_ray.direction, sampleNormal) * sampleNormal;

	return reflectionVector;
}

