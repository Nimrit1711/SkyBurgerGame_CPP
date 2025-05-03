#ifndef POISONBOTTLE_H
#define POISONBOTTLE_H

#include "Hazards.h"

// this is a special type of hazard that slows down the player. 
class PoisonBottle : public Hazards {
private:
    float poisonEffectDuration; // time that the poison effect lasts
public:
    PoisonBottle();
    void applyPoisonEffect(Player& player); 
    void update(float deltaTime) override;
    void render(RenderWindow& window) override;
    Hazards* create() const override;
};

#endif
