#ifndef BALL_H
#define BALL_H
#include <QGraphicsEllipseItem>
#include "Entity.h"

class Ball : public Entity, public QGraphicsEllipseItem{
private:
    //QGraphicsEllipseItem * ballImage;
    int width = 50; // The width of the ball
    int height = 50; // The height of the ball
    int speed; // The speed of the ball
    int sceneHeight; // The height of the scene
    int sceneWidth; // The width of the scene
public:
    Ball(int x, int y, int xVelocity, int yVelocity) : Entity(x, y, xVelocity, yVelocity), QGraphicsEllipseItem(){ // The balls constructor
        //ballImage = new QGraphicsEllipseItem();
        this->setRect(x,y,width, height);
        this->speed = 15;
        sceneHeight = y*4;
        sceneWidth = x*4;
    }
    Ball & operator= (const Ball & ball); // Overloads the equals operator
    void update(); // update method
};

#endif // BALL_H
