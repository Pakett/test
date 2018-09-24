#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{
private:
    int score;
public:
    int getScore();
    void increase();
    Score(QGraphicsItem * parent = 0);
};

#endif // SCORE_H
