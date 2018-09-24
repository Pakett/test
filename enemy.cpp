#include "enemy.h"

Enemy::Enemy(int idx)
{
    setPixmap(QPixmap(":/imgs/enemy.png"));
    setPos(10 + qrand()%220, 0);
    current_speed.x = 0;
    current_speed.y = -5;
    this->idx = idx;
}

void Enemy::collided()
{
    current_speed.y = 20;
}

void Enemy::update()
{
    setPos(x(), y() + current_speed.y);
    if (current_speed.y > -10)
    {
        current_speed.y -= 1;
    }

    if(pos().y() > 600)
    {
        emit(should_be_destoryed(idx));
    }
}
