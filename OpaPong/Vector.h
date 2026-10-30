#pragma once
#include <cmath>
class Vector{
	float x;
	float y;
public:
	Vector(float x, float y);
	Vector();
	float getX() const;
	float getY() const;
	void setX(float x);
	void setY(float y);

	Vector operator+(const Vector& v) const;
	Vector operator*(float scale) const;
	float length() const;
};

