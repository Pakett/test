#ifndef PLATFORM_H
#define PLATFORM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "vector2.h"


class Platform: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:

    Vector2 current_speed;
    QGraphicsRectItem* player;
    int idx;

public:
    Platform(qreal x, qreal y, int idx);
    void collided();
    float getCurrentSpeedY();
    void setNewIdx(int);
public slots:
    void update();
signals:
    void should_be_destoryed(int);
};

#endif // PLATFORM_H
