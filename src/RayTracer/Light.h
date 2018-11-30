#pragma once
#ifndef LIGHT_H
#define LIGHT_H

#include <glm.hpp>

class Light
{
public:

	void SetPosition(glm::vec3 _position) { position = _position; }
	void SetIntesity(glm::vec3 _intesity) { intesity = _intesity; }

	glm::vec3 GetPosition() { return position; }
	glm::vec3 GetIntensity() { return intesity; }

private:
	glm::vec3 position;
	glm::vec3 intesity;
};

#endif // !LIGHT_H
