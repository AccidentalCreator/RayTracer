#include "Sphere.h"
#include "Ray.h"
#include "Camera.h"
#include "Geometry.h"

#include <algorithm>
#include <iostream>


Sphere::Sphere(glm::vec3 _center, int _radius, glm::fvec3 _colour, Light _light)
{
	centre = _center;
	radius = _radius;
	colour = _colour;
	light = _light;
}

Sphere::~Sphere()
{

}

glm::fvec3 Sphere::ShadeSphere(Ray _ray, glm::vec3 _intersection)
{
	// Ambient Lighting

	float ambStrength = 0.1f;
	glm::vec3 ambient = ambStrength * colour;

	// Difuse Lighting

	// Normal of Light to sample
	glm::vec3 lightToSample = glm::normalize(light.GetPosition()  - _intersection);

	// Normal of sample point
	glm::vec3 sampleNormal = glm::normalize((_intersection - centre) / radius);

	// Calculate direction from light source
	float diffuselighting = glm::max(glm::dot(sampleNormal, lightToSample), 0.0f);

	// Specular lighting

	float specStrength = 0.5f;
	glm::vec3 view = glm::normalize(-_ray.direction);
	glm::vec3 reflection = glm::reflect(-lightToSample, sampleNormal);
	float specular = glm::pow(glm::max(glm::dot(view, glm::normalize(reflection)), 0.0f), 64);
	specular *= specStrength;

	glm::fvec3 sphereColour = (diffuselighting + ambient + specular) * light.GetIntensity() * colour;

	return sphereColour;
}

glm::vec3 Sphere::SphereColour()
{
	glm::fvec3 sphereColour = colour; 

	return sphereColour;
}

glm::vec3 Sphere::Reflection(Ray _ray, glm::vec3 _intersection)
{
	// Normal of sample point
	glm::vec3 sampleNormal = (_intersection - centre) / radius;

	// Normal of Light to sample
	glm::vec3 lightToSample = glm::normalize(_intersection - light.GetPosition());

	// Normal of sample to light
	//glm::vec3 normalSL = glm::normalize(lightToSample);

	// Specular reflection equation
	
	glm::vec3 reflectionVector = glm::reflect(lightToSample, sampleNormal);
	
	return reflectionVector;
}

