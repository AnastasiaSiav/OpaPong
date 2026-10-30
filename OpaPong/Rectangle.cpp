#include "Rectangle.h"

Rectangle::Rectangle(const Vector& pos, const Vector& dimensions) :MovingObject(pos) {
	this->dimensions = dimensions;
}

void Rectangle::draw() const {
	graphics::drawRect(pos.getX(), pos.getY(), dimensions.getX(), dimensions.getY(), graphics::Brush());
}