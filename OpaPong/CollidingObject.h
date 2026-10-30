#pragma once
#include "Rectangle.h"

class CollidingObject:public Rectangle{
public:
	CollidingObject(const Vector& pos, const Vector& dimensions);
};

