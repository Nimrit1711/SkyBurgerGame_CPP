#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main(){

  
    RenderWindow gameWindow(VideoMode(800,800), "Sky Burger", Style::Close | Style::Titlebar);
  
    RectangleShape burgerPlayer;
    Vector2f bunPosition(100.0f,650.0f);
    //float acceleration=0.45;

    
    burgerPlayer.setPosition(bunPosition);
    burgerPlayer.setSize(Vector2f(100,100));
    float xVelocity=0.5;
   

    Texture bunTexture;
    bunTexture.loadFromFile("file.png");
    burgerPlayer.setTexture(&bunTexture);


    while (gameWindow.isOpen())
    {
        Event evnt;
        while (gameWindow.pollEvent(evnt))
        {
            switch(evnt.type)
            {
            case Event::Closed:
                gameWindow.close();
                break;          
            
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Left)){
            xVelocity=-0.5;
            
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Right)){
               xVelocity=0.55;
        }

        
                
        bunPosition.x += xVelocity;

        if (bunPosition.x < -burgerPlayer.getSize().x) {
           
            bunPosition.x = gameWindow.getSize().x;
        }
        if (bunPosition.x > gameWindow.getSize().x) {
           
            bunPosition.x = -burgerPlayer.getSize().x;
        }

        burgerPlayer.setPosition(bunPosition);
       

            gameWindow.clear(Color(135,206, 235));
            gameWindow.draw(burgerPlayer);
            gameWindow.display();
    }
return 0;
}
