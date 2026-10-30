#pragma once
#include "Player.h"
class Player1:public Player
{
public:
	Player1(const Vector& pos, const Vector& dimensions);

	virtual void update(float) override;
	virtual void draw() const override;

	virtual void control();
};

