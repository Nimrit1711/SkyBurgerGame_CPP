//Tester to test the different modes. Manually change tested mode 

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "GameMode.h"

// compile code: g++ GameMode.cpp GameModeTester.cpp Player.cpp Burger.cpp FoodItem.cpp Lettuce.cpp Tomato.cpp Onion.cpp Patty.cpp Cheese.cpp Hazards.cpp Bomb.cpp PoisonBottle.cpp GoldenIngredient.cpp BananaPeel.cpp Sock.cpp Game.cpp -lsfml-graphics -lsfml-window -lsfml-system

using namespace sf;
using namespace std;

int main() {
    // Create an SFML window for the game
    RenderWindow window(VideoMode(900, 800), "Game Mode Test");

    // Select the game difficulty
    GameMode::Difficulty selectedDifficulty = GameMode::Difficulty::Normal;

    // Create a Game object with the selected difficulty and window
    Game game(selectedDifficulty, window);

    // Start the main game loop
    game.run();

    return 0;
}
