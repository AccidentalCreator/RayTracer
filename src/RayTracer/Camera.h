#ifndef CAMERA_H
#define CAMERA_H

#include <glm.hpp>

class Ray;

class Camera
{
public:
	Ray CreateRay(glm::vec2 _position);
};

#endif // !CAMERA_H
