#pragma once
#include "CollidingObject.h"
class Player:public CollidingObject{

public:
	Player(const Vector& pos, const Vector& dimensions);
	virtual void control() = 0;
};

