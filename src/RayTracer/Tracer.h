#pragma once
#ifndef TRACER_H

#include <memory>
#include <vector>
#include <glm.hpp>

#include "Camera.h"

class Ray;
class Geometry;
class Sphere;

class Tracer
{
public:
	Tracer();
	~Tracer();
	void TraceRay(Ray _ray, Geometry _geometry, std::vector<std::shared_ptr<Sphere>> spheres, glm::fvec3 &colour);
	void reset();
private:
	Camera camera;
	int r;
};

#define TRACER_H
#endif // !TRACER_H