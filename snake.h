#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Snake : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    bool moving;
    int direction;
public:
    Snake(QGraphicsPixmapItem *parent=0);
    void keyPressEvent(QKeyEvent *event);

public slots:
    void move();
signals:
    void collisionDetected();
};

#endif // SNAKE_H
