#include "Scene\Camera.hpp"

#include "Debug\Exception.hpp"
#include "glm\gtx\transform.hpp"

namespace ece
{
	void Camera::updatePosition(const FloatPoint3D & position, const FloatPoint3D & target)
	{
		this->position = position;
		this->target = target;

		auto direction = target - position;
		direction.normalize();
		if (direction == this->upAxis) {
			if (direction == UP) {
				this->upAxis = RIGHT;
			}
			else if (direction == RIGHT) {
				this->upAxis = FRONT;
			}
			else if (direction == FRONT) {
				this->upAxis = UP;
			}
			else {
				throw BadInputException::makeException("Computation of the up axis is wrong !");
			}
		}
	}
}