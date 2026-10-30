#include "Game.h"
#include <iostream>

std::vector<GameObject*> Game::objects;
int Game::score = 0;
int Game::level = 0;



void Game::start() {
    graphics::createWindow(1200, 600, "Platformer");

    graphics::setDrawFunction(Game::draw);
    graphics::setUpdateFunction(Game::update);

    graphics::setCanvasSize(1000, 500);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);


    
    graphics::Brush br; br.fill_color[0] = 0.09f;br.fill_color[1] = 0.48f;br.fill_color[2] = 0.83f;
    graphics::setWindowBackground(br);
    graphics::setFont("assets\\MightySouly-lxggD.ttf");


    graphics::startMessageLoop();
}


void Game::update(float ms) {

    //check collisions
    checkCollisions();

    //update every object
    for (GameObject* obj : Game::objects) {
        obj->update(dt);
    }


    std::vector<GameObject*> living;
    for (GameObject* obj : Game::objects) {
        if (obj->is_alive()) {
            living.push_back(obj);
        }
        else{
            if (dynamic_cast<Ball*>(obj) != nullptr) {
                living.insert(living.begin(), new Ball(Vector(500, 200), Vector(30, 30)));
                (dynamic_cast<MovingObject*>(living[0]))->setSpeed(Vector(2, 0.5));
            }

            delete obj;
        }
        
       
    }


    Game::objects = living;





    
}


void Game::draw()
{

    for (GameObject* obj : Game::objects) {
        obj->draw();
    }

    graphics::Brush br;
    br.fill_color[0] = 0.5f;
    br.fill_color[1] = 0.0f;
    br.fill_color[2] = 0.0f;
    
    drawText(850, 40, 30, "Score: " + std::to_string(score), br);



}

void Game::load(const GameState& gs) {

    score = gs.score;

    objects = gs.objects;
}



void Game::checkCollisions() {

    Ball* ball = dynamic_cast<Ball*>(Game::objects[0]);
    if (ball == nullptr) {
        throw "Ball should always be the first object.";
    }
 
    for (GameObject* obj : Game::objects) {
        if (obj == ball) {
            continue;
        }
        else if (dynamic_cast<CollidingObject*>(obj) != nullptr) {

            

            CollidingObject* co = dynamic_cast<CollidingObject*>(obj);
            float dx = std::abs(ball->pos.getX() - co->pos.getX());

            float dy =std::abs(ball->pos.getY() - co->pos.getY());


            if (dx <= ball->dimensions.getX() / 2 + co->dimensions.getX() / 2 &&
                dy <= ball->dimensions.getY() / 2 + co->dimensions.getY() / 2) {

                std::cout << "COLLISION\n";
                ball->on_collision(co);
            }

        }
    }
}

