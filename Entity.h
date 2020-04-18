#ifndef ENTITY_H
#define ENTITY_H
#include <QGraphicsItem>
class Entity  {
protected:
    int __x; // The x coordinate of an Entity
    int __y; // The y coordinate of an entity
    int xVelocity; // The velocity on the x axis
    int yVelocity; // The velocity on the y axispia
public:
    Entity(int x, int y, int xVelocity, int yVelocity) { // Constructor that takes in the x and y coords and the velocities on the x and y axis
        this->__x = x;
        this->__y = y;
        this->xVelocity = xVelocity;
        this->yVelocity = yVelocity;
    }
    int getX() const { // returns the x position
        return this->__x;
    }
    int getY() const { // returns the y position
        return this->__y;
    }
    int getXVelocity() const { // returns the xVelocity
        return this->xVelocity;
    }
    int getYVelocity() const { // returns the yVelocity
        return this->yVelocity;
    }
    void setXVelocity(int value) { // sets the xVelocity
        this->xVelocity = value;
    }
    void setYVelocity(int value) { // sets the yVelocity
        this->yVelocity = value;
    }
    void setVelocity(int x, int y) { // Sets the velocity on bot the x and y axis
        this->setXVelocity(x);
        this->setYVelocity(y);
    }
    virtual void update() = 0; // Updates the Entity's values, it is up to the child to implement how this works
};
#endif // ENTITY_H
