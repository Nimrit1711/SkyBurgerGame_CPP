#include "IntroductionMenu.h"
#include "Game.h"
//#include "PauseMenu.h"
//#include "SettingsMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


int main (){
    RenderWindow window(VideoMode(900, 800), "Sky Burger");

    IntroductionMenu mainMenu;
    Game game;
    //PauseMenu pauseMenu;
    //SettingsMenu settingsMenu;


    enum GameState { MAIN, GAME, PAUSE, SETTINGS };
    GameState currentState = MAIN;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        switch (currentState) {
            case MAIN:
                if (mainMenu.handleInput(window)) {
                    currentState = GAME;
                }
                mainMenu.renderMenu(window);
                break;

            case GAME:
                game.run(); // Call the gameplay method
                break;
            
        }
    }
return 0;
}