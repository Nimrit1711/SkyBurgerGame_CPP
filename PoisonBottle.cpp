#include "PoisonBottle.h"
#include <iostream>

PoisonBottle::PoisonBottle() 
    : Hazards("poisonBottle.png", 110.f), poisonEffectDuration(5.0f) { 
    hazardSprite.setScale(0.2f, 0.2f);
    
}

void PoisonBottle::applyPoisonEffect(Player& player) {
      
    float poisonEffectDuration = 5.0f; // 5 seconds
    player.applyPoison(poisonEffectDuration);
}

void PoisonBottle::update(float deltaTime) {
    
    Hazards::update(deltaTime);
}

void PoisonBottle::render(RenderWindow& window) {
    window.draw(hazardSprite);
}
