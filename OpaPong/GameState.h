#pragma once
#include <vector>
#include "graphics.h"
#include "Game.h"
#include "GameObject.h"

class Game; 
class Level;

class GameState {
	std::vector<GameObject*> objects;
	int score;
public:
	GameState(const std::vector<GameObject*>& objects, int score);
	friend class Game;

};

