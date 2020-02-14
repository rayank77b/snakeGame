#ifndef APPLE_H
#define APPLE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QList>

class Apple : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    static const unsigned int apel_max_pix = 25;

    Apple(const unsigned int x, const unsigned int y, QGraphicsPixmapItem *parent=0);

};


#endif // APEL_H
