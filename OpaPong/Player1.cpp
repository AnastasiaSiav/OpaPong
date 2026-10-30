#include "Player1.h"


Player1::Player1(const Vector& pos, const Vector& dimensions):Player(pos,dimensions){}

void Player1::update(float dt) {
	MovingObject::update(dt);
	control();
}

void Player1::draw() const {
	graphics::Brush br;
	br.texture = std::string("assets\\iron.png");
	br.outline_opacity = 0.0f;

	graphics::drawRect(pos.getX(), pos.getY(), dimensions.getX(), dimensions.getY(), br);
}

void Player1::control() {



	Vector temp_acceleration;  // Temporary vector for this frame's acceleration.


	if (graphics::getKeyState(graphics::SCANCODE_UP)) {
		temp_acceleration = temp_acceleration + Vector(0, -1);
	}
	if (graphics::getKeyState(graphics::SCANCODE_DOWN)) {
		temp_acceleration = temp_acceleration + Vector(0, 1);
	}
	

	// Normalize 
	if (temp_acceleration.length() > 0) {
		temp_acceleration = temp_acceleration * (1.0f / temp_acceleration.length());
	}

	// Apply acceleration to speed.
	speed = speed + temp_acceleration * 0.5; // Adjust 0.5 to tune responsiveness.

	// Apply friction 
	speed = speed * 0.95f;

	const float maxSpeed = 1;
	if (speed.getY() > maxSpeed)
		speed.setY(maxSpeed);
	else if (speed.getY() < -maxSpeed) {
		speed.setY(-maxSpeed);
	}

	//don't leave game
	if (pos.getY() > 410)
		pos.setY(410);
	if (pos.getY() < 90)
		pos.setY(90);


}