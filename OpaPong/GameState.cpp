#include "GameState.h"

GameState::GameState(const std::vector<GameObject*>& objects, int score) {
    this->objects = objects;
    this->score = score;
}
