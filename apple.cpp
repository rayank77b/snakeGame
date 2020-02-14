#include "apple.h"

Apple::Apple(const unsigned int x, const unsigned int y, QGraphicsPixmapItem *parent)
    : QObject()
    , QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/apple.png"));
    setPos(x, y);
}
