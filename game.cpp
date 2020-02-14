#include "game.h"
#include <QDebug>
#include <QGraphicsTextItem>
#include <QFont>
#include <QRandomGenerator>

Game::Game(QWidget *parent)
{
    // create the scene
    scene = new QGraphicsScene();
    // make the scene 800x600 instead
    // of infinity by infinity (default)
    scene->setSceneRect(0,0,X_MAX,Y_MAX);

    // make the newly created scene the scene
    // to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(X_MAX,Y_MAX);

    // create the snake
    snake = new Snake(X_MAX/2,Y_MAX/2);
    // add the player to the scene
    scene->addItem(snake);
    // build snake body
    SnakeBody *sb = new SnakeBody(X_MAX/2+SnakeBody::snake_max_pix,Y_MAX/2);
    scene->addItem(sb);
    body.append(sb);
    sb = new SnakeBody(X_MAX/2+2*SnakeBody::snake_max_pix,Y_MAX/2);
    scene->addItem(sb);
    body.append(sb);
    sb = new SnakeBody(X_MAX/2+3*SnakeBody::snake_max_pix,Y_MAX/2);
    scene->addItem(sb);
    body.append(sb);
    sb = new SnakeBody(X_MAX/2+4*SnakeBody::snake_max_pix,Y_MAX/2);
    scene->addItem(sb);
    body.append(sb);

    snake->setBody(body);

    // generate Apple
    QRandomGenerator generator;
    unsigned int rx = static_cast<unsigned int>(generator.bounded(0,X_MAX/25));
    unsigned int ry = static_cast<unsigned int>(generator.bounded(0,Y_MAX/25));

    apple = new Apple(rx*25,ry*25);
    scene->addItem(apple);


    // set snake moving
    gameTimer = new QTimer();
    QObject::connect(gameTimer, SIGNAL(timeout()), snake, SLOT(move()));
    gameTimer->start(300);  // ms

    // Game Over Text
    txtGameOver = new QGraphicsTextItem("GAME OVER");
    txtGameOver->setDefaultTextColor(Qt::red);
    txtGameOver->setFont(QFont("times", 22));
    txtGameOver->setPos(400,400);

    QObject::connect(snake, SIGNAL(collisionDetected()), this, SLOT(snakeCollision()));

    show();
}

void Game::snakeCollision()
{
    scene->addItem(txtGameOver);
    gameTimer->stop();
}
