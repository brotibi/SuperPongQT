#ifndef TESTGAME_H
#define TESTGAME_H

#include <QObject>
#include <QtTest/QtTest>

class TestGame : public QObject
{
    Q_OBJECT
public:
    explicit TestGame(QObject *parent = nullptr);

private slots:
    void initTestCase()
    { qDebug("called before everything else"); }
    void testPlayer();
    void testBall();
    void testGame();
};

#endif // TESTGAME_H
