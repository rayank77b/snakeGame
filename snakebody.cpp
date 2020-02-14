#include "snakebody.h"

SnakeBody::SnakeBody(const unsigned int x, const unsigned int y, QGraphicsPixmapItem *parent)
    : QObject()
    , QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/snake.png"));
    setPos(x, y);
}

