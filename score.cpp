#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText(QString::number(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times", 16));
    setPos(140, 0);
}

void Score::increase()
{
    this->score += 1;
    setPlainText(QString::number(score));
}

int Score::getScore()
{
    return score;
}
