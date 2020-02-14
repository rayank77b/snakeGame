#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QString>
#include <QFont>

class Score : public QGraphicsTextItem
{
    int score;
public:
    Score(QGraphicsItem * parent=0);
    void increase();
};

#endif // SCORE_H
