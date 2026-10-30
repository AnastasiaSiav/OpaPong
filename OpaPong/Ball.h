#pragma once
#include "CollidingObject.h"
#include "Goal.h"
class Ball:public CollidingObject{
public:
	Ball(const Vector& pos, const Vector& dimensions);
	void on_collision(CollidingObject* obj);
	void draw() const override;

};

