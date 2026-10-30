#pragma once
#include <string>
#include "Vector.h"

class GameObject{
	static int current_id;
protected:
	std::string name;
	bool alive;
	int id;
public:
	Vector pos;
	GameObject(const Vector& pos);
	virtual void update(float) = 0;
	virtual void draw()const = 0;
	bool is_alive() const;
	int get_id() const;
	void kill();

};

