#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QFont>
#include <QRandomGenerator>

#include "snake.h"
#include "snakebody.h"
#include "apple.h"
#include "score.h"

const int X_MAX = 1000;
const int Y_MAX = 800;

class Game : public QGraphicsView
{
    Q_OBJECT
private:
    unsigned int snake_grow = 3;
    int game_period_ms = 250;
public:
    QGraphicsScene *scene;
    Snake *snake;
    Apple *apple;
    Score *score;

    QGraphicsTextItem *txtGameOver;
    QTimer *gameTimer;
    QRandomGenerator *generator;

    Game(QWidget * parent=0);

public slots:
    void snakeCollision();
    void appleEated();
};

#endif // GAME_H
