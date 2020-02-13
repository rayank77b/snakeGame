#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>

#include "snake.h"

const int X_MAX = 1000;
const int Y_MAX = 800;

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    QGraphicsScene *scene;
    Snake *snake;
    QGraphicsTextItem *txtGameOver;
    QTimer *gameTimer;

    Game(QWidget * parent=0);

public slots:
    void snakeCollision();
};

#endif // GAME_H
