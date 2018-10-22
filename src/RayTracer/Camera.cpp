#include "Camera.h"
#include "Ray.h"

Ray Camera::CreateRay(glm::vec2 _position)
{
	Ray ray;
	
	ray.origin.x = _position.x;
	ray.origin.y = _position.y;
	ray.direction = glm::vec3(0, 0, 1);

	return ray;
}