#include "Level.h"
#include "Ball.h"
#include "Player1.h"
#include "Player2.h"



GameState Level::load() {
    std::vector<GameObject*> objs = {
        new Ball(Vector(500,200),Vector(30,30)),

        new Player1(Vector(180,200),Vector(10,200)),
        new Player2(Vector(880,200),Vector(10,200)),

        new CollidingObject(Vector(500,10),Vector(2000,10)),
        new CollidingObject(Vector(500,490),Vector(2000,10)),


        new Goal(Vector(0,250),Vector(10,500)),
        new Goal(Vector(1000, 250), Vector(10, 500)),


        

        
    };

    (dynamic_cast<MovingObject*>(objs[0]))->setSpeed(Vector(2, 0.5));



   
    return GameState(objs, Game::score);
}
