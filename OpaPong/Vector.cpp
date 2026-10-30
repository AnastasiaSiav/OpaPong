#include "Vector.h"

Vector::Vector(float x, float y) {
    this->x = x;
    this->y = y;
}
Vector::Vector() :Vector(0, 0) {}
float Vector::getX() const { return x; }
float Vector::getY() const { return y; }
void  Vector::setX(float x) { this->x = x; }
void  Vector::setY(float y) { this->y = y; }

Vector Vector::operator+(const Vector& v) const {
    return Vector(x + v.x, y + v.y);
}
Vector  Vector::operator*(float scale) const {
    return Vector(x * scale, y * scale);

}
float Vector::length() const{
    return std::sqrt(x * x + y * y);
}