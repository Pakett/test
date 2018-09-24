#ifndef PLAYER_H
#define PLAYER_H

#include  <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>

#include "vector2.h"
#include "platofrmspawner.h"

class Player: public QObject, public QGraphicsPixmapItem
{
     Q_OBJECT
private:
    Vector2 current_speed;
    float player_speed;
    PlatofrmSpawner* spawner;
    QTimer * death_timer;
    bool dead;
public:

    QGraphicsRectItem* collider;
    Player(PlatofrmSpawner* spawner);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

public slots:
    void update();
    void on_death();
signals:
    void death();
};

#endif // PLAYER_H
