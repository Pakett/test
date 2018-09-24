#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "vector2.h"

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    Vector2 current_speed;
    int idx;
public:
    Enemy(int);
    void collided();
    void update();
signals:
    void should_be_destoryed(int);
};

#endif // ENEMY_H
