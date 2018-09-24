#include <QApplication>
#include "scenemanager.h"
#include "player.h"
#include "platofrmspawner.h"
#include "score.h"


#include <QGraphicsView>
#include <QObject>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SceneManager scene = SceneManager();
    Score* score = new Score();
    QTimer* updateTimer = new QTimer();

    PlatofrmSpawner* spawner = new PlatofrmSpawner(scene.getScene(), score, updateTimer);

    Player* player = new Player(spawner);
    player->setPos(100, 100);
    player->setPixmap(QPixmap(":/imgs/Doodler.png"));
    player->setFocus();
    scene.addItem(player);
    scene.addItem(player->collider);

    scene.addItem(score);

    QObject::connect(updateTimer, SIGNAL(timeout()), player, SLOT(update()));
    QObject::connect(updateTimer, SIGNAL(timeout()), spawner, SLOT(update()));

    QGraphicsView* view = new QGraphicsView(scene.getScene());
    view->show();
    updateTimer->start(15);
    return a.exec();
}
