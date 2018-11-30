#include "Camera.h"
#include "Ray.h"


#include <iostream>

Camera::Camera()
{
}

Ray Camera::CreateRay(glm::vec3 _position)
{
	Ray ray;
	
	ray.origin.x = _position.x;
	ray.origin.y = _position.y;
	ray.origin.z = _position.z;
	ray.direction = glm::vec3(0, 0, 1);

	return ray;
}