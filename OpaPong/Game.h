#pragma once
#include <vector>
#include "GameObject.h"
#include "GameState.h"
#include "Level.h"
#include "graphics.h"
#include "Ball.h"


class GameState;
class Level;
class GameObject;

class Game {


	static constexpr float dt = 0.1f;
public:
	static int score;
	static int level;
	static std::vector<GameObject*> objects;
	

	static void start();
	static void update(float dt);
	static void draw();
	static void load(const GameState& s);
	static void checkCollisions();

};

