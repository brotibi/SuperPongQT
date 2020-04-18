#include <QtTest/QtTest>
#include "testgame.h"
#include "Player.h"
#include "Ball.h"
#include "Game.h"
//QTEST_MAIN(TestGame)
//#include "testgame.moc"

TestGame::TestGame(QObject *parent) : QObject(parent)
{

}

void TestGame::testPlayer(){
    Player playa(1,1,1,1);
    QVERIFY(playa.getX() == 1);
    QVERIFY(playa.getXVelocity() == 1);
    QVERIFY(playa.getY() == 1);
    QVERIFY(playa.getYVelocity() == 1);
    playa.setXVelocity(2);
    playa.setYVelocity(2);
    QVERIFY(playa.getXVelocity() == 2);
    QVERIFY(playa.getYVelocity() == 2);
    playa.setVelocity(100,100);
    QVERIFY(playa.getXVelocity() == 100);
    QVERIFY(playa.getYVelocity() == 100);
    playa.moveStop();
    QVERIFY(playa.getXVelocity() == 0);
    QVERIFY(playa.getYVelocity() == 0);
    playa.moveForward();
    QVERIFY(playa.getYVelocity() == 35);
    playa.moveBackward();
    QVERIFY(playa.getYVelocity() == 0);
    playa.moveLeft();
    QVERIFY(playa.getXVelocity() == 35);
    playa.moveRight();
    QVERIFY(playa.getXVelocity() == 0);
}

void TestGame::testBall(){
    Player ball(1,1,1,1);
    QVERIFY(ball.getX() == 1);
    QVERIFY(ball.getXVelocity() == 1);
    QVERIFY(ball.getY() == 1);
    QVERIFY(ball.getYVelocity() == 1);
    ball.setXVelocity(2);
    ball.setYVelocity(2);
    QVERIFY(ball.getXVelocity() == 2);
    QVERIFY(ball.getYVelocity() == 2);
    ball.setVelocity(100,100);
    QVERIFY(ball.getXVelocity() == 100);
    QVERIFY(ball.getYVelocity() == 100);
}

void TestGame::testGame(){
    Game game1;
    QVERIFY(game1.time == 0);
    QVERIFY(game1.isGameOver == false);
    QVERIFY(game1.player1 != nullptr);
    QVERIFY(game1.width == 800);
    QVERIFY(game1.height == 600);
    QVERIFY(game1.balls.size() == 1);
    Game game2(450, 400);
    QVERIFY(game2.time == 0);
    QVERIFY(game2.isGameOver == false);
    QVERIFY(game2.player1 != nullptr);
    QVERIFY(game2.width == 450);
    QVERIFY(game2.height == 400);
    QVERIFY(game2.balls.size() == 1);
}
