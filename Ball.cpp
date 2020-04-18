#include "Ball.h"


Ball & Ball::operator= (const Ball & ball){
    this->__x = ball.__x;
    this->__y = ball.__y;
    this->xVelocity = ball.xVelocity;
    this->yVelocity = ball.yVelocity;
    return *this;
}


void Ball::update(){ // Ball's update implementation
    if(__y < 0){
        yVelocity = -yVelocity;
        __y = 0;
    }

    if(__y > this->sceneHeight - this->height){
        yVelocity = -yVelocity;
        __y = this->sceneHeight - height;
    }

    if(__x < 0){
        xVelocity = -xVelocity;
        __x = 0;
    }

    if(__x > this->sceneWidth - this->width){
        xVelocity = -xVelocity;
        __x = this->sceneWidth - width;
    }

    this->__x -= this->getXVelocity();
    this->__y -= this->getYVelocity();
    //this->xVelocity += 0 - (this->xVelocity)/2;
    //this->yVelocity += 0 - (this->yVelocity)/2;
    this->setRect(this->__x, this->__y, this->width, this->height);
}


