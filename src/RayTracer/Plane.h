#pragma once
#ifndef PLANE_H
#define PLANE_H

#include <glm.hpp>

class Plane
{
public:
	Plane(glm::vec3 _position, glm::vec3 _size, glm::vec3 _colour);
	~Plane();

private:
	glm::vec3 position;
	glm::vec3 size;
	glm::vec3 colour;
};

#endif // !PLANE_H
