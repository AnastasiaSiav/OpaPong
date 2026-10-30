#include "graphics.h"
#include "Game.h"
#include "Level.h"
#include <iostream>






int main()
{
    try {
        Game::load(Level::load());
        Game::start();
    }
    catch (const char* err) {
        std::cout << err;
    }
  



    return 0;
}