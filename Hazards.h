#ifndef HAZARDS_H
#define HAZARDS_H
#include "FallingObjects.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Burger.h"

class Hazards: public FallingObjects{
    protected:
    Sprite hazardSprite;
    Texture hazardTexture;   
    float hazardSpeed;
    bool isCaught;

    public:
    Hazards(const string& textureFile, float speed);
    void update(float deltaTime) override;
    void render(RenderWindow& window) override;
    void checkCollision(Player& player, Burger& burger) override;
    FloatRect getGlobalBounds() const override;
    void setPosition(const Vector2f& pos) override;
    bool getIsCaught() const override { return isCaught; }
    void setIsCaught(bool caught) override { isCaught = caught; }
    virtual Hazards* create() const =0;
};




#endif
