#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>

#include "snake.h"


class Game : public QGraphicsView
{
public:
    QGraphicsScene *scene;
    Snake *snake;

    Game(QWidget * parent=0);
};

#endif // GAME_H
