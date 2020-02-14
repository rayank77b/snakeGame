#include "game.h"
#include <QDebug>
#include <QGraphicsTextItem>
#include <QFont>
#include <time.h>

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

    // generate Apple
    generator = new QRandomGenerator();
    generator->seed(time(NULL));
    unsigned int rx = static_cast<unsigned int>(25*generator->bounded(0,X_MAX/25));
    unsigned int ry = static_cast<unsigned int>(25*generator->bounded(0,Y_MAX/25));
    apple = new Apple(rx,ry);
    scene->addItem(apple);

    // create the snake
    snake = new Snake(X_MAX/2,Y_MAX/2);
    // add the player to the scene
    scene->addItem(snake);
    // build snake body
    SnakeBody *sb = new SnakeBody(X_MAX/2+SnakeBody::snake_max_pix,Y_MAX/2);
    scene->addItem(sb);
    snake->add(sb);
    sb = new SnakeBody(X_MAX/2+2*SnakeBody::snake_max_pix,Y_MAX/2);
    scene->addItem(sb);
    snake->add(sb);
    sb = new SnakeBody(X_MAX/2+3*SnakeBody::snake_max_pix,Y_MAX/2);
    scene->addItem(sb);
    snake->add(sb);

    // create the score
    score = new Score();
    scene->addItem(score);

    // set snake moving
    gameTimer = new QTimer();
    QObject::connect(gameTimer, SIGNAL(timeout()), snake, SLOT(move()));
    gameTimer->start(game_period_ms);  // ms

    // Game Over Text
    txtGameOver = new QGraphicsTextItem("GAME OVER");
    txtGameOver->setDefaultTextColor(Qt::red);
    txtGameOver->setFont(QFont("times", 22));
    txtGameOver->setPos(400,400);

    QObject::connect(snake, SIGNAL(collisionDetected()), this, SLOT(snakeCollision()));
    QObject::connect(snake, SIGNAL(eatApple()), this, SLOT(appleEated()));

    show();
}

void Game::snakeCollision()
{
    scene->addItem(txtGameOver);
    gameTimer->stop();
}

void Game::appleEated()
{
    unsigned int rx;
    unsigned int ry;
    bool apple_colliding = false;

    score->increase();

    do
    {
        apple_colliding = false;
        rx = static_cast<unsigned int>(25*generator->bounded(0,X_MAX/25));
        ry = static_cast<unsigned int>(25*generator->bounded(0,Y_MAX/25));
        apple->setX(rx);
        apple->setY(ry);

        QList<QGraphicsItem *> colliding_items = apple->collidingItems();
        for( auto &el : colliding_items) {
            // colliding with body
            if ( (typeid(*el) == typeid(SnakeBody)) || (typeid(*el) == typeid(Snake)) )
            {
                apple_colliding = true;
            }
        }
    } while(apple_colliding);

    SnakeBody *sb;
    for (unsigned int i=0; i<snake_grow; i++)
    {
        sb = new SnakeBody(snake->last_x, snake->last_y);
        scene->addItem(sb);
        snake->add(sb);
    }
    snake_grow = snake_grow + 3;
    game_period_ms = game_period_ms - 3;
    gameTimer->setInterval(game_period_ms);
}
