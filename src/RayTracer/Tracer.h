#ifndef TRACER_H
#define TRACER_H

#include <glm.hpp>

class Ray;

class Tracer
{
public:
	glm::vec3 TraceRay(Ray _ray);

private:
	glm::vec3 colour;

};

#endif // !TRACER_H
