
#include "FallingObjects.h"


FallingObjects:: FallingObjects(const Vector2f& startingPosition):
isCaught(false), positionOfObject(startingPosition){
    objectShape.setPosition(positionOfObject);
    objectShape.setSize(Vector2f(50.0f,50.0f));
}


void FallingObjects:: setTexture(const string& textureFile){
        if (!objectTexture.loadFromFile(textureFile)){
            cout<<"Texture loading error"<<endl;
        }
        objectShape.setTexture(&objectTexture);
    }

void FallingObjects:: setPosition(const Vector2f& position){
        positionOfObject=position;
        objectShape.setPosition(positionOfObject);
}

bool FallingObjects:: isOffScreen(const RenderWindow& window){
    return positionOfObject.y>window.getSize().y;
}

Vector2f FallingObjects:: getPosition() const{
        return positionOfObject;
    }

Vector2f FallingObjects:: getSize() const{
    return Vector2f(50.0f, 50.0f);
}