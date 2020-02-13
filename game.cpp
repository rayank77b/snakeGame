#include "game.h"


Game::Game(QWidget *parent)
{
    // create the scene
    scene = new QGraphicsScene();
    // make the scene 800x600 instead
    // of infinity by infinity (default)
    scene->setSceneRect(0,0,1000,800);

    // make the newly created scene the scene
    // to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,800);

    // create the snake
    snake = new Snake();
    snake->setPos(500,400);
    // make the player focusable and set it to be the current focus
    snake->setFlag(QGraphicsItem::ItemIsFocusable);
    snake->setFocus();
    // add the player to the scene
    scene->addItem(snake);

    // set snake moving
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),
                     snake, SLOT(move()));
    timer->start(300);  // ms

    show();
}
