#include "player.h"
#include <QDebug>
#include <QKeyEvent>
#include <QList>
#include "platform.h"
#include <QPainter>
#include "enemy.h"

Player::Player(PlatofrmSpawner* spawner)
{

    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    current_speed.x = 0;
    current_speed.y = 0;
    player_speed = 5;

    this->spawner = spawner;

    collider = new QGraphicsRectItem();
    collider->setRect(100, 145, 50, 5);
    collider->setOpacity(0);

    death_timer = new QTimer();
    QObject::connect(death_timer, SIGNAL(timeout()), this, SLOT(on_death()));
    dead = false;
}

void Player::keyPressEvent(QKeyEvent *event)
{
       if (event->key() == Qt::Key_Left)
       {
            current_speed.x = -player_speed;
       }
       else if (event->key() == Qt::Key_Right)
       {
            current_speed.x = player_speed;
       }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_Right)
    {
         current_speed.x = 0;
    }
}

void Player::update()
{
    if (scenePos().x() < 250 && current_speed.x > 0)
    {
        setPos(x() + qreal(current_speed.x), y() + current_speed.y);
        collider->setPos(collider->x() + qreal(current_speed.x), collider->y() + current_speed.y);
    }
    else if (scenePos().x() > 0 && current_speed.x < 0)
    {
        setPos(x() + qreal(current_speed.x), y() + current_speed.y);
        collider->setPos(collider->x() + qreal(current_speed.x), collider->y() + current_speed.y);
    }

    QList<QGraphicsItem*> colliding_items = collider->collidingItems();
    for(int i = 0; i < colliding_items.size(); i++)
    {
        if(typeid (* colliding_items[i]) == typeid(Platform))
        {
            death_timer->start(2000);
            spawner->collided();
            break;
        }
        else if (typeid (* colliding_items[i]) == typeid(Enemy))
        {
                this->on_death();
        }
    }
    if  (this->dead)
    {
        setRotation(rotation() + 10);
        setPos(x(), y() + 5);
    }
}

void Player::on_death()
{
    this->collider->scene()->removeItem(this->collider);
    this->spawner->stopAll();
    death_timer->stop();
    this->dead = true;
    this->setRotation(10);
    emit(death());
}
