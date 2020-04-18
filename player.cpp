#include "Player.h"
#include "Game.h"
#include <QGraphicsRectItem>
#include "Ball.h"
//Player::Player()
//{

//}

// This file contains the implementation for the Player class

Player & Player::operator= (const Player & player){
    this->__x = player.__x;
    this->__y = player.__y;
    this->xVelocity = player.xVelocity;
    this->yVelocity = player.yVelocity;
    //this->playerImage = player.playerImage;
    return *this;
}

bool Player::checkCollision(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n= colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Ball)) {
            qDebug() << "Player collided with the ball";
            return true;
        }
    }

    return false;
}

void Player::update() {
    if(__y < 0){
        yVelocity = -yVelocity;
        __y = 0 + yVelocity;
    }

    if(__y > this->sceneHeight - this->height){
        yVelocity = -yVelocity;
        __y = this->sceneHeight - height + yVelocity;
    }

    if(__x < 0){
        xVelocity = -xVelocity;
        __x = 0 + xVelocity;
    }

    if(__x > this->sceneWidth - this->width){
        xVelocity = -xVelocity;
        __x = this->sceneWidth - width + xVelocity;
    }

    this->__x -= this->getXVelocity();
    this->__y -= this->getYVelocity();
    this->xVelocity += 0 - (this->xVelocity)/2;
    this->yVelocity += 0 - (this->yVelocity)/2;
    this->setRect(this->__x, this->__y, this->width, this->height);


}

void Player::moveForward() {
    if(yVelocity < 45)
    this->yVelocity += speed;
}

void Player::moveBackward() {
    if(yVelocity > -45)
    this->yVelocity -= speed;
}

void Player::moveLeft() {
    if(xVelocity < 45)
    this->xVelocity += speed;
}

void Player::moveRight() {
    if(xVelocity > -45)
    this->xVelocity -= speed;
}

void Player::moveStop(){
    this->xVelocity = 0;
    this->yVelocity = 0;
}


