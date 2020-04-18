#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include <QGraphicsItem>
class Player : public Entity, public QGraphicsRectItem{
    friend class Game;
private:
    int speed; // The players acceleration speed
    const int width = 50; // The players width
    const int height = 50; // The players height
    int sceneHeight; // The scene's height
    int sceneWidth; // The scene's width
    bool checkCollision(); // Checks if the player collides with a ball
public:

    Player(int x, int y, int xVelocity, int yVelocity) : Entity(x, y, xVelocity, yVelocity), QGraphicsRectItem(){ // Player's constructor implementation
            //playerImage = new QGraphicsRectItem();
            this->setRect(x,y,width, height);
            this->speed = 35;
            sceneHeight = y*2;
            sceneWidth = x*2;
    }
    Player();
    Player & operator= (const Player & player);
    void update() override;
    void moveForward(); // Moves the player forward
    void moveRight(); // Moves the player to the right
    void moveLeft(); // Moves the player to the left
    void moveBackward(); // Moves the player backwards
    void moveStop(); // Set's the velocity of the player to 0
    //QGraphicsRectItem * draw();
};
#endif // PLAYER_H
