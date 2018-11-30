#include "Plane.h"

Plane::Plane(glm::vec3 _position, glm::vec3 _size, glm::vec3 _colour)
{
	position = _position;
	size = _size;
	colour = _colour;
}

Plane::~Plane()
{

}
