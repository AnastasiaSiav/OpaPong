#include "GameObject.h"

int GameObject::current_id = 0;
GameObject::GameObject(const Vector& pos) {
	id = current_id++;
	this->alive = true;
	this->name = "";

	this->pos = pos;
	
	
}
bool GameObject::is_alive() const {
	return alive;
}
int GameObject::get_id() const {
	return id;
}
void GameObject::kill() {
	alive = false;
}