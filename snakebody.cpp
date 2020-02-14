#include "snakebody.h"

#include <iostream>

#define K_UP 1
#define K_DOWN 2
#define K_RIGHT 3
#define K_LEFT 4

SnakeBody::SnakeBody(const unsigned int x, const unsigned int y, QGraphicsPixmapItem *parent)
    : QObject()
    , QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/snake.png"));
    setPos(x, y);
}

