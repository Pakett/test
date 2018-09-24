#include "platofrmspawner.h"
#include <QtMath>
#include <QDebug>
const int PLATFORMS_ON_ONE_SCREEN_BASE = 10;
const float CHANCE_OF_ENEMY = 0;

PlatofrmSpawner::PlatofrmSpawner(QGraphicsScene* scene, Score* score, QTimer* timer)
{
    this->scene = scene;
    begginingY = 450;
    spawnPlatforms(5);
    this->score = score;
    this->timer = timer;
}

void PlatofrmSpawner::collided()
{
    if(platforms[0]->getCurrentSpeedY() < 0)
    {
        for(int i = 0; i < platforms.size(); i++)
        {
            platforms[i]->collided();
        }
        for(int i = 0; i < enemys.size(); i++)
        {
            enemys[i]->collided();
        }
    }
}

void PlatofrmSpawner::stopAll()
{
    QObject::disconnect(timer, SIGNAL(timeout()), this, SLOT(update()));
}


void PlatofrmSpawner::spawnPlatforms(int count)
{
    int platfroms_count;
    qreal x = 50;
    if (count == - 1)
    {
        platfroms_count = 5 + qrand()%(PLATFORMS_ON_ONE_SCREEN_BASE - 5);
    }
    else
    {
        platfroms_count = count;
    }

    for(int i = 0; i < platfroms_count; i++)
    {
        Platform* plat = new Platform(x, begginingY, platforms.size());
        QObject::connect(plat, SIGNAL(should_be_destoryed(int)), this, SLOT(on_platform_destroy(int)));
        scene->addItem(plat);
        platforms.push_back(plat);
        begginingY -= 40 + qrand()%140;
        x = 10 + qrand()%200;
    }
}

void PlatofrmSpawner::spawnUpdate()
{
     qreal x = 50;
     x = 10 + qrand()%200;
     int platforms_count = 1;

     //begginingY -= -20 + qrand()%20;
     for(int i = 0; i < platforms_count; i++)
     {
         Platform* plat = new Platform(x, 100 + qrand()%50, platforms.size());
         QObject::connect(plat, SIGNAL(should_be_destoryed(int)), this, SLOT(on_platform_destroy(int)));
         scene->addItem(plat);
         platforms.push_back(plat);
     }
}

void PlatofrmSpawner::update()
{
    for(int i = 0; i < platforms.size(); i++)
    {
        platforms[i]->update();
    }
    for(int i = 0; i < enemys.size(); i++)
    {
        enemys[i]->update();
    }
    if(qrand()%100 <= CHANCE_OF_ENEMY)
    {
        Enemy * enem = new Enemy(enemys.size());
        QObject::connect(enem, SIGNAL(should_be_destoryed(int)), this, SLOT(on_enemy_destroy(int)));
        enemys.push_back(enem);
        scene->addItem(enem);
    }


}

void PlatofrmSpawner::on_platform_destroy(int idx)
{
    platforms[idx]->setPos(10 + qrand()%200, 0);
    score->increase();

}

void PlatofrmSpawner::on_enemy_destroy(int idx)
{
    scene->removeItem(enemys[idx]);
}
