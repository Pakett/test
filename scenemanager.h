#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QGraphicsScene>
#include <QGraphicsItem>

class SceneManager
{    
private:

    QGraphicsScene* scene;

public:
    SceneManager();
    void addItem(QGraphicsItem* item);
    QGraphicsScene*  getScene();
};

#endif // SCENEMANAGER_H
