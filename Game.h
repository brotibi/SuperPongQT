#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsTextItem>
#include "Ball.h"
#include <vector>

class Game : public QObject, public QGraphicsRectItem{
    Q_OBJECT
    friend class TestGame;
private:
    int time; // An int to keep track of the players time
    Player * player1; // Player 1 object
    Player * player2; // Player 2 object
    std::vector<Ball *> balls; // A vector of all the balls in the game
    QGraphicsScene * scene; // The Game scene
    QGraphicsTextItem * timeDisplay; // The text that displays the time
    QGraphicsTextItem * gameOverText; // The game over text which displays when the game is over
    QTimer * timer; // The timer used for the main gain "loop"
    int width; // The pixel height of the scene
    int height; // The pixel height of the scene
    bool isGameOver = false; // Boolean telling if the game is over
    bool checkPlayerCollision(); // Checks if the player collides with the ball
    //void start(); // Starts the Game
    void keyPressEvent(QKeyEvent *event); // Key press listener that listens for keys being pressed
public:
    Game(); // No-args constructor for creating the game
    ~Game(); // The Games Destructor
    Game(int width, int height); // Game constructor that takes height and width
    QGraphicsScene * getScene(); // Returns the game scene


public slots:
    void run(); // Main game loop
};
#endif // GAME_H
