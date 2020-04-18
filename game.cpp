#include "game.h"
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include <QFont>

Game::Game(){
    this->time = 0;
    this->scene = new QGraphicsScene();
    this->scene->setSceneRect(0,0,800, 600);
    this->player1 = new Player(scene->width()/2,scene->height()/2,0,0);
    this->player2 = new Player(0,0,0,0);

    scene->addItem(this);
    this->timeDisplay = new QGraphicsTextItem;
    timeDisplay->setPlainText(QString("Time: ") + QString::number(time));
    timeDisplay->setDefaultTextColor(Qt::red);
    timeDisplay->setFont(QFont("times", 16));


    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    //qDebug() << "You just pressed a key in the controller";
    this->balls.push_back(new Ball(scene->width()/4, scene->height()/4, 5, 5));

    this->balls[balls.size() - 1]->setBrush(Qt::green);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(run()));
    this->player1->setBrush(Qt::red);
    width = 800;
    height = 600;
    gameOverText = new QGraphicsTextItem();
    titleText = new QGraphicsTextItem();
    titleText->setPlainText(QString("SUPER PONG \n \n press enter to start"));
    titleText->setDefaultTextColor(Qt::green);
    scene->addItem(titleText);
    titleText->setFont(QFont("times", 40));
    titleText->setPos(width/6,height/3);
}

Game::Game(int width, int height): Game(){
    this->scene->setSceneRect(0,0,width, height);
    this->setRect(0,0,width, height);
    this->width = width;
    this->height = height;
}

Game::~Game(){
    //delete scene;
    delete player1;
    delete player2;
    delete timeDisplay;
    delete gameOverText;
    delete timer;
    for_each(balls.begin(),balls.end(),[](Ball * b){
        delete b;
    });
}

void Game::start(){
    scene->addItem(player1);
    scene->addItem(timeDisplay);
    timer->start(10);
    scene->addItem(balls[balls.size() - 1]);
    scene->removeItem(titleText);
}

void Game::keyPressEvent(QKeyEvent *event) {
    qDebug() << "You just pressed a key in the controller";

    if(!gameStarted && (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)){

        gameStarted = true;
        this->start();
    }


    if(event->key() == Qt::Key_Left){
        this->player1->moveLeft();
    }
    if(event->key() == Qt::Key_Right){
        this->player1->moveRight();
    }
    if(event->key() == Qt::Key_Up){
        this->player1->moveForward();
    }
    if(event->key() == Qt::Key_Down){
        this->player1->moveBackward();
    }
    if(event->key() == Qt::Key_Space){
        this->player1->moveStop();
    }
    if(event->key() == Qt::Key_R){
        //this->player1->moveStop();
        //Game * temp = this;
        //this = new Game();
        //delete temp;
        timer->start(10);
        for_each(balls.begin(),balls.end(),[](Ball * b){
            b->scene()->removeItem(b);
        });
        balls.clear();

        this->balls.push_back(new Ball(scene->width()/4, scene->height()/4, 5, 5));
        scene->addItem(balls[balls.size() - 1]);
        scene->removeItem(gameOverText);
        time = 0;
        this->balls[balls.size() - 1]->setBrush(Qt::green);
    }

    this->player1->update();
}

bool Game::checkPlayerCollision(){

    return player1->checkCollision();
}

void Game::run(){
  //  while (1) {
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();

    if(time%1000 == 0 && time != 0){ // Spawns another ball every 10 secs
        this->balls.push_back(new Ball(scene->width()/4, scene->height()/4, 5, 5));
        this->balls[balls.size() - 1]->setBrush(Qt::green);
        scene->addItem(balls[balls.size() - 1]);
    }



    this->player1->update();
    this->player2->update(); // If there was a player 2 it would update player2s position
    for_each(balls.begin(),balls.end(),[](Ball * b){
        b->update();
    });
    //}
    if(checkPlayerCollision()){
        this->isGameOver = true;

        gameOverText->setPlainText(QString("GAME OVER! \n you survived for: ") + QString::number(time/100) + QString(" seconds"));
        gameOverText->setDefaultTextColor(Qt::red);
        gameOverText->setFont(QFont("times", 40));
        gameOverText->setPos(width/6,height/2);
        scene->addItem(gameOverText);
        timer->stop();
        //scene->removeItem(gameOverText);
        //delete gameOverText;
    }
    ++time;
    timeDisplay->setPlainText(QString("Time: ") + QString::number(time/100));
}

QGraphicsScene * Game::getScene(){
    return this->scene;
}
