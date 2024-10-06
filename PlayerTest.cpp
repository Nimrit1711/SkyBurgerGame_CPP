//test file for Player class
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace sf;
int main() {
   
    RenderWindow window(VideoMode(800, 600), "Player Class Test");
   
    Player player;

   
    while (window.isOpen()) {
     
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // testing lostLife Function
        if (Keyboard::isKeyPressed(Keyboard::Key::L)) {
            player.loseLife();
        }

        player.updateMovement(window);     
        window.clear(Color(135,206, 235));

        
                
        
        player.renderPlayer(window);
        

        window.display();
    }

    return 0;
}
