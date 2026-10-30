#include "Ball.h"

Ball::Ball(const Vector& pos, const Vector& dimensions):CollidingObject(pos,dimensions){}

void Ball::on_collision(CollidingObject* obj) {

	if (dynamic_cast<Goal*>(obj)) {
		kill();
		Game::score++;
		

	}
		graphics::playSound("assets\\hit1.wav", 1.0f, false);

		float dx = std::abs(pos.getX() - obj->pos.getX()) - (dimensions.getX() + obj->dimensions.getX())/2;

		float dy = std::abs(pos.getY() - obj->pos.getY()) - (dimensions.getY() + obj->dimensions.getY()) / 2;

		if (dx > dy) {
			speed.setX(-speed.getX());
		
		}
		else {
			speed.setY(-speed.getY());
		}
}



void Ball::draw() const {

	graphics::Brush br;
	br.texture = std::string("assets\\ball.png");
	br.outline_opacity = 0.0f;


	graphics::drawRect(pos.getX(), pos.getY(), dimensions.getX(), dimensions.getY(), br);
}