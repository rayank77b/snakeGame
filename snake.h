#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QList>

#include "snakebody.h"

class Snake : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    bool moving;
    unsigned int direction;
    unsigned int last_direction;
    unsigned int begin_x;
    unsigned int begin_y;
    unsigned int snake_max_pix = 25;

    QList<SnakeBody*> body;

public:
    qreal last_x;
    qreal last_y;

public:
    Snake(const unsigned int x, const unsigned int y, QGraphicsPixmapItem *parent=0);
    void setBody(QList<SnakeBody*> &b);
    void keyPressEvent(QKeyEvent *event);

public slots:
    void move();
signals:
    void collisionDetected();
};

#endif // SNAKE_H
