#pragma once
#include "Vector.h"
#include "GameObject.h"


class MovingObject:public GameObject{
protected:
	Vector speed;
public:
	MovingObject(const Vector& pos);
	virtual void update(float dt) override;
	
	Vector getSpeed();
	void setSpeed(const Vector&);

};

