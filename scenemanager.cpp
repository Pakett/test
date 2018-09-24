#include "scenemanager.h"

SceneManager::SceneManager()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 300, 500);
}

void SceneManager::addItem(QGraphicsItem* item)
{
    scene->addItem(item);
}

QGraphicsScene* SceneManager::getScene()
{
    return scene;
}
