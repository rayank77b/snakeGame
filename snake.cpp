#include "snake.h"

#include <QDebug>
#include <iostream>
#include "game.h"
#include "apple.h"

#define K_UP 1
#define K_DOWN 2
#define K_RIGHT 3
#define K_LEFT 4

Snake::Snake(const unsigned int x, const unsigned int y, QGraphicsPixmapItem *parent)
    : QObject()
    , QGraphicsPixmapItem(parent)
    , begin_x{x}
    , begin_y{y}
{
    setPixmap(QPixmap(":/images/snake.png"));
    moving = true;
    direction = K_LEFT;
    setPos(x, y);
    // make the player focusable and set it to be the current focus
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void Snake::add(SnakeBody* b)
{
    body.append(b);
}

void Snake::keyPressEvent(QKeyEvent *event)
{
    if ( event->key() == Qt::Key_Left ) {
        if ( last_direction != K_RIGHT)
            direction = K_LEFT;
    } else if ( event->key() == Qt::Key_Right ) {
        if ( last_direction != K_LEFT)
            direction = K_RIGHT;
    } else if ( event->key() == Qt::Key_Up ) {
        if ( last_direction != K_DOWN)
            direction = K_UP;
    } else if ( event->key() == Qt::Key_Down ) {
        if ( last_direction != K_UP)
            direction = K_DOWN;
    } else if ( event->key() == Qt::Key_Space ) {
        moving = !moving;
    }
}

void Snake::move()
{
    if ( moving ) {

        // test for colliding of head to body or eat apple
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for( auto &el : colliding_items) {
            // colliding with body
            if ( typeid(*el) == typeid(SnakeBody))
            {
                moving=false;
                emit collisionDetected();
                return;
            }
            // snake eat apple
            if (typeid(*el) == typeid(Apple))
            {
                emit eatApple();

            }
        }



        last_x = x();
        last_y = y();
        last_direction = direction;
        // bewege den kopf
        if ( direction == K_LEFT ) {
            setPos(x()-snake_max_pix, y());
        } else if ( direction == K_RIGHT ) {
            setPos(x()+snake_max_pix, y());
        } else if ( direction == K_UP ) {
            setPos(x(), y()-snake_max_pix);
        } else {  // ( direction == K_DOWN )
            setPos(x(), y()+snake_max_pix);
        }
        // jetzt muessen wir den snake body auch bewegen.
        // wir nehmen den letzen und haengen in an letzten platz von kopf
        if ( !body.isEmpty() )
        {
            SnakeBody *blast = body.takeLast();
            blast->setX(last_x);
            blast->setY(last_y);
            body.prepend(blast);
        }

        // test snake for border collision
        if ( (x()<0) || (x()>=X_MAX) || (y()<0) || (y()>=Y_MAX) ) {
             moving=false;
             emit collisionDetected();
        }
    }
}
