#pragma once
#include "CollidingObject.h"
#include "Game.h"

class Goal :public CollidingObject
{
public:
	Goal(const Vector& pos, const Vector& dimensions);
	virtual void draw() const override;
};