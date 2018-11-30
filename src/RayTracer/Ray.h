#ifndef RAY_H
#define RAY_H

#include <glm.hpp>

class Ray
{
public:
	glm::vec3 origin;
	glm::vec3 direction;

	glm::fvec3 GetColour() { return colour; }
	void SetColour(glm::fvec3 _colour);

	void SetDirection(glm::vec3 _direction) { direction = _direction; }

private:
	glm::fvec3 colour = glm::fvec3(0, 0, 0);
};

#endif // !RAY_H
