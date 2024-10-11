#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "GameMode.h"

using namespace sf;
using namespace std;

int main() {
    // Create a Game 
    Game game; 

    // Start the game loop
    game.run(); 

    return 0;
}
