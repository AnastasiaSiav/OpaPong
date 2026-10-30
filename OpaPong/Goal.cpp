#include "Goal.h"

Goal::Goal(const Vector& pos, const Vector& dimensions):CollidingObject(pos,dimensions) {}

void Goal::draw() const {

	graphics::Brush br;

	br.fill_color[0] = 0.9f;
	br.fill_color[1] = 0.9f;
	br.fill_color[2] = 0.1f;

	graphics::drawRect(pos.getX(), pos.getY(), dimensions.getX(), dimensions.getY(), br);

}

