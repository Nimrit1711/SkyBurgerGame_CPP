#include "Burger.h"


Burger:: Burger():stackHeight(0){
    burgerPile.clear();  
    
}

void Burger:: addIngredient(unique_ptr<FoodItem> ingredient){
    stackHeight += ingredient->getSize().y; //gets the ingredients height 
    burgerPile.push_back(move(ingredient));  
      
}

void Burger:: clearStack(){
    burgerPile.clear();
    stackHeight=0;
}

void Burger::renderBurger(sf::RenderWindow& window, const sf::Vector2f& playerPosition){
    Vector2f position = playerPosition;  

    for (auto& ingredient : burgerPile) {
        
        position.y -= ingredient->getSize().y;  // Stacks upwards
        ingredient->setPosition(position);  
        ingredient->renderObject(window);  
    }
}
   

void Burger:: setStackHeight(int height){
    this->stackHeight=height;
}

int Burger:: getStackHeight(){
    return stackHeight;
}
