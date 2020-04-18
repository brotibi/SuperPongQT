#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsItem>

#include <Game.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QGraphicsScene * scene = new QGraphicsScene();
    //QGraphicsRectItem * rect = new QGraphicsRectItem();
    //rect->setRect(0,0,100,100);
    //scene->addItem(rect);
    Game  game;
    game.setFlag(QGraphicsItem::ItemIsFocusable);
    game.setFocus();
    //QGraphicsView * view  = new QGraphicsView(game.getScene());
    QGraphicsView view;

    view.setScene(game.getScene());

    //MainWindow w;
    //w.show();
    view.show();
    view.setFixedSize(800, 600);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    return a.exec();
}
