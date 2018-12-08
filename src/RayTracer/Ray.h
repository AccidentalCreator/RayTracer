#ifndef RAY_H
#define RAY_H

#include <glm.hpp>

class Ray
{
public:
	glm::vec3 origin;
	glm::vec3 direction;
	float intersecDist = 100000;

	int reflections = 0;
	

	glm::fvec3 GetColour() { return colour; }
	void SetColour(glm::fvec3 _colour);

private:
	glm::fvec3 colour = glm::fvec3(0, 0, 0);

};

#endif // !RAY_H
