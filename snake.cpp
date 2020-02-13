#include "snake.h"
#include "game.h"

#define K_UP 1
#define K_DOWN 2
#define K_RIGHT 3
#define K_LEFT 4

Snake::Snake(QGraphicsPixmapItem *parent)
    : QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/snake.png"));
    moving = true;
    direction = K_LEFT;
}

void Snake::keyPressEvent(QKeyEvent *event)
{
    if ( event->key() == Qt::Key_Left ) {
        direction = K_LEFT;
    } else if ( event->key() == Qt::Key_Right ) {
        direction = K_RIGHT;
    } else if ( event->key() == Qt::Key_Up ) {
        direction = K_UP;
    } else if ( event->key() == Qt::Key_Down ) {
        direction = K_DOWN;
    } else if ( event->key() == Qt::Key_Space ) {
        moving = !moving;
    }
}

void Snake::move()
{
    if ( moving ) {
        if ( direction == K_LEFT ) {
            setPos(x()-50, y());
        } else if ( direction == K_RIGHT ) {
            setPos(x()+50, y());
        } else if ( direction == K_UP ) {
            setPos(x(), y()-50);
        } else {  // ( direction == K_DOWN )
            setPos(x(), y()+50);
        }
    }
    // test snake for border collision
    if ( moving ) {
        if ( (x()<0) || (x()>=X_MAX) || (y()<0) || (y()>=Y_MAX) ) {
             moving=false;
             emit collisionDetected();
        }
    }
}
