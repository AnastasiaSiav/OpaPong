#pragma once
#include "GameObject.h"
#include "MovingObject.h"
#include "graphics.h"
#include <string>

class Rectangle : public MovingObject{
protected:
	
public:
	Vector dimensions;
	Rectangle(const Vector& pos, const Vector& dimensions);
	virtual void draw() const override;
};

