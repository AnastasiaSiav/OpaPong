#pragma once
#include "Player.h"
class Player2:public Player
{

public:
	Player2(const Vector& pos, const Vector& dimensions);

	virtual void update(float) override;
	virtual void draw() const override;

	virtual void control();
};

