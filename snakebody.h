#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QList>

class SnakeBody : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    static const unsigned int snake_max_pix = 25;

    SnakeBody(const unsigned int x, const unsigned int y, QGraphicsPixmapItem *parent=0);

//public slots:
//    void move();
};


#endif // SNAKEBODY_H
