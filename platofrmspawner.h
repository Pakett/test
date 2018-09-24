#ifndef PLATOFRMSPAWNER_H
#define PLATOFRMSPAWNER_H

#include <QObject>
#include <QList>
#include <QGraphicsScene>
#include <QTimer>
#include "platform.h"
#include "score.h"
#include "enemy.h"

class PlatofrmSpawner: public QObject
{
    Q_OBJECT
private:
    QList<Platform*> platforms;
    QGraphicsScene* scene;
    Score* score;
    qreal begginingY;
    QTimer* timer;
    QList<Enemy *> enemys;
    void spawnPlatforms(int);
    void spawnUpdate();
public:
    PlatofrmSpawner(QGraphicsScene* scene, Score* score, QTimer* timer);
    void collided();
    void stopAll();
public slots:
    void update();
    void on_platform_destroy(int);
    void on_enemy_destroy(int);
};

#endif // PLATOFRMSPAWNER_H
