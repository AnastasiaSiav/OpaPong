#include "MovingObject.h"

MovingObject::MovingObject(const Vector& pos):GameObject(pos){}
void MovingObject::update(float dt) {
	pos = pos + speed;
}


Vector MovingObject::getSpeed() {
	return speed;
}
void MovingObject::setSpeed(const Vector& speed) {
	this->speed = speed;
}